#include <iostream>
using namespace std;

/* 铺垫: qpow 快速幂 */

int qpow(int n, int k)
{
    int ans = 1;
    while (k)
    {
        if (k & 1)    //如果n的当前末位为1
            ans *= n; // ans乘上当前的a
        n *= n;       // a自乘
        k >>= 1;      // n往右移一位
    }
    return ans;
}

int main()
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    int ans = 1;
    int a = 10;
    while (k)
    {
        if (k & 1)
            ans *= a;
        ans %= n;   // %n
        a *= a;
        a %= n;     // %n
        k >>= 1;
    }

    cout<<(x+(m%n)*ans)%n;
}