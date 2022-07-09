#include<math.h>
#include<iostream>
using namespace std;

class verylong{
    #define MAXLEN 11000
    int a[MAXLEN];
    int len;
    public:
    void input(){
        std::string number;
        std::cin>>number;
        len=number.length();
        for(int i=0;i<len;i++)
            a[len-i-1]=number[i]-'0';
    }
    void input(string number){
        len=number.length();
        for(int i=0;i<len;i++)
            a[len-i-1]=number[i]-'0';
    }
    void output(){
        for(int i=len-1;i>=0;i--)
            std::cout<<a[i]+'0';
    }
    void output(int num){
        for(int i=1;i<=num;i++)
            cout<<a[num-i];
    }
    void output2(){
        for(int i=1;i<500;i++)
        {
            cout<<a[500-i];
            if(i%50==0) cout<<endl;
        }
        cout<<a[0]-1;
    }
    string tostring(){
        string s;
        for(int i=len-1;i>=0;i--)
            s+=a[i]+'0';
        return s;
    }
    int length(){
        return len;
    }
    void multself(int b){
        int c[len];
        c[0]=0;
        for(int i=0;i<len;i++)
        {
            c[i]+=a[i]*b;
            c[i+1]=c[i]/10;
            c[i]%=10;
        }
        len++;
        while(c[len-1]>0)
        {
            c[len]=c[len-1]/10;
            c[len-1]%=10;
            len++;
        }

        while(len>1 and c[len-1]==0)
            len--;
        for(int i=0;i<len;i++)
            a[i]=c[i];
    }
    void cut(int num){
        if(num<0)
            return;
        for(int i=num;i<=len;i++)
            a[i]=0;
        len=num;
    }
    void operator= (string b){
        input(b);
    }
};

istream &operator >> (istream &in,verylong &number){
    number.input();
    return in;
}
ostream &operator << (ostream &out,verylong &number){
    out<<number.tostring();
    return out;
}
verylong &operator *= (verylong &number,int b){
    number.multself(b);
    return number;
}

int main()
{
    verylong a;
    a="1";
    int p;
    cin>>p;
    int m=(int)(p*log(2)/log(10))+1;
    for(int i=0;i<p;i++)
        a*=2,a.cut(500);

    cout<<m<<endl;
    a.output2();
}