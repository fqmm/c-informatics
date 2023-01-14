#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,m,u[105],w[105],dp[105][1005];
	scanf("%d%d",&t,&m);
	for(int i= 1;i<=m;i++)
	cin>>u[i]>>w[i];
	for(int i= 1;i<=m;i++)
	{
		for(int j=t;j>=0;j--)
		{
			if(j>=u[i])
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-u[i]]+w[i]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	printf("%d",dp[m][t]);
	return 0;
}
