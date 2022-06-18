#include<iostream>
#include"GAPI.h"
#include<conio.h>
using namespace std;
int main()
{
    string cmd;
    char ch;
    while(cmd!=""||cmd!="exit")
    {
        cout<<t::get()<<endl;
        cout<<"          ________________________________________________"<<endl;
        cout<<"COMMAND: |________________________________________________|\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
        ch=getch();
        if(ch==13)
        {
            cout<<"exit"<<endl;
            exit(0);
        }
        cmd+=ch;
    }
}
