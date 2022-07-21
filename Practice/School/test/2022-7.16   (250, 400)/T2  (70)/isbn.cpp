#include<iostream>

using namespace std;
int main(){
    freopen("isbn.in","r",stdin);
    freopen("isbn.out","w",stdout);

    string s;
    int j=0;
    cin>>s;
    j=1;

    int ans=0;  // ans for mod
    for(int i=0;i<11;i++,j++){
        char c=s[i];
        if(c=='-')
        {
            j--;
            continue;
        }
        ans+=(c-'0')*j;
    }
    ans%=11;

    int cmp;
    cmp=s[s.length()-1]-'0';
    if(s[s.length()-1]=='X')
        cmp=10;
    if(cmp==ans){
        cout<<"Right";
        return 0;
    }
    cout<<s.substr(0,s.length()-1);
    if(ans==10)
    {
        cout<<"X";
        return 1;
    }
    cout<<ans;
}