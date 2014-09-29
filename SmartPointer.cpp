#ifndef SMARTPTR_CPP
#define SMARTPTR_CPP

#include <stdexcept>
#include "SmartPointer.hpp"

using namespace smartptr;

template <typename T>
SmartPointer<T>::SmartPointer()
    : address(nullptr)
    , refCount(nullptr) {
}

template <typename T>
SmartPointer<T>::SmartPointer(T *address)
    : address(address)
    , refCount(new int(0)) {
    increaseRefCount();
}

template <typename T>
SmartPointer<T>::SmartPointer(SmartPointer<T> &other)
    : address(other.address)
    , refCount(other.refCount) {
    increaseRefCount();
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &other)
    : address(other.address)
    , refCount(other.refCount) {
    increaseRefCount();
}

template <typename T>
const SmartPointer<T>& SmartPointer<T>::operator = (T *address) { // ptr1 = int(new int(2))
    decreaseRefCount();
    this->address = address;
    this->refCount = 0;
    increaseRefCount();
    return *this;
}

template <typename T>
const SmartPointer<T>& SmartPointer<T>::operator = (SmartPointer<T> &other) {
    if(this != &other) {
        decreaseRefCount();
        this->address = other.address;
        this->refCount = other.refCount;
        increaseRefCount();
    }
    return *this;
}

template <typename T>
const SmartPointer<T>& SmartPointer<T>::operator = (const SmartPointer<T> &other) {
    decreaseRefCount();
    this->address = other.address;
    this->refCount = other.refCount;
    increaseRefCount();
    return *this;
}

template <typename T>
SmartPointer<T>::~SmartPointer() {
    decreaseRefCount();
}

template <typename T>
void SmartPointer<T>::increaseRefCount() {
    if(refCount == nullptr)
        return;
    ++(*refCount);
}

template <typename T>
void SmartPointer<T>::decreaseRefCount() {
    if(refCount == nullptr)
        return;
    --(*refCount);

    if((*refCount) < 1) {
        delete refCount;
        if(address != nullptr)
            delete address;
    }
}

template <typename T>
T& SmartPointer<T>::operator * () {
    if(address == nullptr)
        throw std::runtime_error("Invalid Action!");
    return *address;
}

template <typename T>
T* SmartPointer<T>::operator -> () {
    if(address == nullptr)
        throw std::runtime_error("Invalid Action!");
    return address;
}

template <typename T>
bool SmartPointer<T>::operator == (const SmartPointer<T> &other) {
    return address == other.address;
}

template <typename T>
bool SmartPointer<T>::operator == (const T *address) {
    return this->address == address;
}

template <typename T>
bool SmartPointer<T>::operator != (const SmartPointer<T> &other) {
    return !(this->operator==(other) );
}

template <typename T>
bool SmartPointer<T>::operator != (const T *address) {
    return !(this->operator==(address));
}

#endif // SMARTPTR_H

