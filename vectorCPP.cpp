#include <exception>
#include <cassert>
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
        value_type* data;
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
                other.cpacity = 0;
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

};
