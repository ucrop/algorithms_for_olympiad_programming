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

ll binarySearchApprox(const vector<ll>& arr, ll d) {
    int l = 0, r = arr.size() - 1;

    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (arr[mid] < d) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    if (abs(d - arr[l]) <= abs(d - arr[r])) {
        return arr[l];
    } else {
        return arr[r];
    }
}

int main() {
    int n = nxt(), k = nxt();
    vector<ll> a(n);
    generate(all(a), nxt);
    while (k--) {
        ll d = nxt();
        cout << binarySearchApprox(a, d) << '\n';
    }
}
