#include "TestUtils.h"

#include "CollectionHelpers.hpp"
#include "gtest/gtest.h"

#include <regex>

namespace util {

template<typename T>
static std::string internalJoin(const std::string& separator, const T& strings) {
    std::string result;
    for (int i = 0; i < strings.size(); ++i) {
        if (i > 0) {
            result += separator;
        }
        result += collectionhelpers::get_at(strings, i).value();
    }
    return result;
}

std::string TestUtils::join(const std::string& separator, const std::vector<std::string>& strings) {
    return internalJoin(separator, strings);
}
std::string TestUtils::join(const std::string& separator, const std::list<std::string>& strings) {
    return internalJoin(separator, strings);
}

void TestUtils::assertThrows(const std::type_info& exceptionType, std::function<void()> lambda) {
    try {
        lambda();
        FAIL();
    } catch (const std::exception& e) {
        if (typeid(e) != exceptionType) {
            FAIL();
        }
    }
}

std::vector<std::string> TestUtils::split(const std::string& separator, const std::string& string) {
    std::vector<std::string> result;
    size_t start;
    size_t end = 0;

    while ((start = string.find_first_not_of(separator, end)) != std::string::npos) {
        end = string.find(separator, start);
        auto nextPart = string.substr(start, end - start);
        result.push_back(nextPart);
    }
    return result;
}

std::string TestUtils::replaceAll(const std::string& input, const std::string& from, const std::string& to) {
    return std::regex_replace(input, std::regex(from), to);
}

}
