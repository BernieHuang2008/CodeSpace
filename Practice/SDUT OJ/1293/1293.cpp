/*  Unfinished  */
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int ans[1100000];
int a[1000];

void m1(int a1[1100000], int b[1100000])
{
    int c[1100000];
    memset(c, 0, sizeof c);
    for(int i=1;i<=a1[0];i++)
    {
        for(int j=1;j<=b[0];j++)
        {
            c[i+j]+=a[i]*b[j];
            c[i+j+1]!=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    a1[0]+=b[0];
    while(a1[0]>1 and c[a1[0]-1]==0)    a1[0]--;
    for(int i=0;i<=a1[0];i++)
    {
        a1[i]=c[i];
    }
}


int mult(int x,int p,int s[1100000], int an){
    int l;
    l=0;
    int t[1100000];
    while(p>0){
        a[++l]=p%2;
        p>>=1;
    }
    memset(t, 0, sizeof t); t[1]=x; t[0]=1;
    memset(s, 0, sizeof s); s[0]=1;

    if(a[1])
        s[1]=x;
    else
        s[1]=1;
    
    for(int i=2;i<=l;i++)
    {
        m1(t,t);


        if(a[i])
            m1(s,t);
    }


    t[1]=0; t[0]=1;
    for(int i=1;i<=a[0];i++)
    {
        t[i]+=a[i]*an;
        t[i+1]= t[i]/10;

    }

    
}
int main()
{
    while(1){
        cin>>n;
        if(n==0)
            break;
        m=n%3;
        if(m==0)
            mult(3,n/3,ans,1);
        if(m==1)
            mult(3,n/3-1,ans,4);
        if(m==2)
            mult(3,n-3,ans,2);
        for(int i=1;i<=ans[0];i++)
            cout<<ans[i];
        cout<<endl;
    }
}