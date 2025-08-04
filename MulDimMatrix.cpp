#include <cstddef>
#include <iostream>
#include <vector>

template <typename T, size_t N> 
class  MultiDimMatrix {
    private:
        size_t _size;
        std::vector<MultiDimMatrix<T, N -1>> data;
    public:

       explicit  MultiDimMatrix(size_t size) :  _size{size}, data(_size, MultiDimMatrix<T, N - 1>(_size)) {} 
        ~MultiDimMatrix() = default;
        void fill(T value) {
            for(int i = 0; i < _size; ++i) {
                data[i].fill(value);
            }
        } 

        bool operator==(const MultiDimMatrix<T, N>& other) const {
            if(_size != other._size) return false;
            return data == other.data;
        }

    
        bool operator!=(const MultiDimMatrix<T, N>& other) const {
            return !(*this == other);
        }
        MultiDimMatrix<T, N - 1>& operator[](size_t index) {
            return data[index];
        }

        const MultiDimMatrix<T, N - 1>& operator[](size_t index) const {
            return data[index];
        }
  
        void apply(void (*func)(T&)) {
            for (int i = 0; i < _size; ++i) {
                data[i].apply(func);
            }
        }
        void printMatrix() {
            for(int i = 0; i < _size; ++i) {
                data[i].printMatrix();
            }
        }

};

template <typename T> 
class MultiDimMatrix<T,1> {
    private:
        size_t _size;
        std::vector<T> data;
    public: 
       explicit  MultiDimMatrix<T,1> (size_t size) : _size{size}, data(_size) {}
        T& operator[](size_t idx) {
            return data[idx];
        }
        const T& operator[](size_t idx) const {
            return data[idx];
        }
        void fill(T value) {
            for (int i = 0; i < _size; ++i) {
                data[i] = value;
            }
        }
        void apply(void (*func)(T&)) {
            for (int i = 0; i < _size; ++i) {
                func(data[i]);
            }
        }
        void printMatrix() {
            for(int i = 0; i < _size; ++i) {
                    std::cout << data[i]<< ' ';
            }
                std::cout << std::endl;
            
        }
 
};

void doubleValue(int& val) {
    val *= 2;
} 

int main() {
  
    MultiDimMatrix<int, 2> mat(3);
    mat.fill(5);
    mat.printMatrix();
    mat.apply(doubleValue);

 
    std::cout  << mat[0][0] << std::endl;
   

    
    MultiDimMatrix<int, 3> mat2(3);
    mat2.fill(4);
    mat2.apply(doubleValue);
    mat2.printMatrix();
  

    return 0;
}
    
