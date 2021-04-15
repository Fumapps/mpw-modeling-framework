#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_ANY_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_ANY_H

#include <variant>
#include <string>

using RawReference = void*;
using EntityReference = RawReference;
using ValueReference = RawReference;
using Any = std::variant<
        int,
        float,
        bool,
        std::string,
        RawReference>;

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_ANY_H
