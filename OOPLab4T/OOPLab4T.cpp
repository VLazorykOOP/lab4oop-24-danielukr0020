﻿#include <iostream>

class MyVector
{
    static int objectCount;
    short* a;
    int size;
    int value;
    int errorCode;

public:
    enum ErrorCodes {
        NO_ERROR = 0,
        OUT_OF_MEMORY,
        INDEX_OUT_OF_RANGE
    };

    int getErrorCode() const {
        return errorCode;
    }

    static int getObjectCount() {
        return objectCount;
    }


    MyVector() : size(1) {
        a = new short[size];
        a[0] = 0;
        ++objectCount;
    }
    MyVector(int Size) : size(Size), value(0) {
        a = new short[Size];
        for (int i = 0; i < Size; i++) {
            a[i] = value;
        }
        ++objectCount;
    }
    MyVector(int Size, int Value) : size(Size), value(Value), errorCode(NO_ERROR) {
        a = new short[Size];
        if (a == nullptr) {
            errorCode = OUT_OF_MEMORY;
            return;
        }
        for (int i = 0; i < Size; i++) {
            a[i] = value;
        }
        ++objectCount;
    }
    ~MyVector() {
        delete[] a;
        --objectCount;
    }
    MyVector(const MyVector& other) : size(other.size), errorCode(NO_ERROR) {
        a = new short[size];
        if (a == nullptr) {
            errorCode = OUT_OF_MEMORY;
            return;
        }
        for (int i = 0; i < size; i++) {
            a[i] = other.a[i];
        }
        ++objectCount;
    }


    int get_Size() const {
        return size;
    }


    //          
    MyVector operator=(const MyVector& b) const {
        for (int i = 0; i < size; i++)
        {
            a[i] = b.a[i];
        }
        return *this;
    }
    MyVector operator+=(const MyVector& b) const {
        for (int i = 0; i < size; i++)
        {
            a[i] += b.a[i];
        }
        return *this;
    }
    MyVector operator-=(const MyVector& b) const {
        for (int i = 0; i < size; i++)
        {
            a[i] -= b.a[i];
        }
        return *this;
    }
    MyVector operator*=(const short b) const {
        for (int i = 0; i < size; i++)
        {
            a[i] *= b;
        }
        return *this;
    }
    MyVector operator/=(const short b) const {
        for (int i = 0; i < size; i++)
        {
            a[i] /= b;
        }
        return *this;
    }
    MyVector operator%=(const short b) const {
        for (int i = 0; i < size; i++)
        {
            a[i] %= b;
        }
        return *this;
    }


    //                   
    MyVector operator+(const MyVector& b) const {
        MyVector temp(size);
        for (int i = 0; i < size; i++)
            temp.a[i] = a[i] + b.a[i];
        return temp;
    }
    MyVector operator-(const MyVector& b) const {
        MyVector temp(size);
        for (int i = 0; i < size; i++)
            temp.a[i] = a[i] - b.a[i];
        return temp;
    }
    MyVector operator*(const MyVector& b) const {
        MyVector temp(size);
        for (int i = 0; i < size; i++)
            temp.a[i] = a[i] * b.a[i];
        return temp;
    }
    MyVector operator/(const MyVector& b) const {
        MyVector temp(size);
        for (int i = 0; i < size; i++)
            temp.a[i] = a[i] / b.a[i];
        return temp;
    }
    MyVector operator%(const MyVector& b) const {
        MyVector temp(size);
        for (int i = 0; i < size; i++)
            temp.a[i] = a[i] % b.a[i];
        return temp;
    }

    //                          
    MyVector operator++() const {
        MyVector temp(*this);
        for (int i = 0; i < size; i++)
        {
            ++a[i];
        }
        return *this;
    }
    MyVector operator--() const {
        MyVector temp(*this);
        for (int i = 0; i < size; i++)
        {
            --a[i];
        }
        return *this;
    }
    MyVector operator++(int) const {
        MyVector temp(*this);
        for (int i = 0; i < size; i++)
        {
            a[i]++;
        }
        return *this;
    }
    MyVector operator--(int) const {
        MyVector temp(*this);
        for (int i = 0; i < size; i++)
        {
            a[i]--;
        }
        return *this;
    }


