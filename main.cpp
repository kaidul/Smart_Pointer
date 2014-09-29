#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include "SmartPointer.hpp"

/* Test Program */
int main(void) {
    /*----------------heap allocation--------------------------*/
    SmartPointer<int> *sp1 = new SmartPointer<int>(new int(1));
    SmartPointer<int> *sp2 = new SmartPointer<int>(new int(2));
    SmartPointer<int> *sp3 = new SmartPointer<int>(new int());
    assert(**sp1 != **sp2);
    *sp1 = *sp1; // no reference count will occur

    *sp3 = *sp1; // like shallow copy
    assert(*sp1 == *sp3);
    assert(**sp1 == **sp3);
    *sp3 = *sp2;
    *sp2 = *sp1;
    *sp3 = *sp1;
    // now sp2 and sp3 become dangling pointers

    delete sp1;
    delete sp2;
    delete sp3;

    /*-------------stack allocation------------- */
    SmartPointer<int> var(new int(7));
    assert(*var == 7);

    SmartPointer<int> foo; // foo = NULL
    SmartPointer<int> bar(new int(7)); // bar = 7;
    foo = bar;
    assert(foo == bar);
    assert(*foo == *bar);

    /* pointer to complex data types */
    SmartPointer<std::vector<int> > vectorPtr(new std::vector<int>());
    assert(vectorPtr->empty());
    vectorPtr->push_back(1);
    vectorPtr->push_back(2);
    vectorPtr->push_back(3);
    assert(vectorPtr->at(0) == 1);
    assert(vectorPtr->at(1) == 2);
    assert(vectorPtr->at(2) == 3);
    SmartPointer<std::unordered_set<int> > *setPtr = new SmartPointer<std::unordered_set<int> >(new std::unordered_set<int>());
    (*setPtr)->insert(1);
    assert( *((*setPtr)->begin()) == 1 );

    SmartPointer <int> ptrtoInt(new int(4));
    SmartPointer <int> ptrtoInt2 = ptrtoInt;
    assert(ptrtoInt2 == ptrtoInt);
    assert(*ptrtoInt2 == *ptrtoInt);

    SmartPointer <int> ptrtoInt3; // NULL
    assert(ptrtoInt3 == nullptr);
    ptrtoInt3 = SmartPointer <int>(new int(2)); // operator = (T*)
    assert(*ptrtoInt3 == 2);
    SmartPointer <int> ptrtoInt4;
    ptrtoInt4 = ptrtoInt3;
    std::cout << "Success!\n";
    return 0;
}
