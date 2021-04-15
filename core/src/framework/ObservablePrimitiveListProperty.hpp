
#ifndef DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEPRIMITIVELISTPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEPRIMITIVELISTPROPERTY_H

#include <list>
#include <memory>
#include "ObservableListProperty.hpp"

namespace framework {

template<typename T>
class ObservablePrimitiveListProperty : public ObservableListProperty<T> {

private:

    std::list<T> elements{};

public:

    const std::list<T>& get() const {
        return elements;
    }

    void add(T element) {
        elements.push_back(element);
        ObservableListProperty<T>::notifyAdded(element);
    }

    void remove(T element) {
        elements.remove(element);
        ObservableListProperty<T>::notifyRemoved(element);
    }

    void forEach(std::function<void(const T&)> consumer) const override {
        std::for_each(elements.cbegin(), elements.cend(), consumer);
    }

    const T& front() const {
        return elements.front();
    }

    [[nodiscard]] bool empty() const override {
        return elements.empty();
    }

};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEPRIMITIVELISTPROPERTY_H
