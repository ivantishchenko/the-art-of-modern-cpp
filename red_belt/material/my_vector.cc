#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class SimpleVector {
public:
    explicit SimpleVector(size_t size) {
        data = new T[size];
        end_ = data + size;
    }
    ~SimpleVector() {
        delete[] data;
    }
    T& operator[](size_t index) {
        return data[index];
    }
    const T* begin() const {
        return data;
    }
    const T* end() const {
        return end_;
    }
    T* begin() {
        return data;
    }
    T* end() {
        return end_;
    }
private:
    T* data;
    T* end_;
};

template <typename T>
void Print(const SimpleVector<T>& v) {
    for(const auto &x: v) {
        cout << x << ' ';
    }
}

int main() {
    SimpleVector<int> sv(5);
    
    cout << sv[12] << endl;

    for(int i = 0; i < 5; ++i) {
        sv[i] = 5 - i;
    }

    for(int x : sv) {
        cout << x << ' ';
    }

    cout << endl;    

    Print(sv);

    return 0;
}
