
#ifndef DE_UNISTUTTGART_FRAMEWORK_OBSERVABLELISTPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_OBSERVABLELISTPROPERTY_H

#include <list>
#include <functional>
#include <memory>
#include <map>

namespace framework {

template<typename T>
class ObservableListProperty {
public:

    using ListenerId = unsigned int;
    using Listener = std::function<void(const T&)>;

private:

    mutable ListenerId nextId = 0;

protected:

    mutable std::map<ListenerId, Listener> addedListeners;
    mutable std::map<ListenerId, Listener> removedListeners;

    void notifyAdded(const T& element) const {
        for (auto&[id, listener] : addedListeners) {
            listener(element);
        }
    }

    void notifyRemoved(const T& element) const {
        for (auto&[id, listener] : removedListeners) {
            listener(element);
        }
    }

public:

    virtual ~ObservableListProperty() = default;

    virtual void forEach(std::function<void(const T&)> consumer) const = 0;

    [[nodiscard]] virtual bool empty() const = 0;

    ListenerId addOnAddedListener(
            Listener listener) const { // mark const to allow returning const property which allows modifying listeners
        addedListeners[nextId] = listener;
        return nextId++;
    }

    void removeOnAddedListener(
            ListenerId id) const { // mark const to allow returning const property which allows modifying listeners
        addedListeners.erase(id);
    }

    ListenerId addOnRemovedListener(
            Listener listener) const { // mark const to allow returning const property which allows modifying listeners
        removedListeners[nextId] = listener;
        return nextId++;
    }

    void removeOnRemovedListener(
            ListenerId id) const { // mark const to allow returning const property which allows modifying listeners
        removedListeners.erase(id);
    }

    ListenerId addOnAnyChangeListener(
            Listener listener) const { // mark const to allow returning const property which allows modifying listeners
        addedListeners[nextId] = listener;
        removedListeners[nextId] = listener;
        return nextId++;
    }

    void removeOnAnyChangeListener(
            ListenerId id) const { // mark const to allow returning const property which allows modifying listeners
        addedListeners.erase(id);
        removedListeners.erase(id);
    }

};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_OBSERVABLELISTPROPERTY_H
