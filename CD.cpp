#include<iostream>
#include<cstring>
using namespace std;
int w,n,u[2001],dp[2001][2001],x[2001];
inline void back_()
{
	for(register int i(n);i>1;--i)
	{
		if(dp[i][w]==dp[i-1][w])
		x[i]=0;
		else
		{
			x[i]=1;
			w=w-u[i];
		}
	}
	x[1]=(dp[1][w]>0)?1:0;  
}
int main()
{
	while(~scanf("%d",&w))
	{
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		memset(u,0,sizeof(u));
		memset(x,0,sizeof(x));
		for(int i = 1;i<=n;i++)
		scanf("%d",&u[i]);
		for(register int i(1);i<=n;++i)
		for(register int j(w);j>=0;--j)
		{
			if(j>=u[i])
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-u[i]]+u[i]);
			else
			dp[i][j]=dp[i-1][j];
		}
		int ans=dp[n][w];
		back_();
		for(register int i = 1;i<=n;i++)
		if(x[i]!=0)
		printf("%d ",u[i]);
		printf("sum:%d\n",ans);
	}
	return 0;
} 
