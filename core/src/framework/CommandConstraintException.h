
#ifndef DE_UNISTUTTGART_FRAMEWORK_COMMANDCONSTRAINTEXCEPTION_H
#define DE_UNISTUTTGART_FRAMEWORK_COMMANDCONSTRAINTEXCEPTION_H

#include <string>
#include <exception>

namespace framework {

class CommandConstraintException : public std::exception {
public:
    CommandConstraintException(std::string message)
            : message(message) {
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_COMMANDCONSTRAINTEXCEPTION_H
