#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

const int NA=55000;
const int NB=300;
int a[NA],a1[NA],f[NA];
int n;
int block, num;
bool tmp;


struct blk{
    int l,r;
    int lazy;
}b[NB];

#define LOG(x) cout<<x;
// #define LOG(x) tmp=1;


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
        b[i].r=i*block;
        b[i].lazy=0;
    }
    b[num].r=n;

    for(int i=1;i<=n;i++)
        f[i]=(i-1)/block+1;

    for(int i=1;i<=num;i++)
    {
        for(int j=b[i].l;j<=b[i].r;j++)    a1[j]=a[j];
        sort(a1+b[i].l,a1+b[i].r+1);
    }

    for(int i=0;i<n;i++)
    {
        int opt,l,r,c;
        cin>>opt>>l>>r>>c;
        if(opt) // opt==1  ->  found
        {
            LOG("in:");
            for(int i=l;i<=r;i++)
                LOG(a[i]);
            LOG(" , search:<"<<c*c<<endl);
            cout<<found(l,r,c*c)<<endl;
        }
        else
        {
            add(l,r,c);
            LOG(a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<endl);
        }

    }
}


int found(int l,int r,long long c)
{
    int ans=0;
    if(f[l]==f[r])
    {
        for(int i=l;i<=r;i++)
            if(a[i]+b[f[l]].lazy<c)    ans++;
        return ans;
    }


    for(int i=l;i<=b[f[l]].r;i++)
        if(a[i]+b[f[l]].lazy<c)    ans++;
    LOG("ans("<<l<<"-"<<b[f[l]].r<<"):"<<ans<<endl);

    for(int i=b[f[r]].l;i<=r;i++)
        if(a[i]+b[f[r]].lazy<c)    ans++;
    LOG("ans("<<b[f[r]].l<<"-"<<r<<"):"<<ans<<endl);

    for(int i=f[l]+1;i<f[r];i++)
    {
        int ll=b[i].l , rr=b[i].r;
        int k=c-b[i].lazy;
        int kk=ll-1;
        while(ll<=rr)
        {
            int mid=(ll+rr)/2;
            if(a1[mid]<k)
                kk=mid, ll=mid+1;
            else
                rr=mid-1;
        }
        ans+=kk+1-b[i].l;
        LOG("ans("<<ll<<"-"<<rr<<"):"<<ans<<endl);
    }
    return ans;
}

void add(int l,int r,int c)
{
    if(f[l]==f[r])
    {
        for(int i=l;i<=r;i++)   a[i]+=c;
        for(int i=b[f[l]].l;i<=b[f[l]].r;i++)   a1[i]=a[i];
        sort(a1+b[f[l]].l,a1+b[f[l]].r+1);
        return;
    }
    
    for(int i=l;i<=b[f[l]].r;i++)    a[i]+=c;
    for(int i=b[f[l]].l;i<=b[f[l]].r;i++)   a1[i]=a[i];
    sort(a1+b[f[l]].l,a1+b[f[l]].r+1);

    for(int i=b[f[r]].l;i<=r;i++)   a[i]+=c;
    for(int i=b[f[r]].l;i<=b[f[r]].r;i++)   a1[i]=a[i];
    sort(a1+b[f[r]].l,a1+b[f[r]].r+1);

    for(int i=f[l]+1;i<f[r];i++)
        b[i].lazy+=c;

    return;
}