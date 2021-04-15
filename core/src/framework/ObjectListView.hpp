#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_OBJECTLISTVIEW_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_OBJECTLISTVIEW_H

#include <memory>
#include <algorithm>
#include <iterator>
#include <list>
#include "iterators/ObjectIterator.hpp"

namespace framework {

/// \brief Defines a convenience view on a collection, which internally holds shared-pointers or weak-pointers of objects.
/// It uses a custom iterator type which allows to traverse over the entities as references.
///
/// \note The primary use case is to avoid copying a collection of weak-pointers, by defining this
/// view to allow traversing elements as shared-pointers.
template<typename T>
class ObjectListView {
public:

    using value_type = T;

    static constexpr bool useConstTrue = true;
    static constexpr bool useConstFalse = false;

    using iterator = ObjectIterator<T, useConstFalse>;
    using const_iterator = ObjectIterator<T, useConstTrue>;

public:

    virtual ~ObjectListView() = default;

    virtual iterator begin() = 0;
    virtual iterator end() = 0;

    const_iterator begin() const {
        return cbegin();
    }

    const_iterator end() const {
        return cend();
    }

    virtual const_iterator cbegin() const = 0;
    virtual const_iterator cend() const = 0;

    virtual iterator rbegin() = 0;
    virtual iterator rend() = 0;

    virtual bool empty() const = 0;

    virtual size_t size() const = 0;

    virtual bool contains(std::shared_ptr<T> element) const = 0;

    std::list<std::shared_ptr<T>> sharedPointerView() {
        std::list<std::shared_ptr<T>> result;
        for (auto& element : *this) {
            result.push_back(element.shared_from_this());
        }
        return result;
    }

    std::list<std::shared_ptr<const T>> sharedPointerView() const {
        std::list<std::shared_ptr<const T>> result;
        for (auto& element : *this) {
            result.push_back(element.shared_from_this());
        }
        return result;
    }

    virtual std::shared_ptr<T> front() = 0;
    virtual std::shared_ptr<const T> front() const = 0;

    virtual std::shared_ptr<T> back() = 0;
    virtual std::shared_ptr<const T> back() const = 0;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_OBJECTLISTVIEW_H
