// { autofold
#include <iostream>
#include <list>
#include <algorithm>
// }

class shape {
public:
    virtual double area() const = 0;
    virtual ~shape() = 0;
};

shape::~shape() {}

class circle : public shape {
    double r;
public:
    circle(double r) : r(r) {}
    double area() const override { return r * r * 3.14; }
};

class square : public shape {
    double a;
public:
    square(double a) : a(a) {}
    double area() const override { return a * a; }
};

class sum {
    double s = 0;
public:
    void operator()(shape* p) { s += p->area(); }
    operator double() { return s; }
};

template <typename T>
class del {
public:
    void operator()(T* p) { delete p; }
};

int main() {
    std::list<shape*> shapes;
    shapes.push_back(new circle(1.5));
    shapes.push_back(new square(4.));
    std::cout << "total: " << std::for_each(shapes.begin(), shapes.end(), sum()) << std::endl;
    std::for_each(shapes.begin(), shapes.end(), del<shape>());
}
