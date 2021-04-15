#ifndef DE_UNISTUTTGART_FRAMEWORK_GAMEABORTEDEXCEPTION_H
#define DE_UNISTUTTGART_FRAMEWORK_GAMEABORTEDEXCEPTION_H

#include <string>
#include <exception>

namespace framework {

class GameAbortedException : public std::exception {
public:
    GameAbortedException(std::string message)
            : message(message) {
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_GAMEABORTEDEXCEPTION_H
