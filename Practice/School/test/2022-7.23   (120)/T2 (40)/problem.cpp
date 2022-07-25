#include<iostream>
using namespace std;

int C[2200][2200];

int main(){
    freopen("problem.in","r",stdin);
    freopen("problem.out","w",stdout);
    int t,k;
    cin>>t>>k;
    for(int ti=0;ti<t;ti++){
        int m,n;
        cin>>n>>m;
        int an=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=min(i, m);j++){
                if(j>i){
                    continue;
                }
                if(j==0){
                    continue;
                }
                if(i==j){
                    an+=!(1%k);
                    continue;
                }
                unsigned long long ans=1;
                for(int kk=0;kk<j;kk++){
                    ans*=i-kk;
                }
                for(int kk=1;kk<=j;kk++){
                    ans/=kk;
                }
                an+=!(ans%k);
            }
        }
        cout<<an<<endl;
    }
}