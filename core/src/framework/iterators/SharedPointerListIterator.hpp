#ifndef DE_UNISTUTTGART_FRAMEWORK_SHAREDPOINTERLISTITERATOR_H
#define DE_UNISTUTTGART_FRAMEWORK_SHAREDPOINTERLISTITERATOR_H

#include <list>
#include <memory>
#include "InternalObjectIterator.hpp"

namespace framework {

template<typename T, typename iterator, bool constType>
class SharedPointerListIterator final : public InternalObjectIterator<T, constType> {
private:
    using ListType = typename std::conditional<constType, const std::list<std::shared_ptr<T>>, std::list<std::shared_ptr<T>>>::type;

    ListType& elements;
    iterator currentIterator;

public:

    using inherited = InternalObjectIterator<T, constType>;
    using ObjectReturnType = typename InternalObjectIterator<T, constType>::ObjectReturnType;

    SharedPointerListIterator(ListType& elements, iterator listIterator)
            : elements(elements), currentIterator(listIterator) {
    }

    ~SharedPointerListIterator() override = default;

    std::unique_ptr<inherited> clone() override {
        return std::make_unique<SharedPointerListIterator<T, iterator, constType>>(elements, currentIterator);
    }

    ObjectReturnType* current() const override {
        if (currentIterator == endIter()) {
            return nullptr;
        }
        return (*currentIterator).get();
    }

    ObjectReturnType* next() override {
        currentIterator++;
        return current();
    }

private:

    template<typename iterator_type = iterator>
    typename std::enable_if<std::is_same<iterator_type, typename ListType::iterator>::value, iterator_type>::type
    endIter() const {
        return elements.end();
    }

    template<typename iterator_type = iterator>
    typename std::enable_if<std::is_same<iterator_type, typename ListType::const_iterator>::value, iterator_type>::type
    endIter() const {
        return elements.cend();
    }

    template<typename iterator_type = iterator>
    typename std::enable_if<std::is_same<iterator_type, typename ListType::reverse_iterator>::value, iterator_type>::type
    endIter() const {
        return elements.rend();
    }

    template<typename iterator_type = iterator>
    typename std::enable_if<std::is_same<iterator_type, typename ListType::const_reverse_iterator>::value, iterator_type>::type
    endIter() const {
        return elements.crend();
    }

};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_SHAREDPOINTERLISTITERATOR_H
