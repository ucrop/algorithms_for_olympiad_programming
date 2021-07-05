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

template<class InputIt, class OutputIt>
ll merge(InputIt first1, InputIt last1,
               InputIt first2, InputIt last2,
               OutputIt d_first)
{
    int len_suffix_first = last1 - first1;
    int len_prefix_second = 1;
    ll answer = 0;
    
    for (; first1 != last1; ++d_first) {
        if (first2 == last2) {
            std::copy(first1, last1, d_first);
            return answer;
        }
        if (*first2 < *first1) {
            *d_first = *first2;
            answer += len_suffix_first;
            len_prefix_second++;
            ++first2;
        } else {
            *d_first = *first1;
            len_suffix_first--;
            ++first1;
        }
    }
    std::copy(first2, last2, d_first);
    return answer;
}

template<typename RandomIt>
ll MergeSort(RandomIt range_begin, RandomIt range_end) {
    const int range_length = range_end - range_begin;
    if (range_length < 2) {
        return 0LL;
    }
    
    vector<typename RandomIt::value_type> elements(
        make_move_iterator(range_begin), make_move_iterator(range_end));
        
    auto mid = begin(elements) + range_length / 2;
    
    ll sum1 = MergeSort(begin(elements), mid) + MergeSort(mid, end(elements));
    ll sum2 = merge(
        make_move_iterator(begin(elements)), make_move_iterator(mid),
        make_move_iterator(mid), make_move_iterator(end(elements)),
        range_begin
    );
    
    return sum1 + sum2;
}

int main() {
    int n = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = nxt();
    }
    
    cout << MergeSort(begin(a), end(a));
}
