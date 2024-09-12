#include "Battery.h"

#include <cfloat>

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "BfsStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "Package.h"
#include "SimulationModel.h"

Battery::Battery(Drone* dr, JsonObject& obj) : IEntity(obj) { drone = dr; }

void Battery::update(double dt) {
  std::cout << " battery percent: " << percentage << std::endl;
  Vector3 premove = position;
  if (drone->getModel() == nullptr) {
    SimulationModel* model2 = this->model;
    drone->linkModel(model2);
  }
  drone->update(dt);
  copyDetails();
  Vector3 postmove = position;
  if (!drone->getCharging()) {
    changePercentage((speed * dt) * -0.0005 + (premove.dist(postmove) * -0.01));
  } else {
    changePercentage(dt * 0.3);
    if (percentage >= 100.0) {
      drone->setCharging(false);
    }
  }
  if (needCharge()) {
    drone->setGoCharge(true);
  }
}

void Battery::copyDetails() {
  this->details = drone->getDetails();
  this->position = drone->getPosition();
  this->direction = drone->getDirection();
  this->speed = drone->getSpeed();
}

void Battery::changePercentage(float percent) { percentage += percent; }

bool Battery::needCharge() {
  double distance = 0;
  Package* pack = drone->getPackage();
  Vector3 endPos = position;
  if (pack != nullptr) {
    Vector3 packagePos = pack->getPosition();
    distance += packagePos.dist(position);
    Vector3 robotPos = pack->getDestination();
    distance += robotPos.dist(packagePos);
    endPos = robotPos;
  }
  IEntity* station = findClosestStation(endPos);
  Vector3 stationPos = station->getPosition();
  Vector3 up(0, 30, 0);
  if (!drone->getGoCharge()) {
    drone->setToCharger(new BeelineStrategy(position, stationPos + up));
  }
  distance += endPos.dist(stationPos);
  return (percentage < (distance * 0.01) + 5.0);
}

IEntity* Battery::findClosestStation(Vector3 vec) {
  IEntity* closest;
  double closestDist = DBL_MAX;
  for (int i = 0; i < chargers.size(); i++) {
    if (closestDist > position.dist(chargers[i]->getPosition())) {
      closestDist = position.dist(chargers[i]->getPosition());
      closest = chargers[i];
    }
  }
  return closest;
}
