#ifndef BATTERY_H_
#define BATTERY_H_

#include "Drone.h"

/**
 * @class Battery
 * @brief Represents a drone with a battery in a physical system. Drones move
 * using euler integration based on a specified velocity and direction.
 */
class Battery : public IEntity {
 public:
  /**
   * @brief Update function of battery, drains percentage based on dt
   *
   * @param dt Time
   **/
  void update(double dt);

  /**
   * @brief Additional Battery constructor
   *
   * @param dr Drone pointer
   * @param obj JSON object containing the Battery drone's information
   **/
  Battery(Drone* dr, JsonObject& obj);

  /**
   * @brief Gets the next delivery within the drone
   *
   **/
  void getNextDelivery() { drone->getNextDelivery(); }

  /**
   * @brief Copies details into Battery from Drone
   *
   **/
  void copyDetails();

  /**
   * @brief Changes internal percentage
   *
   * @param percent Changes internal percentage by this much
   **/
  void changePercentage(float percent);

  /**
   * @brief Returns boolean of if the Battery needs immediate charging
   *
   **/
  bool needCharge();

  /**
   * @brief Returns the closest ChargingStation to this Battery
   *
   **/
  IEntity* findClosestStation(Vector3);

 protected:
  Drone* drone;
  float percentage = 100;
};

#endif
