#include "Greeter.hpp"
#include <iostream>

Greeter::Greeter(const std::string& name) : name(name) {}

void Greeter::sayHello() const {
    std::cout << "Hello, " << name << "!" << std::endl;
}
