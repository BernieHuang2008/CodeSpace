#include<math.h>
#include<iostream>
using namespace std;

int t[11000],s[11000];
int main()
{
    int p;
    cin>>p;
    int m=(int)(p*log(2)/log(10))+1;
    

    int l=0;
    int a[11000];
    while(p>0)
    {
        a[++l]=p%2;
        p/=2;
    }

    

    cout<<m<<endl;
}