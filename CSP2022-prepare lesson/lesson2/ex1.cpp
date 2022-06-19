#include <cstdio>
int p;
int main(){
	
	scanf("%d", &p);
	long long s=1;
	for (int i=1; i<=p; ++i) s*=2;
	printf("%lld", s);
	
	return 0;
} 
