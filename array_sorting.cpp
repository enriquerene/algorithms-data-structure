#include <iostream>
#include <string>

class Array {
    int *array;
    size_t length;

    public:
    Array(size_t length, int *numbers) {
        this->array = numbers;
        this->length = length;
    };

    int *sort(std::string order = "asc") {
        if (order == "desc") {
            descending_sort();
        } else {
            ascending_sort();
        }
        return this->array;
    }

    void ascending_sort() {
        int temp;
        for (size_t i = 1; i < this->length; ++i) {
            for (size_t j = i; j > 0; --j) {
                if (this->array[j] < this->array[j-1]) {
                    temp = this->array[j];
                    this->array[j] = this->array[j-1];
                    this->array[j-1] = temp;
                }
            }
        }
    }

    void descending_sort() {}

    void stringfy(std::string message = "") {
        std::cout << message << std::endl;
        std::cout << "[ ";
        for (size_t i = 0; i < this->length; ++i) {
            std::cout << this->array[i];
            if (i != this->length -1) {
                std::cout << ", ";
            }
        }
        std::cout << " ]" << std::endl;
    }
};

int main() {
    int arr_one[5] = {8, -2, 6, 4, 5};
    int arr_two[7] = {10, -7, 11, 4, 5, 11, -2};


    Array a1 (5, arr_one);
    a1.stringfy("Array One before sorting:");
    a1.sort();
    a1.stringfy("Array One after sorting:");

    std::cout << std::endl;

    Array a2 (7, arr_two);
    a2.stringfy("Array Two before sorting:");
    a2.sort();
    a2.stringfy("Array Two after sorting:");

    return 0;
};
