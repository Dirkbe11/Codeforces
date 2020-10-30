
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


constexpr int MOD = 1e9 + 7;



int binPow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
 
        n >>= 1;
    }
    return res;
}

void binarySearch(int n, int x_position, int &cnt_big, int &cnt_less) {
    int left = 0, right = n;
 
    while(left < right) {
        int middle = (left + right) / 2;
        if (x_position >= middle) {
            if (x_position != middle) cnt_less++;
            left = middle + 1;
        }
        else if (x_position < middle){
            cnt_big++;
            right = middle;
        }
    }
}

int C(int n, int k, const vector <long long> &fact, const vector <long long> &inv) {
    if (k > n) return 0;
    int multiply = (1LL * fact[n] * inv[k]) % MOD;
    multiply = (1LL * multiply * inv[n - k]) % MOD;
    return multiply;
}

void BinarySearch(int n, int x, int pos)
{
    int bigX = 0;
    int smallX = 0;

    binarySearch(n, pos, bigX, smallX);


    int BigT = n-x;
    int SmallT = x-1;

    ll result = 0;


    vector <long long> fact(n + 1, 1LL);
    vector <long long> inv(n + 1, 1LL);
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = binPow(fact[i], MOD - 2);
    }

    int other = (n-bigX - smallX - 1);
    
    int countLess = C(SmallT, smallX, fact, inv);
    int countBig = C(BigT, bigX, fact, inv);

    countBig = (1LL * countBig * fact[bigX]) % MOD;
    countLess = (1LL * countLess * fact[smallX]) % MOD;

    int multiply = (1LL * countBig * countLess) % MOD;
    multiply = (1LL * multiply * fact[other]) % MOD;

    result = (result + multiply)%MOD;
    std::cout << result << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x, pos;
    cin >> n >> x >> pos;

    BinarySearch(n, x, pos);

    return 0;
}
