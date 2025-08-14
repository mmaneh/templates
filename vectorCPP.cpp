#include <exception>
#include <cassert>
#include <algorithm>
#include <iostream>
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
        MyVector() :  size{0}, capacity{0},data{nullptr} {}
        MyVector(size_type sz) : size{sz},  capacity{sz} {
            data = new value_type[size];
            
        }
        MyVector(size_t sz, const size_type val) : size{sz}, capacity{sz} {
            data = new value_type[size];
            for(size_type i = 0; i < size; ++i ) {
                data[i] = val;
            }
        }
        MyVector(const MyVector& other) : size{other.size}, capacity{other.capacity} {
            data = new value_type[size];
            for(size_type i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        MyVector(MyVector&& other) noexcept : size{other.size},capacity{other.capacity}, data{other.data} {
            other.size = 0;
            other.capacity = 0;
            other.data = nullptr;
        }
        MyVector& operator=(const MyVector& other) {
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
        MyVector& operator= (MyVector&& other) noexcept  {
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
        ~MyVector() {
            delete[] data;
        }
        reference operator[] (size_type idx) {
            assert(idx < size);
            return data[idx];
        }
        const reference operator[](size_type idx) const {
            return data[idx];
        }
        reference front() {
            assert(size > 0);
            return data[0];
        }
        const reference front() const {
            assert(size > 0);
            return data[0];
        }
        reference back() {
            assert(size > 0);
            return data[size - 1];
        }
        const reference back() const {
            assert(size > 0);
            return data[size - 1];
        }
        reference at(size_type pos) {
            if(pos >= size) {
                throw std::out_of_range("out of range");
            }  
            return data[pos];
        }
        const reference at(size_type pos) const {
            if(pos >= size) {
                throw std::out_of_range("out of range");
            }  
            return data[pos];
        }
        pointer begin() {
            return data;
        }
        const pointer begin() const {
            return data;
        }
        pointer end() {
            return data + size;
        }
        const pointer end() const {
            return data + size;
        }
        bool empty() const {
            return size == 0;
        }
        size_type size_() {
            return size;
        }
        size_type capacity_() {
            return capacity;
        }
       
        void clear() {
            size = 0;
        }
        void push_back(const reference value) {
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
            data[size++] = value;
        }
        void push_back(T&& value) {
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
            data[size++] = value;
        }
        void pop_back() {
            assert(size < capacity);
            --size;
        }
        pointer insert(size_type pos, size_type value) {
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
            }else {
                for (size_type i = pos; i < size; ++i) {
                    data[i + 1] = data[i];
                }
                data[pos] = value;
                ++size;
            }
            return &data[pos];
        }
        pointer erase(size_type pos) {
            if(pos > size) throw std::out_of_range("out of range");
            for (size_type i = pos; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            --size;
            return &data[pos];
        }
        void swap(MyVector& other) {
            std::swap(data, other.data);
            std::swap(size, other.size);
            std::swap(capacity, other.capacity);
        }
    friend bool operator==(const MyVector& obj1, const MyVector& obj2);
    friend bool operator!=(const MyVector& obj1, const MyVector& obj2);

    friend bool operator<(const MyVector& obj1, const MyVector& obj2);

    friend bool operator<=(const MyVector& obj1, const MyVector& obj2);

    friend bool operator>(const MyVector& obj1, const MyVector& obj2);

    friend bool operator>=(const MyVector& obj1, const MyVector& obj2);
    };
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
        return std::lexicographical_compare(obj1.begin(), obj1.end(),
                                obj2.begin(), obj2.end());
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
int main() {
    MyVector<int> vec;
    vec.push_back(5);
    std::cout << vec.size_() << std::endl;
    vec.insert(2, 7);
    for (int i = 0; i < vec.size_(); ++i) {
        std::cout << vec[i] << std::endl;
    }
}
