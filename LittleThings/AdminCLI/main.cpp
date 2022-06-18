#include<iostream>
#include"GAPI.h"
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<map>
using namespace std;
string history[10];
map<string,string>cmdlist;

void showHistory();
void History(string);
void comm(string);
void CMDinit();

int main()
{
	CMDinit();
    string cmd;
    char ch;
    while(cmd!=""||cmd!="exit")
    {
        /*t::reset();
        cout<<t::get()<<endl<<endl<<endl;
        cout<<"------------------------command------------------------"<<endl;
        showHistory();
        cout<<"          ____________________________________________"<<endl;
        cout<<"COMMAND: |"<<cmd;
		if(cmd.length()<=44)
            for(int j=0;j<44-cmd.length();j++)   cout<<"_";
        cout<<"|";
		if(cmd.length()<=44)
            for(int j=0;j<44-cmd.length();j++)   cout<<"\b";
        cout<<"\b";
        ch=getch();*/
        bool a=true;
        while(ch!=13||a)
        {
        	a=false;
        	system("cls");
	        t::reset();
	        cout<<t::get()<<endl<<endl<<endl;
	        cout<<"------------------------command------------------------"<<endl;
	        showHistory();
	        cout<<"          ____________________________________________"<<endl;
	        cout<<"COMMAND: |"<<cmd;
			if(cmd.length()<=44)
	            for(int j=0;j<44-cmd.length();j++)   cout<<"_";
	        cout<<"|";
			if(cmd.length()<=44)
	            for(int j=0;j<44-cmd.length();j++)   cout<<"\b";
	        cout<<"\b";
            ch=getch();
        	if(ch=='\b')
        		cmd=cmd.substr(0,cmd.length()-1);
			else
	            cmd+=ch;
	        
        }
        cmd=cmd.substr(0,cmd.length()-1);
        History(cmd);
//        cout<<cmd.length();
//        system("pause");
        comm(cmd);
        cmd="";
    }
}

void showHistory()
{
    for(int i=0;i<10;i++)
    {
        cout<<"|"<<history[i];
        if(history[i].length()<=54)
            for(int j=0;j<54-history[i].length();j++)   cout<<" ";
        cout<<"|"<<endl;
        if(i%2==1)
            cout<<"|                                                      |"<<endl;
    }
}
void History(string cmd)
{
    for(int i=1;i<10;i++)
    {
        history[i-1]=history[i];
    }
    history[9]=cmd;
}

void GotoXY(int x, int y)  // 移动 
{
 HANDLE hout;  //屏幕尺寸 变量 
 COORD coord={x,y};  //光标坐标 变量  光标x标  光标y标 
 hout=GetStdHandle(STD_OUTPUT_HANDLE);  //获得屏幕尺寸 
 SetConsoleCursorPosition(hout,coord);  //移动光标 
}

void help()
{
	GotoXY(50,0);
	cout<<"HELP:";
	getch();
}

ifstream in("cmd.txt");
void CMDinit()
{
	while(!in.eof())
	{
		string cmd,runcode;
		in>>cmd;
		getline(in,runcode);
		cmdlist[cmd]=runcode;
	}
}

void comm(string s)
{
    if(s=="exit"||s=="0000")
        exit(0);
    else if(s=="time"||s=="0001")
    	History("> "+t::get());
    else if(s=="help"||s=="0002") 
    	help();
    else if(cmdlist[s]!=cmdlist["CANNOTUSETHIS_NONEMAPSPACE"])
    {
    	system("echo None>temp\\output");
		system(cmdlist[s].c_str());
		ifstream output("temp\\output");
		string res="";
		while(!output.eof())
		{
			string oput;
			getline(output, oput);
			res+=oput;
		}
		History("> "+res);
	}
	else
		History("> None"); 
}
