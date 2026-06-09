#include "factory.hpp"
#include "systemImpl.hpp"
#include "modelImpl.hpp"

System* createSystem(double value) {
    return new SystemImpl(value);
}

Model* createModel() {
    return new ModelImpl();
}