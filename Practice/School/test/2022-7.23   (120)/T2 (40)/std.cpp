#include <iostream>
#include <cstring>
using namespace std;
int t, k;
int c[2010][2010];
int s[2010][2010];

void pre()
{
    memset(s, -1, sizeof(s));
    c[0][0] = 1;
    s[0][0] = 0;
    c[1][0] = c[1][1] = 1; // 加上初始化，绝对绝对不能忘记或错，结合常识。
    s[1][0] = s[1][1] = 0; // 1不能被任何数整除

    for (int i = 2; i <= 2000; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) // 打出题目要的范围即可。
        {
            c[i][j] = (c[i - 1][j - 1] % k + c[i - 1][j] % k) % k; // 递推公式。
            s[i][j] = (s[i - 1][j] == -1 ? 1 : s[i - 1][j]) + (s[i][j - 1] == -1 ? 1 : s[i][j - 1]) - (s[i-1][j-1] == -1 ? 1 : s[i-1][j-1]) + (int)(c[i][j] == 0);
            cout << '(' << i << ',' << j << ')' << (s[i - 1][j] == -1 ? 1 : s[i - 1][j]) << ' ' << (s[i][j - 1] == -1 ? 1 : s[i][j - 1]) << ' ' << (s[i-1][j-1] == -1 ? 1 : s[i-1][j-1]) << ' ' << (int)(c[i][j] == 0) << '=' << s[i][j]<< endl;
        }
    }
}

int main()
{
    freopen("problem.in", "r", stdin);
    // freopen("problem.out","w",stdout);
    cin >> t >> k;
    pre();
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << s[m][n] << endl;
    }
}