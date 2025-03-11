#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
#include <stdexcept>

template <class T>
class Darray {
private:
    T* arr;
    size_t capacity;
    size_t size;

    void resize(size_t newCapacity) {
        T* newArr = new T[newCapacity];
        for (size_t i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    Darray(size_t cap = 4) : capacity(cap), size(0) {
        arr = new T[capacity];
    }

    ~Darray() {
        delete[] arr;
    }

    void append(const T& element) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        arr[size++] = element;
    }

    void insert(const T& element, size_t index) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size >= capacity) {
            resize(capacity * 2);
        }
        for (size_t i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        size++;
    }

    void remove() {
        if (size == 0) {
            throw std::underflow_error("Array is empty");
        }
        size--;
        if (size <= capacity / 4 && capacity > 10) {
            resize(capacity / 2);
        }
    }

    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        if (size <= capacity / 4 && capacity > 10) {
            resize(capacity / 2);
        }
    }

    T get(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    size_t getSize() const {
        return size;
    }

    void reverse() {
        size_t start = 0;
        size_t end = size - 1;
        while (start < end) {
            T temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void bubblesort() {
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void display() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
};

#endif
