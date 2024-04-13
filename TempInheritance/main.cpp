#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;
public:
    Base(const T1& v1, const T2& v2) : value1(v1), value2(v2) {}

    void display() const {
        cout << "Base values: " << value1 << ", " << value2 << endl;
    }
};

template<typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;
public:
    Child(const T1& v1, const T2& v2, const T3& v3, const T4& v4)
        : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {}

    void display() const {
        Base<T1, T2>::display();
        cout << "Child values: " << value3 << ", " << value4 << endl;
    }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;
public:
    Child2(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6)
        : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}

    void display() const {
        Child<T1, T2, T3, T4>::display();
        cout << "Child2 values: " << value5 << ", " << value6 << endl;
    }
};

int main() {
    Base<int, float> base(10, 3.14);
    base.display();

    Child<int, float, string, char> child(20, 6.28, "Hello", 'A');
    child.display();

    Child2<int, float, string, char, double, bool> child2(30, 9.42, "World", 'B', 2.718, true);
    child2.display();

    return 0;
}
