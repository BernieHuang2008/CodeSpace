#include <cstdio>
#include <cstring>
const int N = 550;
int s[N], c[N]; 
int p, l;

void mult(int a[N], int &l, int b){
	//a*b===c===>a
	c[0]=0;
	for (int i=0; i<500; ++i){
		c[i]+=a[i]*b;   //c[i]=c[i]+a[i]*b;
		c[i+1]=c[i]/10;
		c[i]=c[i]%10;  //c[i]%=10;
	}
			
	//c����  ����l l-1----0 
	for (int i=0; i<500; ++i) a[i]=c[i]; 
	
}

int main(){
	
	scanf("%d", &p);
	
	memset(s, 0, sizeof s); s[0]=1; l=1;
	
	for (int i=1; i<=p; ++i) mult(s, l, 2);

	int num=0;
	for (int i=499; i>=0; --i){
		printf("%d", s[i]);
		++num;
		if (num%50==0) printf("\n");
	}
	
	return 0;
} 
