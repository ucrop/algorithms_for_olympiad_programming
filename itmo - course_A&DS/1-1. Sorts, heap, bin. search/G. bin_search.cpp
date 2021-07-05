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
 
    int n = nxt(), x = nxt(), y = nxt();
    
    auto f = [&](int md) {
        int first = min(x, y);
        md -= first;
        if (md < 0) {
            return 0;
        } else {
            return md / x + md / y + 1;
        }
    };
 
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int md = (r + l) / 2;
        if (f(md) >= n) {
            r = md;
        } else {
            l = md;
        }
    }
 
    if (f(l) >= n) {
        r = l;
    }
 
    cout << r;
}
