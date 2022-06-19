#include <cstdio>
#include <cstring>
const int N = 110000;
int s[N], c[N]; 
int p, l;

void mult(int a[N], int &l, int b){
	//a*b===c===>a
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
		
	//c数组  长度l l-1----0 
	for (int i=0; i<l; ++i) a[i]=c[i]; 
	
}

int main(){
	
	scanf("%d", &p);
	
	//long long s=1;
	memset(s, 0, sizeof s); s[0]=1; l=1;
	
	
	//for (int i=1; i<=p; ++i) s*=2; 
	for (int i=1; i<=p; ++i) mult(s, l, 2);
	//s l 
	
	for (int i=l-1; i>=0;--i)printf("%d", s[i]);
	printf("\n");
	
	int num=0;
	for (int i=l-1; i>=0; --i){
		printf("%d", s[i]);
		++num;
		if (num%50==0) printf("\n");
	}
	
	return 0;
} 
