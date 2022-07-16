#include<iostream>
#include<algorithm>
using namespace std;
const int N=60;
int a[N];
int n,t;
int mini;
int zerotime=-1;

bool cmp(int a,int b){
    return a>b;
}


int my(int money,int times,int num){
    // times: this deepth;
    for(int i=num;i<n;i++)
    {
        if(a[i]<=money){
            // cout<<"use:["<<a[i]<<"]\n";
            my(money-a[i],times+1,i);
        }
    }
    // cout<<"money:"<<money<<"\tmini:"<<mini<<endl;
    if(mini>money){
        mini=money;
    }
    if(money==0)
        zerotime=times-1;
    return 0;
}

int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    cin>>n>>t;
    mini=t;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    my(t,1,0);
    if(zerotime!=-1)
    {
        cout<<zerotime;
        return 0;
    }
    cout<<mini;
}