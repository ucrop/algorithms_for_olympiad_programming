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
    int n = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = nxt();
    }
    sort(all(a));
    
    int k = nxt();
    while (k--) {
        int l = nxt(), r = nxt();
        cout << upper_bound(all(a), r) - lower_bound(all(a), l) << '\n';
    }
}
