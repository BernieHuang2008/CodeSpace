#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
    return x > y;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    unique(a,a+n);
    cout<<max(a[3],a[2]%a[1]);
}