#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

const int NA=55000;
const int NB=300;
int a[NA],a1[NA],f[NA];
int n;
int block, num;


struct blk{
    int l,r;
    int lazy;
}b[NB];


int found(int,int,long long);
void add(int,int,int);


int main()
{
    freopen("P6278.in","r",stdin);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    block=(int)sqrt(n);
    num=(n-1)/block+1;

    for(int i=1;i<=num;i++)
    {
        b[i].l=(i-1)*block+1;
        b[i].r=i*block+1;
        b[i].lazy=0;
    }
    b[num].r=n;

    for(int i=1;i<=n;i++)
        f[i]=(i-1)/block+1;

    for(int i=1;i<=num;i++)
    {
        for(int j=b[i].l;j<=b[i].r;j++)    a1[i]=a[i];
        sort(a1+b[i].l,a1+b[i].r+1);
    }

    for(int i=0;i<n;i++)
    {
        int opt,l,r,c;
        cin>>opt>>l>>r>>c;
        if(opt) // opt==1  ->  found
        {
            cout<<found(l,r,c*c);
        }
        else
        {
            add(l,r,c);
        }

    }
}