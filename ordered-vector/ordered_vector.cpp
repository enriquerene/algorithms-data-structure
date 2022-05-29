#include <iostream>
#include <stdexcept>

class OrderedVector {
    size_t length;
    int *data;

    public:
    OrderedVector() {
        this->length = 0;
        this->data = new int[0];
    };
    OrderedVector(size_t length, int *data) {
        this->length = length;
        this->data = new int[length];
        for (size_t i = 0; i < length; ++i) {
            this->data[i] = data[i];
        }
        this->sort();
    };
    ~OrderedVector() {
        delete[] this->data;
    };

    void sort() {
        int value;
        for (size_t i = 0; i < this->length; ++i) {
            for (size_t j = 0; j <= i; ++j) {
                if (this->data[i] < this->data[j]) {
                    value = this->data[j];
                    this->data[j] = this->data[i];
                    this->data[i] = value;
                }
            }
        }
    };

    size_t size() {
        return this->length;
    };

    void print() {
        std::cout << "[";
        for (size_t i = 0; i < this->length; ++i) {
            std::cout << this->data[i];
            if (i != this->length - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    };

    int read(size_t position) {
        if (position >= this->length) {
            throw std::invalid_argument("The requested index is not defined in OrderedVector.");
        }
        return this->data[position];
    };

    int search(int value) {
        if (this->length == 0) return -1;
        int current;
        size_t position = 0;
        while (position < this->length) {
            current = this->data[position];
            if (value == current) return position;
            if (value < current) return -1;
            position += 1;
        }
        return -1;
    };

    void insert(int value) {
        int data[this->length];
        for (size_t i = 0; i < this->length; ++i) {
            data[i] = this->data[i];
        }
        this->length += 1;
        delete[] this->data;
        this->data = new int[this->length];

        size_t insertPosition = this->length - 1;
        for (size_t i = 0; i < this->length - 1; ++i) {
            if (data[i] <= value) {
                this->data[i] = data[i];
            }
            if (data[i] > value) {
                if (insertPosition > i) {
                    insertPosition = i;
                }
                this->data[i+1] = data[i];
            }
        }

        this->data[insertPosition] = value;
    };


    int operator [](int position) {
        return this->read(position);
    };
};
