#include<bits/stdc++.h>
using namespace std;
void dfs(int p);
int n;
int a[55][55];
int vis[55]={0};
int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		for(int b=0;b<n;b++)
		{
			cin>>a[i][b];
		}
	}
    dfs(0);
    
	
	return 0;
}
void dfs(int p)
{
	cout<<p<<" ";
	vis[p]=1;
	for(int k=0;k<n;k++){
		if(a[p][k]==1&&vis[k]==0){
		
		dfs(k);
		}
    }
}
