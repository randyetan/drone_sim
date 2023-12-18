#ifndef NORMAL_DECORATOR_H_
#define NORMAL_DECORATOR_H_

#include "IPkgDecorator.h"
/**
 * @brief this class inhertis from the IPkgDecorator class and is represents
 * a package decorator where the entity will adjust speeds and prices according to it.
 */
class NormalDecorator : public IPkgDecorator {
 public:
  /**
   * @brief Construct a new Normal Decorator object
   *
   * @param pkg The package that is being wrapped in this
   *
   * @param drone The drone that is delivering the package pkg
   */
  NormalDecorator(Package* pkg, Drone* drone);
};

#endif  // NORMAL_DECORATOR_H_
