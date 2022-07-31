#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int w,n;
int a[33000];

void qsort(int l,int r){
    int x=a[l];
    int i=l,j=r;
    while(i<j){
        while(i<j and a[j]>=x)   --j;
        a[i]=a[j];

        while(i<j and a[i]<=x)   ++i;
        a[j]=a[i];
    }
    a[i]=x;
    if(l<i-1)   qsort(l, i-1);
    if(i+1<r)   qsort(i+1, r);
}

int main(){
    freopen("P1094.in", "r", stdin);
    freopen("P1094.out", "w", stdout);
    scanf("%d%d", &w ,&n);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    
    qsort(1, n);

    int i=1,j=n,s=0;

    while(i<=j){
        if(a[i]+a[j]<=w)
            i++;
        j--;
        s++;
    }

    cout<<s;
}