#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_SHAREDPOINTEROBJECTLISTVIEW_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_SHAREDPOINTEROBJECTLISTVIEW_H

#include <memory>
#include <algorithm>
#include <iterator>
#include <list>
#include "ObjectListView.hpp"
#include "SharedPointerObjectIteratorWrapper.hpp"

namespace framework {

/// \brief Wrapper around an ObjectListView which allows to iterate over the objects with shared-pointers
template<typename T, bool constType>
class SharedPointerObjectListView {
public:

    using value_type = std::shared_ptr<T>;
    using ObjectListView = ObjectListView<T, constType>;

    static constexpr bool useConstTrue = true;
    static constexpr bool useConstFalse = false;

    using iterator = SharedPointerObjectIteratorWrapper<T, useConstFalse>;
    using const_iterator = SharedPointerObjectIteratorWrapper<T, useConstTrue>;

private:

    ObjectListView& wrappedObjectView;

public:

    explicit SharedPointerObjectListView(ObjectListView& wrappedObjectView)
            : wrappedObjectView(wrappedObjectView) {
    }

    ~SharedPointerObjectListView() = default;

    iterator begin() {
        return wrappedObjectView.
    }

    iterator end() = 0;

    const_iterator begin() const {
        return cbegin();
    }

    const_iterator end() const {
        return cend();
    }

    const_iterator cbegin() const = 0;
    const_iterator cend() const = 0;

    bool empty() const = 0;

    size_t size() const = 0;
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_SHAREDPOINTEROBJECTLISTVIEW_H
