#ifndef DE_UNISTUTTGART_FRAMEWORK_SIMPLEOBJECTREFERENCELISTPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_SIMPLEOBJECTREFERENCELISTPROPERTY_H

#include <algorithm>
#include <list>
#include <memory>
#include <functional>
#include "ObjectListView.hpp"
#include "iterators/ObjectIterator.hpp"
#include "iterators/WeakPointerListIterator.hpp"

namespace framework {

template<typename T>
class SimpleObjectReferenceListProperty final : public ObjectListView<T> {
    static constexpr bool useConstTrue = true;
    static constexpr bool useConstFalse = false;

    using iterator = ObjectIterator<T, useConstFalse>;
    using const_iterator = ObjectIterator<T, useConstTrue>;

private:

    std::list<std::weak_ptr<T>> elements;

public:

    using ListIteratorNonConst = WeakPointerListIterator<T, decltype(elements.begin()), useConstFalse>;
    using ListIteratorConst = WeakPointerListIterator<T, decltype(elements.cbegin()), useConstTrue>;
    using ListIteratorReverseNonConst = WeakPointerListIterator<T, decltype(elements.rbegin()), useConstFalse>;

    using size_type = size_t;

    std::list<std::weak_ptr<T>>& get() {
        return elements;
    }

    const std::list<std::weak_ptr<T>>& get() const {
        return elements;
    }

    bool empty() const override {
        return elements.empty();
    }

    size_t size() const override {
        return elements.size();
    }

    bool contains(std::shared_ptr<T> element) const override {
        for (auto& current : elements) {
            if (current.lock() == element) {
                return true;
            }
        }
        return false;
    }

    std::shared_ptr<T> front() override {
        if (elements.empty()) {
            return {};
        }
        return elements.front().lock();
    }

    std::shared_ptr<const T> front() const override {
        if (elements.empty()) {
            return {};
        }
        return elements.front().lock();
    }

    std::shared_ptr<T> back() override {
        if (elements.empty()) {
            return {};
        }
        return elements.back().lock();
    }

    std::shared_ptr<const T> back() const override {
        if (elements.empty()) {
            return {};
        }
        return elements.back().lock();
    }

    void push_back(std::shared_ptr<T> element) {
        elements.push_back(element);
    }

    void remove(std::shared_ptr<T> element) {
        elements.remove(element);
    }

    iterator begin() override {
        return iterator(std::make_unique<ListIteratorNonConst>(elements, elements.begin()));
    }

    iterator end() override {
        return iterator(std::make_unique<ListIteratorNonConst>(elements, elements.end()));
    }

    const_iterator cbegin() const override {
        return const_iterator(std::make_unique<ListIteratorConst>(elements, elements.cbegin()));
    }

    const_iterator cend() const override {
        return const_iterator(std::make_unique<ListIteratorConst>(elements, elements.cend()));
    }

    iterator rbegin() override {
        return iterator(std::make_unique<ListIteratorReverseNonConst>(elements, elements.rbegin()));
    }

    iterator rend() override {
        return iterator(std::make_unique<ListIteratorReverseNonConst>(elements, elements.rend()));
    }

};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_SIMPLEOBJECTREFERENCELISTPROPERTY_H
