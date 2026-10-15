#include "as1.hpp"
#include <utility>

namespace homework {

    // As 1.1 Swap three raw pointers (cyclic shift: a -> b -> c -> a)
    void swap_ptr(int* a, int* b, int *c) {
        if (!a || !b || !c) return; // Safety check for null pointers
        
        int temp = *a; // Save the original value of a
        *a = *b;       // a gets b's value
        *b = *c;       // b gets c's value
        *c = temp;     // c gets a's original value
    }

    // As 1.2 Unique data class implementation
    UniqueData::UniqueData(int value) 
        : data_(std::make_unique<int>(value)) {}

    int UniqueData::get() const {
        return *data_; // Dereference the unique_ptr to get the int value
    }

    void UniqueData::set(int value) {
        *data_ = value; // Update the value stored in the heap
    }

}; // namespace homework
