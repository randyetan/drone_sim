#include "Package.h"

#include "Robot.h"

Package::Package(JsonObject &obj) : IEntity(obj) {
}

Vector3 Package::getDestination() const {
  return destination;
}

std::string Package::getMethodName() const {
  return methodName;
}

std::string Package::getStrategyName() const {
  return strategyName;
}

Robot* Package::getRobot() {
  return owner;
}

void Package::setStrategyName(std::string strategyName_) {
  strategyName = strategyName_;
}

void Package::setMethodName(std::string methodName_) {
  methodName = methodName_;
}

void Package::update(double dt) {}

void Package::initDelivery(Robot* owner) {
  this->owner = owner;
  owner->requestedDelivery = false;
  requiresDelivery = false;
  destination = owner->getPosition();
}

void Package::handOff() {
  if (owner) {
    owner->receive(this);
  }
}
