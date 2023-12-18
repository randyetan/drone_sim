#ifndef IPKGDECORATOR_H_
#define IPKGDECORATOR_H_

#include "IEntity.h"
#include "Drone.h"
#include "Package.h"
#include "Robot.h"

class Drone;

/**
* @brief This class is a decorator class that will wrap a package and adjust 
* the speed and price of delivery based on what kind of delivery method was changes
*/
class IPkgDecorator {
 protected:
    double moneyMultiplier = 0;
    double maxRefundPercent = 0.0;
    double timeMultiplier = 0;
    float droneSpeed = 0;

 public:
    /**
    * @brief An IPkgDecorator is created, sets pkg and drone values to params
    * @param pkg Package pointer containing package that is wrapped by this
    * @param drone Drone pointer that is set to carry the package wrapped.
    */
    IPkgDecorator(Package* pkg, Drone* drone);


    /**
    * @brief IPkgDecorator destructor
    */
    virtual ~IPkgDecorator();


    /**
    * @brief Calculates the price needed to deliver the package to the robot
    * @return true if the robot has enough money to pay for delivery, false if not
    */
    bool calculatePrice();

    /**
    * @brief Sends money between two entities
    * @param giver IEntity object that will be giving money to reciever
    * @param receiver IEntity object that will be receiving money from giver
    * @param exchangeVal Float that represents the amount of money being sent
    */
    void sendMoney(IEntity* giver, IEntity* receiver, float exchangeVal);


    /**
    * @brief Determines whether or not drone needs to refun robot for long trip
    */
    void needRefund();


    /**
    * @brief Updates the amount of time it has taken for the drone to take trip
    * @param dt double that represents change in time
    */
    void updateTime(double dt);

 private:
    Package* pkg = nullptr;
    Drone* drone = nullptr;
    double maximumtime = 0;
    float moneyOwed = 0.0;
    double timeTaken = 0;
};

#endif
