// big.cpp
#include <bits/stdc++.h>
using namespace std;

struct Big {
    static const int MAX_DIGITS = 1000; // !!
    int n[MAX_DIGITS];
    Big() {
        memset(n, 0, sizeof(n));
    }
    inline void operator = (int n) {
        this->n[0] = 0;
        while (n) {
            this->n[++this->n[0]] = n % 10;
            n /= 10;
        }
    }
    inline void operator = (Big b) {
        for (int i = 0; i <= b.n[0]; ++i) {
            this->n[i] = b.n[i];
        }
    }
    inline Big operator + (Big b) {
        int i, t = 0;
        Big c;
        for (i = 1; i <= this->n[0] || i <= b.n[0] || t > 0; ++i, t /= 10) {
            c.n[i] = (t += this->n[i] + b.n[i]) % 10;
        }
        c.n[0] = i - 1;
        return c;
    }
    inline Big operator * (int b) {
        int i, t = 0;
        Big c;
        for (i = 1; i <= this->n[0] || t > 0; ++i, t /= 10) {
            c.n[i] = (t += this->n[i] * b) % 10;
        }
        c.n[0] = i - 1;
        return c;
    }
    inline void print() {
        for (int i = this->n[0]; i >= 1; --i) {
            cout << this->n[i];
        }
    }
};

Big a, b;

int main() {
    a = 135;
    b = 10;
    a = a + b * 2;
    a.print();
}
