#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_SEMAPHORE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_SEMAPHORE_H

#include <mutex>
#include <condition_variable>
#include <memory>

namespace framework {

class Semaphore;

/**
 * \brief RAII based lock object
 */
class SemaphoreLock final {
private:

    std::unique_ptr<Semaphore> semaphore; // use unique_ptr, since object storage is not supported by forward declaration

public:

    explicit SemaphoreLock(Semaphore& semaphore);
    ~SemaphoreLock();
};

/**
 * \brief Semaphore implementation which reuses same underlying mutex when copying the object.
 * \note Inspired by https://sodocumentation.net/cplusplus/topic/9785/semaphore
 */
class Semaphore final {
private:

    // Note: use shared-pointers to allow simple copy / sharing of Semaphore objects

    std::shared_ptr<unsigned int> count;
    std::shared_ptr<std::condition_variable> conditionVariable;
    std::shared_ptr<std::mutex> mutex;

public:

    explicit Semaphore(unsigned int count = 1);

    /**
     * Returns a RAII based object, which acquires the semaphore in the constructor and
     * releases the semaphore in the destructor.
     * @return a SemaphoreLock object
     */
    SemaphoreLock lock();

    /**
     * Acquires the semphore.
     * If the internal counter has one or more "slots" available, the control flow will return.
     * Otherwise, the control flow will block, until some thread calls release.
     */
    void acquire();

    /**
     * Releases the semaphore and increments the internal "slot" counter.
     * If any thread is blocked, since it wants to acquire the semaphore, it will be notified.
     */
    void release();

    /**
     * Non-blocking and safe operator to retrieve, if the semaphore can be acquired.
     * @return true, if the semaphore is fully used (internal counter is zero)
     */
    bool isLocked();

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_SEMAPHORE_H
