#include<iostream>
#include<math.h>
using namespace std;
int n,b_num,b_size;
int a[55000];

struct block{
    int s;
    int e;
    int lazy;
    int max=-1;
    int min=1000000;
}b[300];

int f[55000];

int small(int,int,long long);
void add(int,int,int);

int main()
{
    cin>>n;

    b_size=(int)sqrt(n);
    b_num=(n+b_size-1)/b_size;

    for(int i=1;i<=b_num;i++)
    {
        b[i].s=(i-1)*b_size+1;
        b[i].e=i*b_size;
        b[i].lazy=0;
    }
    b[b_num].e=n;

    for(int i=1;i<=n;i++)
        cin>>a[i],
        f[i]=(i-1)/b_size+1,
        b[f[i]].max=max(b[f[i]].max,a[i]),
        b[f[i]].min=min(b[f[i]].min,a[i]);

    
    for(int i=0;i<n;i++)
    {
        bool opt;
        int l,r,c;
        cin>>opt>>l>>r>>c;
        if(opt)
            cout<<small(l,r,c*c)<<endl;
        else
            add(l,r,c);
    }
}

int small(int l,int r,long long c2)
{
    int ans=0;
    if(f[l]==f[r])
    {
        for(int i=l;i<=r;i++)
        {
            if(a[i]<c2)
                ans++;
        }
        return ans;
    }

    // l box
    for(int i=l;i<=b[f[l]].e;i++)
    {
        if(a[i]<c2)
            ans++;
    }
    // r box
    for(int i=b[f[r]].s;i<=r;i++)
    {
        if(a[i]<c2)
            ans++;
    }

    // mid box

    for(int i=f[l]+1;i<f[r];i++)
    {
        if(b[i].max+b[i].lazy<c2)
            ans+=b[i].e-b[i].s+1;
        else if(b[i].min+b[i].lazy>c2)
            continue;
        else
        {
            for(int j=b[i].s;j<=b[i].e;j++)
            {
                if(a[j]<c2)
                    ans++;
            }
        }
    }
    return ans;
}

void add(int l,int r,int c)
{
    if(f[l]==f[r])
    {
        for(int i=l;i<=r;i++)
            a[i]+=c;
        return;
    }
    for(int i=l;i<=b[f[l]].e;i++)
        a[i]+=c;
    for(int i=b[f[r]].s;i<=r;i++)
        a[i]+=c;
    for(int i=f[l]+1;i<f[r];i++)
        b[i].lazy+=c;
}