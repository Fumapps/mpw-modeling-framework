
#ifndef DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTLISTPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTLISTPROPERTY_H

#include <algorithm>
#include <list>
#include <functional>
#include <memory>
#include "ObservableListProperty.hpp"
#include "ObjectListView.hpp"
#include "iterators/ObjectIterator.hpp"

namespace framework {

template<typename T>
class ObservableObjectListProperty : public ObservableListProperty<T>, public ObjectListView<T> {

protected:

    std::list<std::reference_wrapper<T>> references{};

public:

    static constexpr bool useConstTrue = true;
    static constexpr bool useConstFalse = false;

    using size_type = size_t;
    using iterator = ObjectIterator<T, useConstFalse>;
    using const_iterator = ObjectIterator<T, useConstTrue>;

    const std::list<std::reference_wrapper<T>>& getReferences() const {
        return references;
    }

    std::shared_ptr<T> front() override {
        if (references.size() > 0) {
            return references.front().get().shared_from_this();
        }
        return nullptr;
    }

    std::shared_ptr<const T> front() const override {
        if (references.size() > 0) {
            return references.front().get().shared_from_this();
        }
        return nullptr;
    }

    std::shared_ptr<T> back() override {
        if (references.size() > 0) {
            return references.back().get().shared_from_this();
        }
        return nullptr;
    }

    std::shared_ptr<const T> back() const override {
        if (references.size() > 0) {
            return references.back().get().shared_from_this();
        }
        return nullptr;
    }

    bool empty() const override {
        return references.empty();
    }

    size_t size() const override {
        return references.size();
    }

    bool contains(std::shared_ptr<T> element) const override {
        for (auto& current : references) {
            if (&current.get() == element.get()) {
                return true;
            }
        }
        return false;
    }

    void forEach(std::function<void(const T&)> consumer) const override {
        std::for_each(references.cbegin(), references.cend(), consumer);
    }
};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTLISTPROPERTY_H
