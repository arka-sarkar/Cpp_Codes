#include<iostream>
using namespace std;

template <class T>
class Vector{
    public:
        T* arr;
        int size;
        Vector(int size) {
            this->size = size;
            arr = new T[size];
        }

        T dotProduct(Vector& v) {
            T sum = 0;
            for(size_t i = 0; i < size; i++) sum += (arr[i]*v.arr[i]);
            return sum;
        }
};

int main() {
    Vector<float> v1(3);
    v1.arr[0] = 1.4;
    v1.arr[1] = 3.3;
    v1.arr[2] = 0.1;

    Vector<float> v2(3);
    v2.arr[0] = 0.4;
    v2.arr[1] = 1.9;
    v2.arr[2] = 4.1;

    cout << v1.dotProduct(v2) << endl;
    return 0;
}