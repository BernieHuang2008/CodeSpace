#ifndef VERYLONG_H
#define VERYLONG_H
#include<iostream>

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
    void input(std::string number){
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
            std::cout<<a[num-i];
    }
    std::string tostring(){
        std::string s;
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
    void operator= (std::string b){
        input(b);
    }
};

std::istream &operator >> (std::istream &in,verylong &number){
    number.input();
    return in;
}
std::ostream &operator << (std::ostream &out,verylong &number){
    out<<number.tostring();
    return out;
}
verylong &operator *= (verylong &number,int b){
    number.multself(b);
    return number;
}
#endif // VERYLONG_H