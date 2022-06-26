Code:

```cpp
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int NA=1.1e6;
int n, q;
int a[NA], a1[NA], f[NA];
int block, num;  // block size , block num

int check(int,int,int);
void modify(int,int,int);

struct blk{
    int s;
    int e;
    int lazy;
}b[2000];

int main()
{
    // freopen("p2801.in", "r", stdin);

    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }


    block=(int)sqrt(n);
    num=(n-1)/block+1;

    for(int i=1;i<=num;i++)
    {
        b[i].s=(i-1)*block+1;
        b[i].e=i*block;
        b[i].lazy=0;
    }
    b[num].e=n;

    for(int i=1;i<=num;i++)
    {
        for(int j=b[i].s;j<=b[i].e;j++) a1[j]=a[j];
        sort(a1+b[i].s,a1+b[i].e+1);
    }

    for(int i=1;i<=n;i++)
    {
        f[i]=(i-1)/block+1;
    }

    for(int i=0;i<q;i++)
    {
        char opr;
        int l,r,wc;
        cin>>opr;
        cin>>l>>r>>wc;
        if(opr=='M')
        { 
            modify(l,r,wc);
        }
        if(opr=='A')
        {
            cout<<check(l,r,wc)<<endl;
        }
    }

}

int check(int l,int r,int c)
{
    int ans=0;
    if(f[l]==f[r])
    {
        for(int i=l;i<=r;i++)
            if(a[i]+b[f[l]].lazy>=c)    ans++;
    }
    else
    {
        for(int i=l;i<=b[f[l]].e;i++)
            if(a[i]+b[f[l]].lazy>=c)    ans++;
        for(int i=b[f[r]].s;i<=r;i++)
            if(a[i]+b[f[r]].lazy>=c)    ans++;
        for(int i=f[l]+1;i<f[r];i++)
        {
            int k=c-b[i].lazy;
            int ll=b[i].s,rr=b[i].e;
            int an=rr+1;
            while(ll<=rr)
            {
                int mid=(ll+rr)/2;
                if(a1[mid]>=k)
                    rr=mid-1 , an=mid;
                if(a1[mid]<k)
                    ll=mid+1;
                    
            }
            ans+=b[i].e-an+1;
        }
    }
    return ans;
}

void modify(int l,int r,int w)
{
    if(f[l]==f[r])
    {
        for(int i=l;i<=r;i++)    a[i]+=w;
        for(int i=b[f[l]].s;i<=b[f[l]].e;i++)    a1[i]=a[i];
        sort(a1+b[f[l]].s,a1+b[f[l]].e+1);
    }

    else
    {
        for(int i=l;i<=b[f[l]].e;i++)   a[i]+=w;
        for(int i=b[f[l]].s;i<=b[f[l]].e;i++)   a1[i]=a[i];
        sort(a1+b[f[l]].s,a1+b[f[l]].e+1);

        
        for(int i=b[f[r]].s;i<=r;i++)   a[i]+=w;
        for(int i=b[f[r]].s;i<=b[f[r]].e;i++)   a1[i]=a[i];
        sort(a1+b[f[r]].s,a1+b[f[r]].e+1);


        for(int i=f[l]+1;i<f[r];i++)
            b[i].lazy+=w;
    }

    return;
}

```