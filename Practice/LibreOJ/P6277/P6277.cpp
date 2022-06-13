#include<iostream>
#include<math.h>
using namespace std;

// define

struct block{
    int start;
    int end;
    int lazy;
    int sum;
}b[250];

int n;
int a[55000],f[55000];
int block_size,block_num;

int main()
{
    cin>>n;

    block_size=(int)sqrt(n);
    block_num=(n+block_size-1)/block_size;

    // block init.
    for(int i=0;i<block_num;i++)
    {
        b[i].start=i*block_size+1;
        b[i].end=min(b[i].start+block_size-1,n);
        b[i].lazy=0;
        b[i].sum=0;
    }

    for(int i=1;i<=n;i++)
        f[i]=(i-1)/block_size+1;

    for(int i=1;i<=n;i++)
        cin>>a[i],b[f[i]].sum+=a[i];

    for(int i=0;i<n;i++)
    {
        int opt,l,r,c;
        cin>>opt>>l>>r>>c;
        if(opt) // opt==1
        {
            cout<<a[r];
        }
        else    // opt==0
        {
            
        }
    }
}