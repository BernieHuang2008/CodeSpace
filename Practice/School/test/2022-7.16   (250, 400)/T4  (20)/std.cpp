#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
const int INF=1<<30;
int n,t;
int a[55];  //a�����ʾǮ�ҵ���� 
int f[100005];  //f[i]��ʾƴ������i������Ҫ������Ǯ������ 
int ans;
int work()
{
    int i,j;
    f[0]=0;
    for(i=1;i<=t;i++) f[i]=INF;  //��ʼ�� 
    for(i=1;i<=n;i++)
		for(j=a[i];j<=t;j++)
			f[j]=min(f[j],f[j-a[i]]+1);  //ö���Ƿ�ʹ�õ�i��Ǯ�� 
    
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