    //                   
    bool operator==(const MyVector& b) const {
        if (size != b.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (a[i] != b.a[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const MyVector& b) const {
        if (size != b.size) {
            return true;
        }
        for (int i = 0; i < size; ++i) {
            if (a[i] == b.a[i]) {
                return false;
            }
        }
        return true;
    }


    //             
    MyVector operator|(const MyVector& b) const {
        MyVector temp(size);
        for (int i = 0; i < size; ++i) {
            temp.a[i] = a[i] | b.a[i];
        }
        return temp;
    }
    MyVector operator^(const MyVector& b) const {
        MyVector temp(size);
        for (int i = 0; i < size; ++i) {
            temp.a[i] = a[i] ^ b.a[i];
        }
        return temp;
    }
    MyVector operator&(const MyVector& b) const {
        MyVector temp(size);
        for (int i = 0; i < size; ++i) {
            temp.a[i] = a[i] & b.a[i];
        }
        return temp;
    }


    //          
    bool operator>(const MyVector& b) const {
        if (size != b.size) {
            return true;
        }
        for (int i = 0; i < size; ++i) {
            if (a[i] > b.a[i]) {
                return true;
            }
        }
        return false;
    }
    bool operator<(const MyVector& b) const {
        if (size != b.size) {
            return true;
        }
        for (int i = 0; i < size; ++i) {
            if (a[i] < b.a[i]) {
                return true;
            }
        }
        return false;
    }
    bool operator>=(const MyVector& b) const {
        if (size != b.size) {
            return true;
        }
        for (int i = 0; i < size; ++i) {
            if (a[i] >= b.a[i]) {
                return true;
            }
        }
        return false;
    }
    bool operator<=(const MyVector& b) const {
        if (size != b.size) {
            return true;
        }
        for (int i = 0; i < size; ++i) {
            if (a[i] <= b.a[i]) {
                return true;
            }
        }
        return false;
    }


    // >> <<
    friend std::istream& operator>>(std::istream& is, MyVector& b) {
        for (int i = 0; i < b.size; i++)
        {
            is >> b.a[i];
        }
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, MyVector& b) {
        for (int i = 0; i < b.size; i++)
        {
            os << b.a[i];
        }
        return os;
    }


    // new delete
    void* operator new(size_t size) {
        return ::operator new(size);
    }
    void operator delete(void* ptr) {
        ::operator delete(ptr);
    }


    // []
    short& operator[](int index) {
        return a[index];
    }
    void printinfo() {
        for (int i = 0; i < size; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
};
int MyVector::objectCount = 0;

int main() {
    // Create MyVector objects
    MyVector v1(3, 5); // Vector of size 3 with value 5
    MyVector v2(3, 7); // Vector of size 3 with value 7
    std::cout << "v1: ";
    v1.printinfo();
    std::cout << "v2: ";
    v2.printinfo();

    // Check object count
    std::cout << "\nObject count: " << MyVector::getObjectCount() << std::endl;

    v1 += v2;
    v2 -= v1;

    std::cout << "v1 += v2: ";
    v1.printinfo();
    std::cout << "v2 -= v1: ";
    v2.printinfo();

    std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
    std::cout << "v1 != v2: " << (v1 != v2) << std::endl;
    std::cout << "v1 > v2: " << (v1 > v2) << std::endl;
    std::cout << "v2 <= v1: " << (v2 <= v1) << std::endl;

    MyVector v3 = v1 * v2;
    MyVector v4 = v1 / v2;

    std::cout << "\nv3 = v1 * v2: ";
    v3.printinfo();
    std::cout << "v4 = v1 / v2: ";
    v4.printinfo();

    MyVector v5 = v1 ^ v2;
    MyVector v6 = v1 | v2;

    std::cout << "\nv5 = v1 ^ v2: ";
    v5.printinfo();
    std::cout << "v6 = v1 | v2: ";
    v6.printinfo();

    std::cout << "\nObject count after destruction: " << MyVector::getObjectCount() << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

class AssocArray {
private:
    std::vector<std::string> keys;
    std::vector<std::string> values;
    int errorCode;

public:
    AssocArray() : errorCode(-1) {}

    void addEntity(const std::string& key, const std::string& value) {
        keys.push_back(key);
        values.push_back(value);
    }

    std::string& operator[](const std::string& key) {
        for (size_t i = 0; i < keys.size(); ++i) {
            if (keys[i] == key) {
                errorCode = -1;
                return values[i];
            }
        }
        errorCode = 404;
        static std::string emptyString;
        return emptyString;
    }

    friend std::ostream& operator<<(std::ostream& out, const AssocArray& arr) {
        for (size_t i = 0; i < arr.keys.size(); ++i) {
            out << arr.keys[i] << " : " << arr.values[i] << std::endl;
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, AssocArray& arr) {
        std::string key, value;
        std::cout << "Enter key: ";
        in >> key;
        std::cout << "Enter value: ";
        in >> value;
        arr.addEntity(key, value);
        return in;
    }

    int getErrorCode() const {
        return errorCode;
    }
};

int main() {
    AssocArray myAssocArray;

    myAssocArray.addEntity("example.com", "192.168.1.1");
    myAssocArray.addEntity("google.com", "172.217.168.78");

    std::cout << "IP address of example.com: " << myAssocArray["example.com"] << std::endl;
    std::cout << "IP address of non-existing domain: " << myAssocArray["nonexistent.com"] << std::endl;

    if (myAssocArray.getErrorCode() == 404) {
        std::cout << "Error: Domain not found" << std::endl;
    }

    std::cin >> myAssocArray;

    std::cout << "Associative array:" << std::endl;
    std::cout << myAssocArray;

    return 0;
}
