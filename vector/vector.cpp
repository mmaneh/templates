#include "vector.hpp"
#include <exception>
#include <cassert>
#include <algorithm>
#include <iostream>

template<typename T>
MyVector<T>::MyVector() : size{0}, capacity{0}, data{nullptr} {}

template<typename T>
MyVector<T>::MyVector(size_type sz) : size{sz}, capacity{sz} {
    data = new value_type[size];
}

template<typename T>
MyVector<T>::MyVector(size_t sz, const size_type val) : size{sz}, capacity{sz} {
    data = new value_type[size];
    for (size_type i = 0; i < size; ++i) {
        data[i] = val;
    }
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other) : size{other.size}, capacity{other.capacity} {
    data = new value_type[size];
    for (size_type i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
MyVector<T>::MyVector(MyVector&& other) noexcept : size{other.size}, capacity{other.capacity}, data{other.data} {
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if(this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new value_type[size];
        for(size_type i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept {
    if(this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = other.data;
        other.size = 0;
        other.capacity = 0;
        other.data = nullptr;       
    }
    return * this;
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] data;
}

template<typename T>
typename MyVector<T>::reference MyVector<T>::operator[](size_type idx) {
    return data[idx];
}

template<typename T>
const typename MyVector<T>::reference MyVector<T>::operator[](size_type idx) const {
    return data[idx];
}

template<typename T>
typename MyVector<T>::reference MyVector<T>::front() {
    return data[0];
}

template<typename T>
const typename MyVector<T>::reference MyVector<T>::front() const {
    return data[0];
}

template<typename T>
typename MyVector<T>::reference MyVector<T>::back() {
    return data[size - 1];
}

template<typename T>
const typename MyVector<T>::reference MyVector<T>::back() const {
    return data[size - 1];
}

template<typename T>
typename MyVector<T>::reference MyVector<T>::at(size_type pos) {
    if(pos >= size) {
        throw std::out_of_range("out of range");
    }  
    return data[pos];
}

template<typename T>
const typename MyVector<T>::reference MyVector<T>::at(size_type pos) const {
    if(pos >= size) {
        throw std::out_of_range("out of range");
    }  
    return data[pos];
}

template<typename T>
typename MyVector<T>::pointer MyVector<T>::begin() {
    return data;
}

template<typename T>
const typename MyVector<T>::pointer MyVector<T>::begin() const {
    return data;
}

template<typename T>
typename MyVector<T>::pointer MyVector<T>::end() {
    return data + size;
}

template<typename T>
const typename MyVector<T>::pointer MyVector<T>::end() const {
    return data + size;
}

template<typename T>
bool MyVector<T>::empty() const {
    return size == 0;
}

template<typename T>
typename MyVector<T>::size_type MyVector<T>::size_() {
    return size;
}

template<typename T>
typename MyVector<T>::size_type MyVector<T>::capacity_() {
    return capacity;
}

template<typename T>
void MyVector<T>::clear() {
    size = 0;
}

template<typename T>
void MyVector<T>::push_back(const reference value) {
    if(size == capacity) {
        size_type newCapacity = (capacity == 0) ? 1 : capacity * 2;
        pointer newData = new value_type[newCapacity];
        for (size_type i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size++] = std::move(value); 
}

template<typename T>
void MyVector<T>::push_back(T&& value) {
    if(size == capacity) {
        size_type newCapacity = (capacity == 0) ? 1 : capacity * 2;
        pointer newData = new value_type[newCapacity];
        for (size_type i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size++] = std::move(value); 
}

template<typename T>
void MyVector<T>::pop_back() {
    --size;
}

template<typename T>
typename MyVector<T>::pointer MyVector<T>::insert(size_type pos, size_type value) {
    if(pos > size) throw std::out_of_range("out of range");
    if(size == capacity) {
        size_type newCapacity = (capacity == 0) ? 1 : capacity * 2;
        pointer NewData = new value_type[newCapacity];
        for (size_type i = 0; i < pos; ++i) {
            NewData[i] = data[i];
        } 
        NewData[pos] = value;
        for (size_type i = pos; i < size; ++i) {
            NewData[i + 1] = data[i];
        }
        delete[] data;
        data = NewData;
        capacity = newCapacity;
        ++size;
    } else {
        for (size_type i = pos; i < size; ++i) {
            data[i + 1] = data[i];
        }
        data[pos] = value;
        ++size;
    }
    return &data[pos];
}

template<typename T>
typename MyVector<T>::pointer MyVector<T>::erase(size_type pos) {
    if(pos > size) throw std::out_of_range("out of range");
    for (size_type i = pos; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
    return &data[pos];
}

template<typename T>
void MyVector<T>::swap(MyVector& other) {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

template<typename T>
bool operator==(const MyVector<T>& obj1, const MyVector<T>& obj2) {
    if (obj1.size() != obj2.size()) return false;
    for (size_t i = 0; i < obj1.size(); ++i) {
        if(obj1[i] != obj2[i]) return false;
    }
    return true;
}

template<typename T>
bool operator!=(const MyVector<T>& obj1, const MyVector<T>& obj2) {
    return !(obj1 == obj2);
}

template<typename T>
bool operator<(const MyVector<T>& obj1, const MyVector<T>& obj2) {
    return std::lexicographical_compare(obj1.begin(), obj1.end(), obj2.begin(), obj2.end());
}

template<typename T>
bool operator>(const MyVector<T>& obj1, const MyVector<T>& obj2) {
    return obj2 < obj1;
}

template<typename T>
bool operator<=(const MyVector<T>& obj1, const MyVector<T>& obj2) {
    return !(obj2 < obj1);
}

template<typename T>
bool operator>=(const MyVector<T>& obj1, const MyVector<T>& obj2) {
    return !(obj1 < obj2);
}

