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
 
int main() { 
 
    double c;
    cin >> c;
 
    auto f = [c](double x) {
        return x * x + sqrt(x) - c;
    };
 
    double l = 0, r = 1e5;
    for (int i = 0; i < 200; i++) {
        double md = (l + r) / 2;
        if (f(md) >= 0) {
            r = md;
        } else {
            l = md;
        }
    }
 
    cout << setprecision(16) << l;
}
