#include "ChargerFactory.h"

IEntity* ChargerFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("charger") == 0) {
    std::cout << "Recharge Station Created" << std::endl;
    return new RechargeStation(entity);
  }
  return nullptr;
}
