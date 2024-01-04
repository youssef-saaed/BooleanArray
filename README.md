# BooleanArray

A C++ class for storing boolean values efficiently using a single bit per value.

## Usage

Include the `BooleanArray.h` header file in your C++ project and use the `BooleanArray` class as follows:

```cpp
#include "BooleanArray.h"

// Example Usage
int main() {
    // Create a BooleanArray with a specified size
    BooleanArray boolArray(100);

    // Set and get values
    boolArray.set(5, true);
    bool value = boolArray[5];
    
    return 0;
}
