#include<iostream>
#include<math.h>
using namespace std;

// define

struct block{
    int start;
    int end;
    int lazy;
}b[250];

int n;
int a[55000],f[55000];
int block_size,block_num;

void modify(int,int,int);

int main()
{
    cin>>n;

    block_size=(int)sqrt(n);
    block_num=(n+block_size-1)/block_size;

    // block init.
    for(int i=1;i<=block_num;i++)
    {
        b[i].start=i*block_size+1;
        b[i].end=min(b[i].start+block_size-1,n);
        b[i].lazy=0;
    }

    for(int i=1;i<=n;i++)
        f[i]=(i-1)/block_size+1;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++)
    {
        int opt,l,r,c;
        cin>>opt>>l>>r>>c;
        if(opt) // opt==1
        {
            cout<<a[r]+b[f[r]].lazy<<endl;
        }
        else    // opt==0
        {
            modify(l,r,c);
        }
    }
}



void modify(int l,int r,int c)
{
    if(f[l]==f[r])  // in the same block
    {
        for(int i=l;i<=r;i++)
        {
            a[i]+=c;
        }
        return;
    }
    // in different blocks

    // l's box
    for(int i=l;i<=b[f[l]].end;i++)
    {
        a[i]+=c;
    }

    // r's box
    for(int i=b[f[r]].start;i<=r;i++)
    {
        a[i]+=c;
    }

    // mid boxes
    for(int i=f[l]+1;i<f[r];i++)
    {
        b[i].lazy+=c;
    }
    
}