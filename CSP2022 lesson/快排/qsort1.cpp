#include <stdio.h>

const int N = 11000;
int a[N]={0,4,7,3,6,9,2,5};
int n=6;

void qsort1(int l, int r){
	
	int x=a[l];
	int i=l, j=r, k=l;
	
	
	while (i<j){
		// 1 left
		while (j>i and a[j]>x)--j;
		a[k]=a[j]; k=j; 
		if (i>=j) break;	// stop i
		i++; 
		
		// 2 right
		while (i<j and a[i]<x)++i;
		a[k]=a[i]; k=i; 
		if (i>=j) break;
		j--;
	}
	
	a[i]=x;
	
	//l----i-1   i+1----r 
	
	if (l<i-1) qsort1(l, i-1);
	if (i+1<r) qsort1(i+1, r);

}

int main(){
	n=7;
	for (int i=1; i<=n; ++i) printf("%d ", a[i]);
	printf("\n");
	
	//�������� sort
	 
	qsort1(1, n);
	
	
	for (int i=1; i<=n; ++i) printf("%d ",a[i]);
	printf("\n");

	
	return 0;
} 
