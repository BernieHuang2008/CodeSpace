#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1100000;
struct node1{
	int l, r;
	int lazy;
};
int a[N], a1[N];
node1 b[1100];
int n, q, block, num;
int f[N];
void modify(int x, int y, int k){
	if (f[x]==f[y]){
		for (int i=x; i<=y; ++i) a[i]+=k;
		for (int i=b[f[x]].l; i<=b[f[x]].r; ++i) a1[i]=a[i];
		sort(a1+b[f[x]].l, a1+b[f[x]].r+1);
		return;
	}
	
	//左  右  整块
	for(int i=x; i<=b[f[x]].r; ++i) a[i]+=k;
	for (int i=b[f[x]].l; i<=b[f[x]].r; ++i) a1[i]=a[i];
	sort(a1+b[f[x]].l, a1+b[f[x]].r+1);
		
	
	for(int i=b[f[y]].l; i<=y; ++i) a[i]+=k;
	for (int i=b[f[y]].l; i<=b[f[y]].r; ++i) a1[i]=a[i];
	sort(a1+b[f[y]].l, a1+b[f[y]].r+1);
		
	for (int i=f[x]+1; i<f[y]; ++i) b[i].lazy+=k;
		
}
int check1(int x, int y, int k){
	int ans=0;
	if (f[x]==f[y]){
		for (int i=x; i<=y; ++i) 
			if (a[i]+b[f[x]].lazy>=k) ++ans;
		return ans;
	}
	//左  右  整块
	for(int i=x; i<=b[f[x]].r; ++i) 
		if (a[i]+b[f[x]].lazy>=k) ++ans;
		
	for(int i=b[f[y]].l; i<=y; ++i) 
		if (a[i]+b[f[y]].lazy>=k) ++ans;
		
	for (int i=f[x]+1; i<f[y]; ++i){
		//i b[i].l  b[i].r  a1[i]  k
		int k1=k-b[i].lazy;
		// a1[b[i].l]      a1[b[i].r]    k1
		int ll=b[i].l, rr=b[i].r;
		int kk=rr+1;
		//最靠左a1[i]>=x 的位置i 
		while (ll<=rr){
			int mid=(ll+rr)>>1;
			if (a1[mid]<k1) ll=mid+1;
			else {
				kk=mid;
				rr=mid-1;
			}
		}
		ans+=b[i].r-kk+1;
	}
	 
	return ans;
}
int main(){
//	freopen("p2801.in", "r", stdin);
	
	//读入数据
	scanf("%d%d", &n,&q);
	for (int i=1; i<=n; ++i) scanf("%d", &a[i]);
	
	//初始化
	block=(int)sqrt(n);
	num=(n-1)/block+1;
	for (int i=1; i<=num; ++i){
		b[i].l=(i-1)*block+1;
		b[i].r=i*block;
		b[i].lazy=0;
		
	}
	b[num].r=n;
	
	for (int i=1; i<=num; ++i) {
		for (int j=b[i].l; j<=b[i].r; ++j) a1[j]=a[j];
		sort(a1+b[i].l, a1+b[i].r+1);
	}
	
	for (int i=1; i<=n; ++i) f[i]=(i-1)/block+1;
	
	
	for (int i=1; i<=q; ++i){
		//char ch;
		int x, y, c;
		//scanf("%c%c", &ch, &ch);
		char ch[10];
		scanf("%s", ch);

		scanf("%d%d%d", &x, &y, &c);
		
		if (ch[0]=='M'){
			modify(x, y, c);
		}
		if (ch[0]=='A'){
			int ans;
			ans=check1(x, y, c);
			printf("%d\n", ans);
		}
	} 
	
	return 0;
} 