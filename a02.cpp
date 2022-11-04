// { autofold
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
// }

struct coord {
    double lat, lon;
};
 
std::istream& operator>>(std::istream& is, coord& p){ 
    return is >> p.lat >> p.lon; 
}
 
bool operator<(const coord& p1, const coord& p2){ 
    return p1.lat < p2.lat; 
}
 
bool rem(const coord& p){ 
    return p.lon < 0 || p.lat < 0; 
}
 
int main(){
    using namespace std;
    ifstream in("border.txt");
    istream_iterator<coord> is(in), es;
    vector<coord> c; 
    copy(is, es, back_inserter(c));
    cout << c.size() << '\n';
    vector<coord>::iterator it = remove_if(c.begin(), c.end(), rem);
    c.erase(it, c.end());
    it = max_element(c.begin(), c.end());
    if(it != c.end()) 
        cout << "sjever: " << it->lat << endl;
    it = min_element(c.begin(), c.end());
    if(it != c.end()) 
        cout << "jug: " << it->lat << endl;
}
