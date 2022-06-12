#include<iostream>
using namespace std;
const int N=1e5*1.1;
long long a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
    {
        int mode,x,y,k=0;
        cin>>mode;
        cin>>x>>y;
        switch (mode)
        {
            case 1:
            {
                cin>>k;
                for(int j=x;j<=y;j++)
                    a[j]+=k;
                break;
            }
            case 2:
            {
                for(int j=x;j<=y;j++)
                    k+=a[j];
                cout<<k<<endl;
                break;
            }
        }
    }
}