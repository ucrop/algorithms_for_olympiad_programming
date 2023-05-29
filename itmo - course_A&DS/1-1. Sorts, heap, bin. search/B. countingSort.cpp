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


const int MAX_N = 101;
vector<int> countingSort(const vector<int>& v) {
    vector<int> cnt(MAX_N);
    for (auto& x : v) {
        cnt[x]++;
    }
    vector<int> answer;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            answer.push_back(i);
        }
    }
    return answer;
}

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    int n = nxt();
    vector<int> a(n);
    generate(all(a), nxt);
    cout << countingSort(a);
}
