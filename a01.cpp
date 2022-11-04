#include <iostream>

namespace oop {

class size {
public:
    int x, y;
    size(int x, int y) : x(x), y(y) {}
};

class rect {
public:
    int left, top, right, bottom;
    rect(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}

    void operator+=(const size& s) {
        left += s.x; right += s.x; top += s.y; bottom += s.y;
    }

    rect operator&(const rect& r) const {
        return rect(std::max(left, r.left), std::max(top, r.top), std::min(right, r.right), std::min(bottom, r.bottom));
    }
};

std::ostream& operator<<(std::ostream& os, const rect& r) {
    return os << '(' << r.left << ',' << r.top << ',' << r.right << ',' << r.bottom << ')';
}

} // namespace

int main() {
    oop::rect r1(0, 0, 50, 50), r2(50, 50, 100, 100);
    r1 += oop::size(10, 10); // offset rect
    std::cout << (r1 & r2); // print intersection
}
