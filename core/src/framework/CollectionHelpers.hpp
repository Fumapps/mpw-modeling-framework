#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_COLLECTION_HELPERS_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_COLLECTION_HELPERS_H

#include <list>
#include <vector>
#include <memory>
#include <optional>
#include "ObjectListView.hpp"

namespace collectionhelpers {
template<typename T>
std::optional<std::shared_ptr<T>> get_at(framework::ObjectListView<T>& list, size_t index) {
    if (index >= 0 && index < list.size()) {
        auto iter = list.begin();
        std::advance(iter, index);
        return (*iter).shared_from_this();
    }
    return std::nullopt;
}

template<typename T>
std::optional<std::shared_ptr<const T>> get_at(const framework::ObjectListView<T>& list, size_t index) {
    if (index >= 0 && index < list.size()) {
        auto iter = list.cbegin();
        std::advance(iter, index);
        return (*iter).shared_from_this();
    }
    return std::nullopt;
}

template<typename T>
std::optional<T> get_at(const std::list<T>& list, size_t index) {
    if (index >= 0 && index < list.size()) {
        auto iter = list.begin();
        std::advance(iter, index);
        return *iter;
    }
    return std::nullopt;
}

template<typename T>
std::optional<T> get_at(const std::vector<T>& list, size_t index) {
    if (index >= 0 && index < list.size()) {
        return list[index];
    }
    return std::nullopt;
}

template<typename TGT, typename SRC>
std::list<std::shared_ptr<TGT>> type_select(const std::list<std::shared_ptr<SRC>>& list) {
    std::list<std::shared_ptr<TGT>> result;
    for (auto element : list) {
        auto targetElement = std::dynamic_pointer_cast<TGT>(element);
        if (targetElement != nullptr) {
            result.push_back(targetElement);
        }
    }
    return result;
}

template<typename TGT, typename SRC>
std::list<std::shared_ptr<const TGT>> type_select(const framework::ObjectListView<SRC>& list) {
    return type_select<const TGT, const SRC>(list.sharedPointerView());
}

template<typename TGT, typename SRC>
std::list<std::shared_ptr<TGT>> type_select(framework::ObjectListView<SRC>& list) {
    return type_select<TGT, SRC>(list.sharedPointerView());
}

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_COLLECTION_HELPERS_H
