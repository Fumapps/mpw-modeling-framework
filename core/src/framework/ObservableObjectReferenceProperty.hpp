
#ifndef DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTREFERENCEPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTREFERENCEPROPERTY_H

#include <vector>
#include <functional>
#include "ObservableObjectProperty.hpp"

namespace framework {

template<typename T>
class ObservableObjectReferenceProperty : public ObservableObjectProperty<T> {

private:

    std::weak_ptr<T> element{};

public:

    void set(std::shared_ptr<T> element) {
        std::shared_ptr<T> oldElement = this->element.lock();

        if (this->element.lock() != element) {
            this->element = element;
            ObservableObjectProperty<T>::notifyChanged(*oldElement.get(), *element);
        }
    }

    std::shared_ptr<T> get() const override {
        return this->element.lock();
    }

    typename ObservableObjectProperty<T>::OptionalObjectConstReference getReference() const override {
        typename ObservableObjectProperty<T>::OptionalObjectConstReference result;
        if (this->element.lock() != nullptr) {
            result = *this->element.lock();
        }
        return result;
    }

    typename ObservableObjectProperty<T>::OptionalObjectReference getReference() override {
        typename ObservableObjectProperty<T>::OptionalObjectReference result;
        if (this->element.lock() != nullptr) {
            result = *this->element.lock();
        }
        return result;
    }

};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTREFERENCEPROPERTY_H
