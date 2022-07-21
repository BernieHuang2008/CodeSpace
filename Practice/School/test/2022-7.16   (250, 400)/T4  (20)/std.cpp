#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
const int INF=1<<30;
int n,t;
int a[55];  //a数组表示钱币的面额 
int f[100005];  //f[i]表示拼出奖金i，所需要的最少钱币数量 
int ans;
int work()
{
    int i,j;
    f[0]=0;
    for(i=1;i<=t;i++) f[i]=INF;  //初始化 
    for(i=1;i<=n;i++)
		for(j=a[i];j<=t;j++)
			f[j]=min(f[j],f[j-a[i]]+1);  //枚举是否使用第i种钱币 
    
	for(i=t;i>=0;i--)
	{
		if(f[i]<INF&&i==t)
		{
			printf("%d\n",f[i]);
			return 0;	
		}
		if(f[i]<INF&&i!=t)
		{
	    	ans=t-i;
	    	printf("%d\n",ans); 
	    	return 0;
		}
		
    }
}

int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
	scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    work();
}
