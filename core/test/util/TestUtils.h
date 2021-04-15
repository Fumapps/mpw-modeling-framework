#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_TESTUTILS_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_TESTUTILS_H

#include <string>
#include <vector>
#include <list>
#include <functional>

namespace util {

class TestUtils {
public:

    TestUtils() = delete;

    static std::string join(const std::string& separator, const std::vector<std::string>& strings);
    static std::string join(const std::string& separator, const std::list<std::string>& strings);
    static std::vector<std::string> split(const std::string& separator, const std::string& string);
    static std::string replaceAll(const std::string& input, const std::string& from, const std::string& to);

    static void assertThrows(const std::type_info& exceptionType, std::function<void()> lambda);

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_TESTUTILS_H
