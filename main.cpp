#include <iostream>
#include <cassert>
#include <vector>
#include "SmartPointer.hpp"

using namespace std;

/* Test Program */
int main(void) {
    // heap allocation
    SmartPointer<int> *sp1 = new SmartPointer<int>(new int(1));
    SmartPointer<int> *sp2 = new SmartPointer<int>(new int(2));
    SmartPointer<int> *sp3 = new SmartPointer<int>(new int());
    assert(**sp1 != **sp2);
    sp3 = sp1; // like shallow copy
//    assert(&sp1 != &sp3);
    assert(sp1 == sp3);
    assert(*sp1 == *sp3);
    assert(**sp1 == **sp3);
    sp3 = sp2;
    sp2 = sp1;
    sp3 = sp1;
    // now sp2 and sp3 become dangling pointers

    delete sp1;
    delete sp2;
    delete sp3;

    // stack allocation
    SmartPointer<int> var(new int(7));
    assert(*var == 7);

    SmartPointer<vector<int> > vectorPtr(new vector<int>());
    assert(vectorPtr->empty());
    vectorPtr->push_back(0);
    vectorPtr->push_back(1);
    vectorPtr->push_back(2);
    vectorPtr->push_back(3);
    assert(vectorPtr->at(0) == 0);
    assert(vectorPtr->at(1) == 1);
    assert(vectorPtr->at(2) == 2);
    assert(vectorPtr->at(3) == 3);

    SmartPointer <int> ptrtoInt(new int(4));
    SmartPointer <int> ptrtoInt2 = ptrtoInt;
    assert(ptrtoInt2 == ptrtoInt);
    assert(*ptrtoInt2 == *ptrtoInt);

    SmartPointer <int> ptrtoInt3;
    assert(ptrtoInt3 == nullptr);
    ptrtoInt3 = SmartPointer <int>(new int(2));
    assert(*ptrtoInt3 == 2);
    SmartPointer <int> ptrtoInt4;
    ptrtoInt4 = ptrtoInt3;
    return 0;
}
