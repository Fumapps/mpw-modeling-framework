#include "MpwSemaphore.h"

namespace framework {

Semaphore::Semaphore(unsigned int count)
        : count(std::make_shared<unsigned int>(count))
        , mutex(std::make_shared<std::mutex>())
        , conditionVariable(std::make_shared<std::condition_variable>()) {
}

SemaphoreLock Semaphore::lock() {
    return SemaphoreLock(*this);
}

void Semaphore::acquire() {
    std::unique_lock<std::mutex> lock(*mutex);
    while ((*count) == 0) {
        conditionVariable->wait(lock);
    }
    (*count)--;
}

void Semaphore::release() {
    std::unique_lock<std::mutex> lock(*mutex);
    (*count)++;
    conditionVariable->notify_one();
}

bool Semaphore::isLocked() {
    return (*count) == 0;
}

SemaphoreLock::SemaphoreLock(Semaphore& semaphore)
        : semaphore(std::make_unique<Semaphore>(semaphore)) {
    this->semaphore->acquire();
}

SemaphoreLock::~SemaphoreLock() {
    this->semaphore->release();
}
}
