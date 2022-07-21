#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("isbn.in","r",stdin);
	freopen("isbn.out","w",stdout);
	char c;
	int b;
	scanf("%d-%d-%d-",&a[1],&a[2],&a[3]);
	cin>>c;
	if(c=='1')b=1;else if(c=='2')b=2;else if(c=='3')b=3;else if(c=='4')b=4;else if(c=='5')b=5;else if(c=='6')b=6;else if(c=='7')b=7;else if(c=='8')b=8;else if(c=='9')b=9;else if(c=='X')b=10;
	if((a[1]*1+(a[2]/100*2)+(a[2]/10)%10*3+a[2]%10*4+a[3]/10000*5+(a[3]/1000)%10*6+(a[3]/100)%10*7+a[3]/10%10*8+a[3]%10*9)%11==b){
	printf("Right");	
	}
	else{
		b=(a[1]*1+(a[2]/100*2)+(a[2]/10)%10*3+a[2]%10*4+a[3]/10000*5+(a[3]/1000)%10*6+(a[3]/100)%10*7+a[3]/10%10*8+a[3]%10*9)%11;
		if(b==1)c='1';else if(b==2)c='2';else if(b==3)c='3';else if(b==4)c='4';else if(b==5)c='5';else if(b==6)c='6';else if(b==7)c='7';else if(b==8)c='8';else if(b==9)c='9';else if(b==10)c='X';
		cout<<a[1]<<'-'<<a[2]<<'-'<<a[3]<<'-'<<c;
	}
	return 0;
}
