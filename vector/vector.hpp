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
    MyVector() noexcept;
    explicit MyVector(size_t sz, const value_type& val = T());
    MyVector(const MyVector& other);
    MyVector(MyVector&& other) noexcept;
    MyVector(const std::initializer_list<T> &il);

    MyVector& operator=(const MyVector& other);
    MyVector& operator=(MyVector&& other) noexcept;
    MyVector& operator=(const std::initializer_list<T> &il);
    ~MyVector();

    reference operator[](size_type idx);
    const reference operator[](size_type idx) const;

    reference front();
    const reference front() const;
    
    reference back();
    const reference back() const;

    reference at(size_type pos);
    const reference at(size_type pos) const;

    pointer data_();
    const pointer data_() const noexcept;

    pointer begin();
    pointer begin() const;
    
    pointer end();
    pointer end() const;

    bool empty() const;
    
    size_type size_() const;
    
    size_type capacity_() const;

    void reserve(size_type newCap);

    void clear();
       
    void insert(size_type pos, const value_type& value);
    void insert(size_type pos, T&& value);
    void insert(size_type pos, size_type count, const value_type& val);
    
    template <typename ... Args>
    void emplace(size_type pos, Args&& ...args);
    pointer erase(size_type pos);
    pointer erase(size_type first, size_type last);
    void push_back(const reference value);
    void push_back(T&& value);
    
    template <typename ... Args>
    void emplace_back(Args && ... args);
    void resize (size_type count, const value_type& val = T());
    void swap(MyVector& other);
    void pop_back();
};


template<typename T> bool operator==(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator!=(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator<(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator>(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator<=(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator>=(const MyVector<T>& obj1, const MyVector<T>& obj2);

#endif

