#include <bits/stdc++.h>

#define itn int
#define all(c) c.begin(),c.end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define ll long long
#define ull unsigned long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
using namespace std; 

template<typename T>
ostream& operator <<(ostream& out, const vector<T>& mas) {
    for (const auto& x : mas) {
        out << x << ' ';
    }
    return out;
}

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

struct Point {
    Point (double _x, double _y) : 
        x(_x), y(_y) {}
    
    double x, y;
};

double find_dist(Point p1, Point p2) {
    double rx = abs(p1.x - p2.x);
    double ry = abs(p1.y - p2.y);
    return sqrt(rx * rx + ry * ry);
}

int main() {
    int v1 = nxt(), v2 = nxt();
    double a;
    cin >> a;
    
    auto getSumDist = [v1, v2, a](double x) {
        double first_polyline = find_dist(Point(0, 1), Point(x, a));
        double second_polyline = find_dist(Point(x, a), Point(1, 0));
        return first_polyline / v1 + second_polyline / v2; 
    };

    double l = 0, r = 1;
    for (int i = 0; i < 200; i++) {
        double a = (l * 2 + r) / 3;
        double b = (l + r * 2) / 3;
        
        double d1 = getSumDist(a);
        double d2 = getSumDist(b);
        if (d1 < d2) {
            r = b;
        } else {
            l = a;
        }
    }
    cout << setprecision(16) << l;
}
