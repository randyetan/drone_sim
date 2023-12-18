#include "NormalDecorator.h"

NormalDecorator::NormalDecorator(Package* pkg, Drone* drone)
: IPkgDecorator(pkg, drone) {
  droneSpeed = 21;
  drone->setSpeed(droneSpeed);
  this->moneyMultiplier = 0.0075;
  this->timeMultiplier = .15;
  this->maxRefundPercent = 0.75;
}
