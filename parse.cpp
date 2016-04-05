// parse.cpp
#include <bits/stdc++.h>
using namespace std;

struct Parse {
    static const int SIZE = 1 << 20;
    int i, sign;
    char b[SIZE];
    Parse() {
        i = SIZE;
        sign = 1;
    }
    inline void init() {
        fread(b, 1, SIZE, stdin);
        i = 0;
    }
    inline bool is_digit(const char &x) {
        if (x >= '0' && x <= '9') {
            return true;
        }
        if (x == '-') {
            return true;
        }
        return false;
    }
    inline Parse operator >> (int &n) {
        n = 0;
        if (i == SIZE) {
            init();
        }
        while (!is_digit(b[i])) {
            ++i;
            if (i == SIZE) {
                init();
            }
        }
        if (b[i] == '-') {
            sign = -1;
            ++i;
        } else {
            sign = 1;
        }
        while (is_digit(b[i])) {
            n = n * 10 + b[i] - '0';
            ++i;
            if (i == SIZE) {
                init();
            }
        }
        n = n * sign;
        return (*this);
    }
};

int main() {
/*
#ifdef ONLINE_JUDGE
    Parse cin;
#endif
*/
    // freopen("input", "r", stdin); // this should be commented
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        cout << x << ' ';
    }
    cout << '\n';
}
