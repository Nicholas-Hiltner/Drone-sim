#include "DroneFactory.h"

#include "Battery.h"

IEntity* DroneFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("drone") == 0) {
    std::cout << "Drone Created" << std::endl;
    Drone* dr = new Drone(entity);
    Battery* batt = new Battery(dr, entity);
    return batt;
  }
  return nullptr;
}
