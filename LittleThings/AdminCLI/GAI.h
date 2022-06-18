#ifndef GAI_H
#define GAI_H

#include<iostream>
#include<math.h>
using namespace std;

/*	Copyright H.G.Cucumber	*/

/*	==Function==						==Return==	
 *	AI::strsim(string,string)			-The similarit of strings	//×Ö·û´®ÏàËÆ¶È 
 */

namespace AI{
	

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


}
#endif
