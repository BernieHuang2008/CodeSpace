#include<iostream>
using namespace std;
int main(){
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    string str;
    cin>>str;
    int ans=0;
    for(int i=0;i<str.length();i++){
        ans+=(str[i]=='1');
    }
    cout<<ans;
}