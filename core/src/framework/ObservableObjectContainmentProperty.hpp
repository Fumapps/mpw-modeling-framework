
#ifndef DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTCONTAINMENTPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTCONTAINMENTPROPERTY_H

#include <vector>
#include <functional>
#include "ObservableObjectProperty.hpp"

namespace framework {

template<typename T>
class ObservableObjectContainmentProperty : public ObservableObjectProperty<T> {

private:

    std::shared_ptr<T> element{};

public:

    void set(std::shared_ptr<T> element) {
        std::shared_ptr<T> oldElement = this->element;

        if (this->element != element) {
            this->element = element;
            ObservableObjectProperty<T>::notifyChanged(*oldElement.get(), *element);
        }
    }

    std::shared_ptr<T> get() const override {
        return this->element;
    }

    typename ObservableObjectProperty<T>::OptionalObjectConstReference getReference() const override {
        typename ObservableObjectProperty<T>::OptionalObjectConstReference result;
        if (this->element != nullptr) {
            result = *this->element;
        }
        return result;
    }

    typename ObservableObjectProperty<T>::OptionalObjectReference getReference() override {
        typename ObservableObjectProperty<T>::OptionalObjectReference result;
        if (this->element != nullptr) {
            result = *this->element;
        }
        return result;
    }

};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTCONTAINMENTPROPERTY_H
