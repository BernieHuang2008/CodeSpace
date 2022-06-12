#include <cstdio>
const int N = 110000;
long long a[N];
int n, m;
int main(){
	
	freopen("p3372.in", "r", stdin);
	
	scanf("%d%d", &n,&m);
	for (int i=1; i<=n; ++i) scanf("%lld", &a[i]);
	
	for (int i=1; i<=m; ++i){
		
		int x, y, op;
		long long k;
		scanf("%d", &op);
		if (op==1){
			scanf("%d%d%lld", &x, &y, &k);
			for (int j=x; j<=y; ++j) a[j]+=k;
		}
		if (op==2){
			scanf("%d%d", &x, &y);
			long long sum=0;
			for (int j=x; j<=y; ++j) sum+=a[j];
			printf("%lld\n", sum);
		}
	}
	
	return 0;
}
