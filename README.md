# Smart Pointer

Smart Pointer Implementation using *Non-intrusive Reference Counting* mechanism.

## Usage

<pre lang="cpp">
SmartPointer<int> foo; // foo = NULL
SmartPointer<int> bar(new int(7)); // bar = 7;

SmartPointer<int> var = new SmartPointer<int>(new int(4)); // int *var = new int(4);

SmartPointer<std::vector<int> > vectorPtr = new SmartPointer<std::vector<int> >(new vector<int>());
vectorPtr->push_back(1);
assert(vectorPtr.at(0) == 1);
</pre>

