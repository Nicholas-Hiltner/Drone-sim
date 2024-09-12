#ifndef RECHARGE_STATION_H_
#define RECHARGE_STATION_H_

#include "IEntity.h"

/**
 *@brief RechargeStation where Drones with Batteries recharge.
 **/
class RechargeStation : public IEntity {
 public:
  /**
   * @brief Creates a RechargeStation
   *
   * @param obj JSON object containing the RechargeStation's information
   **/
  RechargeStation(JsonObject& obj);
  /**
   * @brief Updates the ChargingStation, function present for inheritance. Does nothing.
   * @param dt Delta time
   */
  void update(double dt);

 protected:
  bool inUse;
};

#endif
