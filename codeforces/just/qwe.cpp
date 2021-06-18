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
  
const ll MAX_N = 2e5 + 5, inf = 1e18;
const double PI = 3.1415926536;
int days[13] = {0, 31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
  
template<typename T>
ostream& operator <<(ostream& out, const vector<T>& mas) {
    for (const auto& x : mas) {
        out << x << ' ';
    }
    return out;
}
 
ll vec_mult(const pll & t1, const pll & t2, const pll & t3) {
    const ll & x1 = t1.first, y1 = t1.second;
    const ll & x2 = t2.first, y2 = t2.second;
    const ll & x3 = t3.first, y3 = t3.second;
    return abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
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
 
void solve() {
    int n = nxt();
    vector<set<int>> st(n);
    vector<set<int>> st1(n);
    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    vector<set<int>> g(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '=') {
                g[i].insert(j);
            }
            if (matrix[i][j] == '>') {
                g[j].insert(i);
            }
            if (matrix[i][j] == '<') {
                g[i].insert(j);
            }
        }
    }

    int x = 1;
    vector<int> mark(n);

    auto bfs = [&](int i, int x) {
        queue<int> q;
        q.push(i);
        vector<int> used(n);
        while (q.size()) {

            int v = q.front();
            q.pop();
            if (used[v]) {
                continue;
            }

            st[v].insert(x);
            used[v] = true;
            mark[v] = true;
            for (auto& u : g[v]) {
                if (!used[u]) {
                    q.push(u);
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == '!') {
                if (!mark[i]) {
                    bfs(i, i + 1);
                } 
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[j][i] == '^') {
                if (!mark[i]) {
                    bfs(i, i + 1);
                } 
            }
        }
    }
     
    for (auto& x : st) { 
        for (auto& y : x) {
            if (y > n) {
                cout << "No\n";
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == '^' || matrix[i][i] == '!') {
            cout << "No\n";
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '=') {
                if (st[i] != st[j]) {
                    cout << "No";
                    return;
                }
            }

            if (matrix[i][j] == '<') {
                for (auto& x : st[i]) {
                    if (!st[j].count(x)) {
                        cout << "No";
                        return;
                    }
                }
            }

            if (matrix[i][j] == '>') {
                for (auto& x : st[j]) {
                    if (!st[i].count(x)) {
                        cout << "No";
                        return;
                    }
                }
            }

            if (matrix[i][j] == '!') {
                bool f = false;
                for (auto& x : st[i]) {
                    if (!st[j].count(x)) {

                        f = true;
                        break;
                    }
                }
                if (!f) {
                    cout << "No\n";
                    return;
                }
            }

            if (matrix[i][j] == '^') {
                bool f = false;
                for (auto& x : st[j]) {
                    if (!st[i].count(x)) {
                        f = true;
                        break;
                    }
                }
                if (!f) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    cout << "Yes\n";
    for (auto& x : st) {
        cout << x.size() << ' ';
        for (auto& y : x) {
            cout << y << ' ';
        }
        cout << endl;
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
