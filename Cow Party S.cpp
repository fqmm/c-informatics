#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int l[1005][1005],l1[1005][1005];
int vv[1005]={0},dis[1005],vis[1005];
inline int read()
{
	int x=0,y=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') y=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*y;
}
void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
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
void dijkstra2(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	for(int i=1; i<=n; i++) {
		int t=-1;
		for(int j=1; j<=n; j++)
			if(!vis[j] && (t==-1 || dis[j]<dis[t])) t=j;
		vis[t]=1;
		for(int j=1; j<=n; j++) {
			dis[j] = min(dis[j],dis[t]+l1[t][j]);
		}
	}
}
int main()
{
	memset(l,0x3f,sizeof(l));
	memset(l1,0x3f,sizeof(l1));
	n=read();m=read();x=read();
	for(int i=1;i<=m;i++)
	{
	    int a,b,v;
		a=read();b=read();v=read();
		l[a][b]=min(l[a][b],v);
		l1[b][a]=min(l1[b][a],v);
	}
	dijkstra2(x);
	for(int i = 1;i<=n;i++)
	{
		if(i!=x)
		vv[i]+=dis[i];
	}
	dijkstra(x);
	for(int i = 1;i<=n;i++)
	{
		if(i!=x)
		vv[i]+=dis[i];
	}
	sort(vv+1,vv+1+n);
	printf("%d",vv[n]);
	return 0;
}
