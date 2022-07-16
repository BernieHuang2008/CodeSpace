#include<iostream>
#include<cmath>
using namespace std;
int max1=-1,max2=-1;
void mx(int i){
    if(i>max2)
        if(i==max1)
            return;
        else
            max2=min(max1,i),max1=max(max1,i);
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            mx(max(a[i]%a[j],a[j]%a[i]));
        }
    }

    cout<<max2;
}