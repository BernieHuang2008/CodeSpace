#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
struct node{
    int l, r;
    long long sum;
    long long lazy;
};
long long a[N];
int f[N];
node b[1000];
int n, m, block, num;

void modify(int x, int y, long long k){
	
	//x,y��ͬһ��
	if (f[x]==f[y]){
		for (int i=x; i<=y; ++i) a[i]+=k, b[f[x]].sum+=k;
		return ;
	} 
	
	//��˵� x 
	for (int i=x; i<=b[f[x]].r; ++i) a[i]+=k, b[f[x]].sum+=k;
	
	
	//�Ҷ˵� y
	for (int i=b[f[y]].l; i<=y; ++i) a[i]+=k, b[f[y]].sum+=k;
	
	//x--y �м������
	
	for (int i=f[x]+1; i<f[y]; ++i) b[i].lazy+=k;
	
}

long long query(int x, int y){
	long long s=0;
	if (f[x]==f[y]){
		for (int i=x; i<=y; ++i) s+=a[i]+b[f[x]].lazy;
		return s; 
	}
	
	//��˵� x
	for (int i=x; i<=b[f[x]].r; ++i) s+=a[i]+b[f[x]].lazy;
	
	//�Ҷ˵� y
	for (int i=b[f[y]].l; i<=y; ++i) s+=a[i]+b[f[y]].lazy;
	
	//x--y �м������
	
	for (int i=f[x]+1; i<f[y]; ++i) s+=b[i].sum+b[i].lazy*block; 
	
	return s;
}
int main(){
    // freopen("p3372.in", "r", stdin);
	
	scanf("%d%d", &n,&m);
	for (int i=1; i<=n; ++i) scanf("%lld", &a[i]);
    
    block=(int)sqrt(n); 
	
	num=(n+block-1)/block;
	
	for (int i=1; i<=num; ++i){
		//i: (i-1)*block+1  i*block	
		b[i].l=(i-1)*block+1;
		b[i].r=i*block;
		b[i].lazy=0;
	}
	b[num].r=n;
	
	for (int i=1; i<=n; ++i) f[i]=(i-1)/block+1;	
	
	for (int i=1; i<=num; ++i){
		for (int j=b[i].l; j<=b[i].r; ++j) b[i].sum+=a[j];
	}
    for (int i=1; i<=m; ++i){
		
		int x, y, op;
		long long k;
		scanf("%d", &op);
		if (op==1){
			scanf("%d%d%lld", &x, &y, &k);
			modify(x, y, k);
		}
		if (op==2){
			scanf("%d%d", &x, &y);
			long long sum;
			sum=query(x, y);
			printf("%lld\n", sum);
		}
	}
   
    return 0;
}
