#include "IPkgDecorator.h"

IPkgDecorator::IPkgDecorator(Package* pkg, Drone* drone) {
  this->pkg = pkg;
  // this->time = time; this line and any time refrences dont work anymore
  this->drone = drone;
}

IPkgDecorator::~IPkgDecorator() {}

bool IPkgDecorator::calculatePrice() {
  double distance = pkg->getPosition().dist(pkg->getDestination());
  moneyOwed = static_cast<float>(distance * moneyMultiplier);
  if (moneyOwed > pkg->getRobot()->getMoney()) {
    return false;
  }
  maximumtime = distance * timeMultiplier;
  this->sendMoney(pkg->getRobot(), drone, moneyOwed);
  return true;
}

void IPkgDecorator::sendMoney(IEntity* giver,
IEntity* receiver, float exchangeVal) {
  // if (giver->getMoney < exchangeVal) {
  //   return false;
  // }
  if (giver && receiver) {
    giver->setMoney(giver->getMoney() - exchangeVal);
    receiver->setMoney(receiver->getMoney() + exchangeVal);
    std::cout << giver->getName() << " has given " << receiver->getName()
    << " $" << std::fixed << std::setprecision(2)
    << exchangeVal << "." << std::endl;
    // return true;
  } else if (giver) {
    std::cout << "There is no receiver." << std::endl;
    // return false;
  } else {
    std::cout << "There is no giver." << std::endl;
    // return false;
  }
}

void IPkgDecorator::needRefund() {
  if (timeTaken > maximumtime) {
    float retDollar = moneyOwed * std::min((timeTaken - maximumtime)
    / 5, maxRefundPercent);
    std::cout << "Package was not delivered in promised time: $"
    << retDollar <<  " returned" << std::endl;
    this->sendMoney(drone, pkg->getRobot(), retDollar);
    } else {
    std::setprecision(4);
    std::cout << "Package was delivered in promised time "
    << maximumtime << "!" << std::endl;
    if (drone->getMoney() >= 100) {
      std::setprecision(5);
    }
    std::cout << "Drone balance: $" << std::fixed
    << std::setprecision(2) << drone->getMoney() << std::endl;
  }
}

void IPkgDecorator::updateTime(double dt) {
  timeTaken += dt;
}
