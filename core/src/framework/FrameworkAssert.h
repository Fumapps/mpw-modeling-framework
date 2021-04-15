#ifndef DE_UNISTUTTGART_FRAMEWORK_FRAMEWORKASSERT_H
#define DE_UNISTUTTGART_FRAMEWORK_FRAMEWORKASSERT_H

#include <string>

#include "Any.h"

namespace framework {

void assertCondition(bool condition, const std::string& message);

void assertAttributeCondition(const std::string& condition, bool valid);

void assertInstanceNotNull(const std::string& instanceName, EntityReference instance);

void assertObjectFound(const std::string& referenceName, const std::string& objectTypeName, EntityReference instance);

void checkState(bool check);

void checkState(bool check, const std::string& message);

}

#endif //DE_UNISTUTTGART_FRAMEWORK_FRAMEWORKASSERT_H
