// { autofold
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <iterator>
#include <fstream>
#include <algorithm>
// }

struct student {
    std::string name, surname;
    int grade;
};

std::istream& operator>>(std::istream& is, student& s) {
    return is >> s.name >> s.surname >> s.grade;
}

std::ostream& operator<<(std::ostream& os, const student& s) {
    return os << s.name << '\t' << s.surname << '\t' << s.grade;
}

bool operator<(const student& s1, const student& s2) {
    return s1.grade > s2.grade;
}

bool small(const student& s) {
    return islower(s.name[0]) || islower(s.surname[0]);
}

student limit(student s) {
    s.grade = std::clamp(s.grade, 1, 5);
    return s;
}

class avg {
    double sum = 0; 
    int cnt = 0;
public:
    void operator()(const student& s) { ++cnt; sum += s.grade; }
    operator double() { return cnt ? sum / cnt : 0; }
};

int main() {
    using namespace std;
    vector<student> v;
    ifstream f("studenti.txt");
    istream_iterator<student> is(f), es;
    copy(is, es, back_inserter(v));
    v.erase(remove_if(v.begin(), v.end(), small), v.end());
    transform(v.begin(), v.end(), v.begin(), limit);
    sort(v.begin(), v.end());
    ostream_iterator<student> os(cout, "\n");
    copy(v.begin(), v.end(), os);
    cout << setprecision(3) << "prosjek ocjena: " << for_each(v.begin(), v.end(), avg()) << '\n';
}
