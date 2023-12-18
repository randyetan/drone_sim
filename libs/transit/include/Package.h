#ifndef PACKAGE_H
#define PACKAGE_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

class Robot;

class Package : public IEntity {
 public:
  /**
   * @brief Constructor
   * @param obj JSON object containing the package's information
   */
  Package(JsonObject& obj);

  /**
   * @brief Gets the Package's destination
   * @return The Package's destination
   */
  Vector3 getDestination() const;

  /**
   * @brief Returns the name of the strategy for this package
   * 
   * @returns String name of strategy
  */
  std::string getStrategyName() const;

  /**
  * @brief Returns the delivery method name
  * @returns String name of the delivery method
  */
  std::string getMethodName() const;

  /**
  * @brief Returns the robot 'owner' pointer
  * @returns Robot pointer of the private variable owner
  */
  Robot* getRobot();

  /**
   * @brief Set the Strategy Name
   *
   * @param strategyName_ Strategy name
   */
  void setStrategyName(std::string strategyName_);

  /*TODO Codestyling/Doxygen*/
  void setMethodName(std::string methodName_);

  /**
   * @brief Updates the Package
   * 
   * @param dt difference in time since last update
  */
  void update(double dt);

  /**
   * @brief Sets the attributes for delivery
   * 
   * @param owner Robot for the package to be delivered to
  */
  void initDelivery(Robot* owner);

  /**
   * @brief Gives the robot/owner this package
  */
  void handOff();

  bool requiresDelivery = true;

 private:
  Vector3 destination;
  std::string strategyName;
  std::string methodName;
  Robot* owner = nullptr;
};

#endif  // PACKAGE_H
