#ifndef GFUNCTION_H
#define GFUNCTION_H

#include<iostream>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip>

using namespace std;


/*	Copyright H.G.Cucumber	*/

/*	==Function==			==Return==
 *	gcd(int,int)			-Greatest common factor		//最大公因数
 *	strsim(string,string)	-The similarit of strings	//字符串相似度
 *	print(i/f/c/s)			(void)						//print
 *	input(char)				(string)					//input
 *	toint(ch/str)			(int)						//toint
 *	tostr(int)				(string)					//tostr
 *	strfind(str1,str2)		(int)						//str1中str2出现的次数
 *	color(int)				(void)						//change text color
 *	position(int,int)		(void)						//set print position
 *  coutfloat(int)			(void)						//set decimal digits of 'cout' output
 */



int gcd(int m,int n)
{
	if(m%n==0)    return n;
	else    return gcd(n,m%n);
}

float strsim(string a,string b)
{
	int n[a.length()+1][b.length()+1]= {0};
	int mi=0;
	for(int i=0; i<=a.length(); i++) n[i][0]=i;
	for(int i=0; i<=b.length(); i++) n[0][i]=i;
	for(int i=1; i<=a.length(); i++)
	{
		int mini=max(a.length(),b.length());//mini value in a;
		for(int j=1; j<=b.length(); j++)
		{
			int c=n[i-1][j-1];
			if(a[i-1]!=b[j-1]) c++;
			n[i][j]=min(n[i-1][j]+1,min(n[i][j-1]+1,c));
			mini=min(mini,n[i][j]);
		}
		mi=max(mini,mi);
	}
	return 1-(mi*1.0/max(a.length(),b.length()));
}

int toint(string s)
{
	int rt=0;
	if(s[0]=='-')
	{
		for(int i=1; i<s.length(); i++)
		{
			rt*=10;
			char lstc[10]= {'0','1','2','3','4','5','6','7','8','9'};
			for(int j=0; j<10; j++)
				if(s[i]==lstc[j])	rt+=j;

		}
		rt*=-1;
		return rt;
	}
	for(int i=0; i<s.length(); i++)
	{
		rt*=10;
		char lstc[10]= {'0','1','2','3','4','5','6','7','8','9'};
		for(int j=0; j<10; j++)
			if(s[i]==lstc[j])	rt+=j;
	}
	return rt;
}

int toint(char c)
{
	string s;
	s=c;
	return toint(s);
}

string tostr(int it)
{
	string rt="";
	bool pm=(it<0);
	if(it<0)	it*=-1;
	while(it>=1)
	{
		int i=it%10;
		char lstc[10]= {'0','1','2','3','4','5','6','7','8','9'};
		rt=lstc[i]+rt;
		it=it/10;
	}
	if(pm)	rt="-"+rt;
	return rt;
}

int strfind(string s,string c)
{
	int sum=0;
	while(s.find(c)!=string::npos)
	{
		s=s.substr(s.find(c)+1);
		sum++;
	}
	return sum;
}

void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void position(int x,int y)
{
	COORD pos= {x,y};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out,pos);
}

string turn(string s)
{
	for(int i=0; i<s.length()/2; i++)
	{
		swap(s[i],s[s.length()-i-1]);
	}
	return s;
}

void coutfloat(int f_num)
{
	cout<<fixed;
	cout<<setprecision(f_num);
}
#endif
