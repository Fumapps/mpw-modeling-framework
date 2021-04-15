#ifndef DE_UNISTUTTGART_FRAMEWORK_SHAREDPOINTEROBJECTITERATORWRAPPER_H
#define DE_UNISTUTTGART_FRAMEWORK_SHAREDPOINTEROBJECTITERATORWRAPPER_H

#include <algorithm>
#include <list>
#include <functional>
#include <utility>
#include <memory>
#include <iterator>
#include "ObjectIterator.hpp"

namespace framework {

template<typename T, bool constType>
class SharedPointerObjectIteratorWrapper {
public:
    using WrappedObjectIterator = ObjectIterator<T, constType>;

private:
    WrappedObjectIterator objectIterator;

public:

    using self_type = ObjectIterator;
    using value_type = ObjectReturnType;
    using iterator_category = typename std::forward_iterator_tag;
    using difference_type = int;

    explicit SharedPointerObjectIteratorWrapper(WrappedObjectIterator objectIterator)
            : objectIterator(objectIterator) {
    }

    SharedPointerObjectIteratorWrapper(const SharedPointerObjectIteratorWrapper& rhs)
            : objectIterator(rhs.objectIterator) {
    }

    self_type operator++() {
        self_type i = *this;
        internalIterator->next();
        return i;
    }

    std::shared_ptr<WrappedObjectIterator::ObjectReturnType> operator*() {
        return objectIterator->shared_from_this();
    }

    std::shared_ptr<WrappedObjectIterator::ObjectReturnType> operator->() {
        return objectIterator->shared_from_this();
    }

    bool operator==(const self_type& rhs) {
        return objectIterator == rhs.objectIterator;
    }

    bool operator!=(const self_type& rhs) {
        return objectIterator != rhs.objectIterator;
    }
};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_SHAREDPOINTEROBJECTITERATORWRAPPER_H
