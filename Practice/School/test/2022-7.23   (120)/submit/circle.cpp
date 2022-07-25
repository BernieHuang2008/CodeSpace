#include<iostream>
#include<cmath>
using namespace std;

int main(){
   freopen("circle.in","r",stdin);
   freopen("circle.out","w",stdout);
    int a[110];
    int n,m,k,x,len;
    cin>>n>>m>>k>>x;
    for(int i=1;i<100;i++){
        a[i]=((int)pow(10, i))%n;
        for(int j=0;j<i;j++)
            if(a[j]==a[i])
                len=i;
    }
    cout<<((a[k%len]*m%n)%n+x)%n;
}
