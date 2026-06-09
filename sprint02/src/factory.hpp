#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "system.hpp"
#include "model.hpp"

/****************** Factory ******************/
System* createSystem(double value = 0.0);
Model* createModel();

#endif // FACTORY_HPP