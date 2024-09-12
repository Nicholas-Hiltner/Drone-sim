#include "RechargeStation.h"

RechargeStation::RechargeStation(JsonObject& obj) : IEntity(obj) {
  inUse = false;
}

void RechargeStation::update(double dt) {}
