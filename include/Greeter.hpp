#ifndef GREETER_HPP
#define GREETER_HPP

#include <string>

class Greeter {
public:
    Greeter(const std::string& name);
    void sayHello() const;

private:
    std::string name;
};

#endif
