#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include <cassert>
#include <algorithm>
#include <initializer_list>
#include <memory>

template <typename T>
class MyVector {
public:
    using value_type = T;
    using size_type = size_t;
    
    using pointer = T*;
    using reference = T&;

    class Iterator;
    class ConstIterator;
    class ReverseIterator; 
   

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

    pointer data_() noexcept;
    const pointer data_() const noexcept;
    

    Iterator begin();
    ConstIterator begin() const;
    
    Iterator end();
    ConstIterator end() const;

    ReverseIterator rbegin();
    ReverseIterator rend();

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


class Iterator{
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;
    private:
        pointer ptr;

    public:
        Iterator(pointer pt) : ptr{pt} {}
        reference operator*() {
            return *ptr;
        }
        pointer operator->() {
            return ptr;
        }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++ptr;
            return  tmp;
        }

        Iterator& operator--() {
            --ptr;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --ptr;
            return  tmp;
        }

	bool operator==(const Iterator& other) const {
	       	return ptr == other.ptr; 
	}

        bool operator!=(const Iterator& other) const { 
		return ptr != other.ptr; 
	}
};

class ConstIterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;
    private:

	pointer ptr;
    public:

        ConstIterator(const pointer pt) : ptr(pt) {}
        ConstIterator(const Iterator& it) : ptr(it.operator->()) {}

        const T& operator*() const {
	       	return *ptr; 
	}
        const T* operator->() const { 
		return ptr; 
	}

        ConstIterator& operator++() { 
		++ptr; 
		return *this; 
	}
        ConstIterator operator++(int) { 
		ConstIterator tmp = *this; 
		++ptr; 
		return tmp; 
	}
        ConstIterator& operator--() { 
		--ptr; return *this; 
	}
        ConstIterator operator--(int) { 
		ConstIterator tmp = *this; 
		--ptr; 
		return tmp; 
	}

        bool operator==(const ConstIterator& other) const { 
		return ptr == other.ptr; 
	}
        bool operator!=(const ConstIterator& other) const { 
		return ptr != other.ptr; 
	}
    };


template <typename Iterator>
class MoveIterator {
public:

    using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;
    using value_type        = typename std::iterator_traits<Iterator>::value_type;
    using difference_type   = typename std::iterator_traits<Iterator>::difference_type;
    using pointer = typename std::iterator_traits<Iterator>::pointer;
    using reference = typename std::iterator_traits<Iterator>::reference;

private:
    Iterator it;

public:
    explicit MoveIterator(Iterator i) : it{i} {}
    MoveIterator& operator++() {
        ++it;
        return *this;
    }
    MoveIterator operator++(int) {
        MoveIterator tmp = * this;
        ++it;
        return tmp;
    }

    MoveIterator& operator--() {
        --it;
        return *this;
    }
    MoveIterator operator--(int) {
        MoveIterator tmp = * this;
        --it;
        return tmp;
    }
    pointer operator-> () {
        return it.operator->();
    }
    reference operator*() {
        return std::move(*it);
    }

    bool operator==(const MoveIterator& other) const{
        return it == other.it;
    }
    bool operator!=(const MoveIterator& other) const {
        return it != other.it;
    }
};

};


template<typename T> bool operator==(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator!=(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator<(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator>(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator<=(const MyVector<T>& obj1, const MyVector<T>& obj2);
template<typename T> bool operator>=(const MyVector<T>& obj1, const MyVector<T>& obj2);

#include "vector.tpp"
#endif

