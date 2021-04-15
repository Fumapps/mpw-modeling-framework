#ifndef DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTREFERENCELISTPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTREFERENCELISTPROPERTY_H

#include <list>
#include <functional>
#include <memory>
#include "ObservableObjectListProperty.hpp"
#include "iterators/WeakPointerListIterator.hpp"

namespace framework {

template<typename T>
class ObservableObjectReferenceListProperty : public ObservableObjectListProperty<T> {
    static constexpr bool useConstTrue = true;
    static constexpr bool useConstFalse = false;

    using inherited = ObservableObjectListProperty<T>;
    using iterator = typename inherited::iterator;
    using const_iterator = typename inherited::const_iterator;

private:

    std::list<std::weak_ptr<T>> elements{};

public:

    using ListIteratorNonConst = WeakPointerListIterator<T, decltype(elements.begin()), useConstFalse>;
    using ListIteratorConst = WeakPointerListIterator<T, decltype(elements.cbegin()), useConstTrue>;
    using ListIteratorReverseNonConst = WeakPointerListIterator<T, decltype(elements.rbegin()), useConstFalse>;

    const std::list<std::weak_ptr<T>>& getElements() const {
        return elements;
    }

    void add(std::shared_ptr<T> element) {
        ObservableObjectListProperty<T>::references.push_back(*element);
        elements.push_back(element);
        ObservableListProperty<T>::notifyAdded(*element);
    }

    void remove(std::shared_ptr<T> element) {
        ObservableObjectListProperty<T>::references.remove_if([element](auto& referenceWrapper) {
            return &referenceWrapper.get() == element.get();
        });
        elements.remove_if([element](auto& weakPtr) {
            return weakPtr.lock() == element;
        });
        ObservableListProperty<T>::notifyRemoved(*element);
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

#endif //DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTREFERENCELISTPROPERTY_H
