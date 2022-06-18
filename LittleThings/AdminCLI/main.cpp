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
        cout<<"          ________________________"<<endl;
        cout<<"COMMAND: |________________________|\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
        ch=getch();
        if(ch==13)
        {
            cout<<t::get()<<endl;
        }
        cmd+=ch;
    }
}
