#include "FrameworkAssert.h"

#include <string>
#include "AssertionFailedException.h"

namespace framework {

void assertCondition(bool condition, const std::string& message) {
    if (!condition) {
        throw AssertionFailedException(message);
    }
}

void assertAttributeCondition(const std::string& condition, bool valid) {
    assertCondition(valid, "Attribute condition is not valid: " + condition);
}

void assertInstanceNotNull(const std::string& instanceName, EntityReference instance) {
    assertCondition(instance != nullptr, "Instance must not be null: " + instanceName);
}

void assertObjectFound(const std::string& referenceName, const std::string& objectTypeName,
                       EntityReference instance) {
    assertCondition(instance != nullptr,
                    "Object of type '" + objectTypeName + "' for reference '" + referenceName + "' not found");
}

void checkState(bool check) {
    if (!check) {
        throw AssertionFailedException();
    }
}

void checkState(bool check, const std::string& message) {
    if (!check) {
        throw AssertionFailedException(message);
    }
}

}
