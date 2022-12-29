#include<bits/stdc++.h>
using namespace std;
int n,m,c[1005],l[1001][1001];
int dis[10005],vis[10005];
void dijkstra() {
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	for(int i=1; i<=n; i++) {
		int t=-1;
		for(int j=1; j<=n; j++)
			if(!vis[j] && (t==-1 || dis[j]<dis[t])) t=j;
		vis[t]=1;
		for(int j=1; j<=n; j++) {
			dis[j] = min(dis[j],dis[t]+l[t][j]);
		}
	}
}
int main()
{
    memset(l,0x3f,sizeof(l));
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		cin>>c[i];
	}
	for(int i = 1;i<=m;i++)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		l[x][y]=l[y][x]=v;
		l[x][y]+=c[y];l[y][x]+=c[x];
	}
	dijkstra();
	cout<<dis[n]-c[n];
	return 0;
}
