#include <cstdio>
#include <cstring>
const int N = 11000;

char str1[N];
int a[N], c[N], l, b;
int main(){
	
	
	scanf("%s%d", str1, &b);
	l=strlen(str1);  //长度l 0开始编号 l-1 
	for (int i=0; i<l; ++i) a[l-i-1]=str1[i]-48; //str1[i]====>a[l-i-1]
	
	//for (int i=l-1; i>=0; --i) printf("%d", a[i]);
	
	//乘法 
	c[0]=0;
	for (int i=0; i<l; ++i){
		c[i]+=a[i]*b;   //c[i]=c[i]+a[i]*b;
		c[i+1]=c[i]/10;
		c[i]=c[i]%10;  //c[i]%=10;
	}
	//处理进位 
	++l;
	while (c[l-1]>0){
		c[l]=c[l-1]/10;
		c[l-1]%=10;
		++l;
	}
	
	while (l>1 and c[l-1]==0) --l;
	
	//输出
	for (int i=l-1; i>=0; --i) printf("%d", c[i]);
	 
	return 0;
} 
