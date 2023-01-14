#include<bits/stdc++.h>
using namespace std;
int main()
{
	int v,n,w[55],dp[50005];
	scanf("%d%d",&v,&n);
	for(int i = 1;i<=n;i++)
	cin>>w[i];
	for(int i = 1;i<=n;i++)
	{
		for(int j = v;j>=w[i];j--)
		{
		//	if(j<dp[j-w[i]]+w[i])
		//	{
				dp[j]=max(dp[j-w[i]]+w[i],dp[j]);
		//	}
		
		}
	}
	cout<<v-dp[v];
	return 0;
}
