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

template<class T>
class PriorityQueue {
public:

    PriorityQueue() = default;

    void push(const T& elem) {
        _buf.push_back(elem);

        size_t v = _buf.size() - 1;
        while (v > 0) {
            size_t p = (v - 1) / 2;
            if (_buf[p] > _buf[v]) {
                swap(_buf[p], _buf[v]); 
            }
            v = p;
        }
    }

    T top() {
        if (_buf.size() == 0) {
            throw "empty queue";
        }
        return _buf[0];
    }

    T pop() {
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
            if (left < _buf.size() - 1 && _buf[left] < _buf[j]) {
                j = left;
            }
            if (right < _buf.size() - 1 && _buf[right] < _buf[j]) {
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


template<class T>
void heapSort(vector<T>& v) {
    PriorityQueue<T> pq;
    for (auto& x : v) {
        pq.push(x);
    }

    vector<T> answer;
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(pq.pop());
    }
    v = answer;
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
    heapSort(a);
    cout << a;
}