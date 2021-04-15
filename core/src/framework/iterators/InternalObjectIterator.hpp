#ifndef DE_UNISTUTTGART_FRAMEWORK_INTERNALOBJECTITERATOR_H
#define DE_UNISTUTTGART_FRAMEWORK_INTERNALOBJECTITERATOR_H

namespace framework {

template<typename T, bool constType>
/// \brief has to be implemented by the concrete collection
class InternalObjectIterator {
public:

    using ObjectReturnType = typename std::conditional<constType, const T, T>::type;

    virtual ~InternalObjectIterator() = default;

    virtual std::unique_ptr<InternalObjectIterator> clone() = 0;

    virtual ObjectReturnType* current() const = 0;

    virtual ObjectReturnType* next() = 0;
    // virtual bool operator==(const InternalObjectIterator& rhs) const = 0;
};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_INTERNALOBJECTITERATOR_H
