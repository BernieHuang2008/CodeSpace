#include <cstdio>
#include <cstdlib>
#include <ctime>

const int N = 110000;
int a[N], n;

void qsort1(int l, int r){
	
	int x=a[l];
	int i=l, j=r, k=l;
	
	
	//
	while (i<j){
		//1ÓÒ
		while (j>i and a[j]>x)--j;
		a[k]=a[j]; ++i; 
		k=j;
		if (i==j) break;
		
		//2×ó 
		while (i<j and a[i]<x)++i;
		a[k]=a[i]; --j;
		k=i; 
		if (i==j) break;
	}
	
	a[i]=x;
	
	//l----i-1   i+1----r 
	
	if (l<i-1) qsort1(l, i-1);
	if (i+1<r) qsort1(i+1, r);

}

int main(){
	srand(time(0));
	
	n=6;
	for (int i=1; i<=n; ++i) a[i]=rand()%10;
	for (int i=1; i<=n; ++i) printf("%d ", a[i]);
	printf("\n");
	
	//¿ìËÙÅÅÐò sort
	 
	qsort1(1, n);
	
	
	for (int i=1; i<=n; ++i) printf("%d ", a[i]);
	printf("\n");

	
	return 0;
} 
