#ifndef CHARGER_FACTORY_H_
#define CHARGER_FACTORY_H_

#include "IEntityFactory.h"
#include "RechargeStation.h"

/**
 *@brief Charger Factory to produce RechargeStations class.
 **/
class ChargerFactory : public IEntityFactory {
 public:
  virtual ~ChargerFactory() {}
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
