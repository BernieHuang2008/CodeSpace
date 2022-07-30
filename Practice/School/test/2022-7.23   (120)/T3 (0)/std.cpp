#include<iostream>
using namespace std;

int n,m,d[11000];
int f[11000][550];

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    
    f[0][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i, m);j++)
            f[i][0] = max(f[i-j][j], f[i][0]);
        f[i][0]=max(f[i][0], f[i-1][0]);
        for(int j=1;j<=m;j++)
            f[i][j] = max(f[i-1][j-1] + d[i], f[i][j]);
    }

    cout<<f[n][0];
}
