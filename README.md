# Smart Pointer

Smart Pointer Implementation using *Non-intrusive Reference Counting* mechanism.

## Usage

```cpp
SmartPointer<int> foo; // foo = NULL
SmartPointer<int> bar(new int(7)); // bar = 7;
foo = bar;
assert(foo == bar);
assert(*foo == *bar);

SmartPointer<int> var = new SmartPointer<int>(new int(4)); // int *var = new int(4);
assert(*var == 4);

/* pointer to complex data types */
SmartPointer<std::vector<int> > vectorPtr(new std::vector<int>());
assert(vectorPtr->empty());
vectorPtr->push_back(1);
assert(vectorPtr->at(0) == 1);

SmartPointer<std::unordered_set<int> > *setPtr = new SmartPointer<std::unordered_set<int> >(new std::unordered_set<int>());
(*setPtr)->insert(1);
assert( *((*setPtr)->begin()) == 1 );
```
