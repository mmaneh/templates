#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include <cassert>
#include <algorithm>

template <typename T>
class MyVector {
public:
    using value_type = T;
    using size_type = size_t;
    using reference = value_type&;
    using pointer = value_type*;

private:
    size_type size;
    size_type capacity;
    pointer data;

public:
    MyVector();
    MyVector(size_type sz);
    MyVector(size_t sz, const value_type& val);
    MyVector(const MyVector& other);
    MyVector(MyVector&& other) noexcept;
    MyVector& operator=(const MyVector& other);
    MyVector& operator=(MyVector&& other) noexcept;
    ~MyVector();

    reference operator[](size_type idx);
    const reference operator[](size_type idx) const;

    reference front();
    const reference front() const;
    
    reference back();
    const reference back() const;

    reference at(size_type pos);
    const reference at(size_type pos) const;

    pointer begin();
    const pointer begin() const;
    
    pointer end();
    const pointer end() const;

    bool empty() const;
    
    size_type size_() const;
    
    size_type capacity_() const;

    void clear();
    
    void push_back(const reference value);
    void push_back(T&& value);
    
    void pop_back();
    
    pointer insert(size_type pos, const value_type& value);
    
    pointer erase(size_type pos);
    
    void swap(MyVector& other);
};


template<typename T> bool operator==(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator!=(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator<(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator>(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator<=(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator>=(const MyVector<T>& obj1, const MyVector<T>& obj2);

#endif

