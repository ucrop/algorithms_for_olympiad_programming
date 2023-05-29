#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
#define itn int
#define all(c) c.begin(),c.end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define ll long long
#define ull unsigned long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
using namespace std;
 
const ll MAX_N = 2e5 + 5, inf = 1e18, mod = 1000000007;
const double PI = 3.1415926536;
int days[13] = {0, 31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
 
template<typename T>
ostream& operator <<(ostream& out, const vector<T>& mas) {
    for (const auto& x : mas) {
        out << x << ' ';
    }
    return out;
}
 
void ok() {
    cout << "YES" << '\n';
}
 
void no() {
    cout << "NO" << '\n';
}
 
inline ll nxt() {
    ll x;
    cin >> x;
    return x;
}
  
template<class T>
class Heap {
public:
 
    Heap() = default;
 
    void Insert(const T& elem) {
        _buf.push_back(elem);
 
        size_t v = _buf.size() - 1;
        while (v > 0) {
            size_t p = (v - 1) / 2;
            if (_buf[p] < _buf[v]) {
                swap(_buf[p], _buf[v]); 
            }
            v = p;
        }
    }
    
    T Extract() {
        if (_buf.size() == 0) {
            throw "empty queue";
        }
 
        T tmp = _buf[0]; 
        size_t end = _buf.size() - 1;
        swap(_buf[0], _buf[end]);
        size_t i = 0;
        while (true) {
            int j = i;
            int left = j * 2 + 1;
            int right = j * 2 + 2;
            if (left < _buf.size() - 1 && _buf[left] > _buf[j]) {
                j = left;
            }
            if (right < _buf.size() - 1 && _buf[right] > _buf[j]) {
                j = right;
            }
 
            if (i == j) {
                break;
            }
            swap(_buf[i], _buf[j]);
            i = j;
        }
        _buf.pop_back();
        return tmp;
    }
 
private:
    vector<T> _buf;
};
 
void solve() {
    Heap<int>* heap = new Heap<int>();
    
    int q = nxt();
    while (q--) {
        int type = nxt();
        if (type == 0) {
            int x = nxt();
            heap->Insert(x);
        } else {
            cout << heap->Extract() << '\n';
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
