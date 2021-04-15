#ifndef DE_UNISTUTTGART_FRAMEWORK_WEAKPOINTERLISTITERATOR_H
#define DE_UNISTUTTGART_FRAMEWORK_WEAKPOINTERLISTITERATOR_H

#include <list>
#include <memory>
#include <type_traits>
#include "InternalObjectIterator.hpp"

namespace framework {

template<typename T, typename iterator, bool constType>
class WeakPointerListIterator final : public InternalObjectIterator<T, constType> {
private:
    using ListType = typename std::conditional<constType, const std::list<std::weak_ptr<T>>, std::list<std::weak_ptr<T>>>::type;

    ListType& elements;
    iterator currentIterator;

public:

    using inherited = InternalObjectIterator<T, constType>;
    using ObjectReturnType = typename inherited::ObjectReturnType;

    WeakPointerListIterator(ListType& elements, iterator listIterator)
            : elements(elements), currentIterator(listIterator) {
        // ensure that the begin iterator does not point to an
        // expired weak-pointer
        increaseUntilCurrentIsNotNull();
    }

    ~WeakPointerListIterator() override = default;

    std::unique_ptr<inherited> clone() override {
        return std::make_unique<WeakPointerListIterator>(elements, currentIterator);
    }

    ObjectReturnType* current() const override {
        if (currentIterator == endIter()) {
            return nullptr;
        }
        return (*currentIterator).lock().get();
    }

    ObjectReturnType* next() override {
        currentIterator++;
        increaseUntilCurrentIsNotNull();
        return current();
    }

private:

    void increaseUntilCurrentIsNotNull() {
        ObjectReturnType* element = current();
        while (element == nullptr && currentIterator != endIter()) {
            element = next();
        }
    }

    template<typename iterator_type=iterator>
    typename std::enable_if<std::is_same<iterator_type, typename ListType::iterator>::value, iterator_type>::type
    endIter() const {
        return elements.end();
    }

    template<typename iterator_type=iterator>
    typename std::enable_if<std::is_same<iterator_type, typename ListType::const_iterator>::value, iterator_type>::type
    endIter() const {
        return elements.cend();
    }

    template<typename iterator_type=iterator>
    typename std::enable_if<std::is_same<iterator_type, typename ListType::reverse_iterator>::value, iterator_type>::type
    endIter() const {
        return elements.rend();
    }

    template<typename iterator_type=iterator>
    typename std::enable_if<std::is_same<iterator_type, typename ListType::const_reverse_iterator>::value, iterator_type>::type
    endIter() const {
        return elements.crend();
    }

};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_WEAKPOINTERLISTITERATOR_H
