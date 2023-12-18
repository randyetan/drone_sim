#include "FastDecorator.h"

FastDecorator::FastDecorator(Package* pkg, Drone* drone)
: IPkgDecorator(pkg, drone) {
  droneSpeed = 30;
  drone->setSpeed(droneSpeed);
  this->moneyMultiplier = 0.015;
  this->timeMultiplier = 0.075;
  this->maxRefundPercent = 0.5;
}
