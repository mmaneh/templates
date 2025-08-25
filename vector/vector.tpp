#include "vector.hpp"
#include <exception>
#include <cassert>
#include <algorithm>
#include <iostream>

template<typename T>
MyVector<T>::MyVector() noexcept : size{0}, capacity{0}, data{nullptr} {}

template<typename T>
MyVector<T>::MyVector(size_t sz, const value_type& val) : MyVector {} {
    data = static_cast<T*>(operator new(sizeof(T) * count));
    try {
        std::uninitialized_fill_n(data, count, value);
        size = capacity = count;
    }
    catch(...) {
        operator delete(data);
        throw;
    }
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other) : MyVector {} {
   data = static_cast<T*> (operator new(sizeof(T) * other.capacity));

   try{
        std::uninitialized_copy_n(other.data, other.size, data);
        size = other.size;
        capacity = other.capacity;
   }
   catch(...) {
        operator delete (data);
        throw;
   }
}

template<typename T>
MyVector<T>::MyVector(MyVector&& other) noexcept : size{other.size}, capacity{other.capacity}, data{other.data} {
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

template <typename T>
MyVector<T>::MyVector(const std::initializer_list<T>& il) {
    data = static_cast<T*>(operator new (sizeof(T) * il.size()));

    try{
        std::uninitialized_copy_n(il.begin(), il.end(), data);
        capacity = size = il.size();
    }
    catch(...) {
        operator delet(data);
        throw;
    }
}
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if(this != &other) {
        MyVector<T> tmp(other);
        swap(tmp);
    }
    return *this;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept {
    if(this != &other) {
        MyVector<T> tmp(std::move(other));
        swap(tmp);
    }
    return * this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const std::initializer_list<T> &il) {
    Vector<T> tmp(il);
    swap(tmp);
    return *this;
}

template<typename T>
MyVector<T>::~MyVector() {
    clear();
    operator delete(data);
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

template <typename T>
typename MyVector<T>::pointer MyVector<T>::data_() {
    return data;
}

template <typename T>
const typename MyVector<T>::pointer MyVector<T>::data_() const noexcept{
    return data;
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
typename MyVector<T>::pointer MyVector<T>::begin() const {
    return data;
}

template<typename T>
typename MyVector<T>::pointer MyVector<T>::end() {
    return data + size;
}

template<typename T>
typename MyVector<T>::pointer MyVector<T>::end() const {
    return data + size;
}

template<typename T>
bool MyVector<T>::empty() const {
    return size == 0;
}

template<typename T>
typename MyVector<T>::size_type MyVector<T>::size_() const {
    return size;
}

template<typename T>
typename MyVector<T>::size_type MyVector<T>::capacity_() const {
    return capacity;
}
template <typename T>
void MyVector<T>::reserve(typename MyVector<T>::size_type newCap){
    if(newCap <= capacity) return;
    pointer Newdata = static_cast<T*>(operator new(sizeof(T) * newCap));
    size_type i = 0;
    try {
        for(; i < size; ++i) {
            new(&Newdata) T(data[i]);
        }
    }catch (...){
        for (size_type j = 0; j < size; ++j) {
            NewData[i].~T();
        }
        operator delete(Newdata);
        throw;
    }
    size_type tmp = size;
    clear;
    operator delete(data);
    size = tmp;
    cpacity = newCap;
    data = Newdata;
}
template<typename T>
void MyVector<T>::clear() {
    for (size_type i = 0; i < size; ++i) {
        data[i].~T();
    }
    size = 0;
}

template<typename T>
void MyVector<T>::insert(size_type pos, const value_type& value) {
    pointer Newdata = nullptr;
    size_type newCap = capacity;
    if(size == capacity) {
        Newdata = static_cast<T*>(operator new(sizeof(T) * capacity * 2));
        newCap = capacity * 2;
    }else {
        Newdata = static_cast<T*>(operator new(sizeof(T) * capacity));
    }

    try {

    for (size_type i = 0; i < pos; ++i) {
        new(&Newdata[i]) T(std::move(data[i]));
    }

    
        new(&Newdata[pos]) T(value);

    }catch (...){
        for (size_type i = 0; i < size; ++i) {
            new(data[i]) T(std::move(Newdata[i]));
        }
        operator delete(Newdata);
    }

    for (size_type i = pos; i < size + 1 ; ++i) {
        new (&Newdata[i]) T(std::move(data[i - 1]));
    }
    
    operator delete(data);
    data = Newdata;
    ++size;
    capacity = newCap;
}
////////////////////////////////////////////////////////////////
//////////////////edit////////////////////////////
template <typename T>
void MyVector<T>::insert(size_type pos, T&& value) {
     if (size == capacity) {
        reserve(capacity * 2);
    }

    for (size_type i = size; i >= pos; --i) {
        new (&data[i]) T(std::move(data[i - 1]));
    }
    new (&data[pos]) T(std::move(value));

    ++size;
}
template <typename T>
void Vector<T>::insert(size_type pos, size_type count, const T& value) {
    T* newData = nullptr;
    size_type newCapacity = capacity;

    if (size + count > capacity) {
        newData = static_cast<T *>(operator new(sizeof(T) * (size + count) * 2));
        newCapacity = (size + count) * 2;
    }
    else {
        
        newData = static_cast<T *>(operator new(sizeof(T) * capacity));
    }

    for (size_type i = 0; i < pos; ++i) {
        new (&newData[i]) T(std::move(data[i]));
    }

    try {
        std::uninitialized_fill_n(newData + pos, count, value);
    }
    catch (...) {
        for (size_type i = 0; i < pos; ++i) {
            new (&data[i]) T(std::move(newData[i]));
        }
        operator delete(newData);
        throw;
    }

    for (size_type i = size + count - 1; i > pos + count; --i) {
        new (&newData[i]) T(std::move(data[i - count]));
    }

    operator delete(data);
    data = newData;
    size += count;
    capacity = newCapacity;
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace(size_type pos, Args &&...args) {
    T* newData = nullptr;
    size_type newCapacity = capacity;

    if (size == capacity) {
	newCapacity = (capacity == 0 ? 1 : capacity * 2);
        newData = static_cast<T *>(operator new(sizeof(T) * newCapacity));
       
    }
    else {
        newData = static_cast<T *>(operator new(sizeof(T) * capacity));
    }

    for (size_type i = 0; i < pos; ++i) {
        new (&newData[i]) T(std::move(data[i]));
    }

    try {
        new (&newData[pos]) T(std::forward<Args>(args)...);
    }
    catch (...) {
        for (size_type i = 0; i < pos; ++i) {
            new (data[i]) T(std::move(newData[i]));
        }
        operator delete(newData);
        throw;
    }

    for (size_type i = size; i > pos; --i) {
        new (&newData[i]) T(std::move(data[i - 1]));
    }

    operator delete(data);
    data = newData;
    ++size;
    capacity = newCapacity;
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
typename MyVector<T>::pointer MyVector<T>::erase(size_type pos) {
    if(pos > size) throw std::out_of_range("out of range");
    for (size_type i = pos; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
    return &data[pos];
}


template <typename T>
template <typename... Args>
void Vector<T>::emplace_back(Args &&...args) {
    if (size == capacity) {
        reserve(capacity * 2);
    }
    new (&data[size]) T(std::forward<Args>(args)...);
    ++size;
} 

template<typename T>
void MyVector<T>::pop_back() {
    data[size - 1].~T();
    --size;
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
template class MyVector<int>;

