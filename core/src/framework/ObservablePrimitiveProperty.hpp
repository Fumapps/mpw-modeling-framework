
#ifndef DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEPRIMITIVEPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEPRIMITIVEPROPERTY_H

#include <vector>
#include <functional>
#include <map>

namespace framework {

template<typename T>
class ObservablePrimitiveProperty {
public:

    using ListenerId = unsigned int;
    using Listener = std::function<void(const T&, const T&)>;

private:

    T value{};

    mutable ListenerId nextId = 0;
    mutable std::map<ListenerId, Listener> listeners;

    void notifyChanged(const T& oldValue, const T& newValue) const {
        for (auto&[id, listener] : listeners) {
            listener(oldValue, newValue);
        }
    }

public:

    void set(const T& value) {
        T oldValue = this->value;

        if (this->value != value) {
            this->value = value;
            notifyChanged(oldValue, value);
        }
    }

    const T& get() const {
        return this->value;
    }

    ListenerId addListener(
            Listener listener) const { // mark const to allow returning const property which allows modifying listeners
        listeners[nextId] = listener;
        return nextId++;
    }

    void removeListener(
            ListenerId id) const { // mark const to allow returning const property which allows modifying listeners
        listeners.erase(id);
    }

};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_OBSERVABLEPRIMITIVEPROPERTY_H
