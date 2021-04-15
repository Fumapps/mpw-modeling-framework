
#ifndef DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTPROPERTY_H

#include <vector>
#include <functional>
#include <optional>

namespace framework {

template<typename T>
class ObservableObjectProperty {

public:
    using OptionalObjectConstReference = std::optional<std::reference_wrapper<const T>>;
    using OptionalObjectReference = std::optional<std::reference_wrapper<T>>;

protected:

    mutable std::vector<std::function<void(OptionalObjectConstReference, const T&)> > listeners;

    void notifyChanged(OptionalObjectConstReference oldElement, const T& newElement) const {
        for (auto& l : listeners) {
            l(oldElement, newElement);
        }
    }

public:

    virtual std::shared_ptr<T> get() const = 0;

    virtual OptionalObjectConstReference getReference() const = 0;
    virtual OptionalObjectReference getReference() = 0;

    void addListener(std::function<void(OptionalObjectConstReference,
                                        const T&)> listener) const { // mark const to allow returning const property which allows modifying listeners
        listeners.push_back(listener);
    }

    void removeListener(std::function<void(OptionalObjectConstReference,
                                           const T&)> listener) const { // mark const to allow returning const property which allows modifying listeners
        listeners.erase(listener);
    }
};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEOBJECTPROPERTY_H
