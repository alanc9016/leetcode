#include <iostream>
#include "Vector.h"

template<typename T>
void PrintVector(const Vector<T>& vector) {
    for (size_t i = 0; i < vector.Size(); i++) 
        std::cout << vector[i] << " ";
    std::cout << std::endl;
}

int main() {
    Vector<int> vector;
    vector.Prepend(3);
    vector.Prepend(2);
    vector.Prepend(1);
    vector.Delete(1);

    PrintVector(vector);
    /* std::cout << vector[1] << std::endl; */

    return 0;
}

