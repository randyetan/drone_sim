#include "PremiumDecorator.h"

PremiumDecorator::PremiumDecorator(Package* pkg, Drone* drone)
: IPkgDecorator(pkg, drone) {
  droneSpeed = 45;
  drone->setSpeed(droneSpeed);
  this->moneyMultiplier = 0.0225;
  this->timeMultiplier = .05;
  this->maxRefundPercent = 0.25;
}
