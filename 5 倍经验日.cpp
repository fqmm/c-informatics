#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long dp[1005][1005],lose[1005],win[1005],use[1005];
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i = 1;i <= n;i++) scanf("%d%d%d",&lose[i],&win[i],&use[i]);
	for(int i = 1;i<= n;i++)
	{
		for(int j =x;j>=0;j--)
		{
			if(j>=use[i])
			dp[i][j]=max(dp[i-1][j]+lose[i],dp[i-1][j-use[i]]+win[i]);
			else
			dp[i][j]=dp[i-1][j]+lose[i];
		}
		//for(int j = x;j >= use[i];j--)
	//	{
	//		dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
	//	}
	}
	cout<<5*dp[n][x];
} 
