#ifndef SMARTPTR_H
#define SMARTPTR_H

#include <cstddef>

namespace smartptr {

template <typename T>
class SmartPointer {
public:
    SmartPointer(void);
    SmartPointer(T *);
    SmartPointer(SmartPointer<T> &);
    SmartPointer(const SmartPointer<T> &);
    const SmartPointer& operator = (T *);
    const SmartPointer& operator = (SmartPointer<T> &);
    const SmartPointer& operator = (const SmartPointer<T> &);
    ~SmartPointer();

    T& operator * ();
    T* operator -> ();
    bool operator == (const SmartPointer<T> &);
    bool operator == (const T *);
    bool operator != (const SmartPointer<T> &);
    bool operator != (const T *);
private:
    T *address;
    int *refCount;

    void increaseRefCount();
    void decreaseRefCount();
};

}

#include "SmartPointer.cpp"

#endif // SMARTPTR_H

