#include<iostream>
#include<math.h>
using namespace std;

struct node{
    int start,end;
    long long lazy=0;
    long long sum;
};

const int N=1e5*1.1;
long long a[N];
node b[1000];
int block;
int f[N];

void modify(int x,int y,long long k)
{
    if(f[x]==f[y])
    {
        for(int i=x;i<=y;i++)
            a[i]+=k;
        return ;
    }

    // x's block
    for(int i=x;i<=b[f[x]].end;i++)
        a[i]+=k,
        b[f[x]].sum+=k;
    
    // mid-block's lazy
    for(int i=f[x]+1;i<f[y];i++)
        b[i].lazy+=k;

    // y's block
    for(int i=b[f[y]].start;i<=y;i++)
        a[i]+=k,
        b[f[y]].sum+=k;
}

long long query(int x,int y)
{
    long long s=0;
    if(f[x]==f[y])
    {
        for(int i=x;i<=y;i++)
            s+=a[i]+b[f[x]].lazy;
        return s;
    }

    // x's block
    for(int i=x;i<=b[f[x]].end;i++)
        s+=a[i]+b[f[x]].lazy;
    
    // mid-block's lazy
    for(int i=f[x]+1;i<f[y];i++)
        s+=b[i].sum+(b[i].lazy*block);
    
    // y's block
    for(int i=b[f[y]].start;i<=y;i++)
        s+=a[i]+b[f[y]].lazy;

    return s;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    block=(int)sqrt(n); //block size
    int num=(n+block-1)/block;

    // init each block.
    for(int i=1;i<=num;i++)
    {
        b[i].start=(i-1)*block+1;
        b[i].end=i*block;
    }
    b[num].end=n;

	for (int i=1; i<=n; ++i)
        f[i]=(i-1)/block+1;
    
	for (int i=1; i<=num; ++i)
		for (int j=b[i].start; j<=b[i].end; ++j) 
            b[i].sum+=a[j];

    for(int i=0;i<m;i++)
    {
        int mode,x,y;
        long long k=0;
        cin>>mode;
        cin>>x>>y;
        switch (mode)
        {
            case 1:
            {
                cin>>k;
                modify(x,y,k);
                break;
            }
            case 2:
            {
                cout<<query(x,y)<<endl;
                break;
            }
        }
    }
    return 0;
}