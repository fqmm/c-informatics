#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct edge
{
	int u;
	int v;
	double dis;
}ed[1000005];
int fa[1005];
bool cmp(edge a,edge b)
{
	return a.dis<b.dis;
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int Kruskal(int n,int m)
{
	int num=0;
	for(int i = 1;i<=m;i++)
	{
		int fu=find(ed[i].u);
		int fv=find(ed[i].v);
		if(fu!=fv)
		{
			fa[fu]=fv;
			num++;
			
			cout<<ed[i].u<<" "<<ed[i].v<<endl;
			if(num==n-1) break;
		}
	}
	return num;
}
int main()
{
	int num;
	scanf("%d",&num);
	while(num--)
	{
		int n,way[1001][3]={0},m=0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) fa[i]=i;
		for(int i = 1;i <= n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			way[i][1]=x; way[i][2]=y;
		}
		for(int i = 1;i <= n;i++)
		for(int j = i+1;j<=n;j++)
		{
			double d=sqrt(pow(way[i][1]-way[j][1],2)+pow(way[i][2]-way[j][2],2));
			m++;
			ed[m].u=i; ed[m].v=j; ed[m].dis=d;
		}
		sort(ed+1,ed+m+1,cmp);
		int p;
		scanf("%d",&p);
		for(int i = 1;i<= p;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int fu=find(x);int fv=find(y);
			fa[fv]=fu;
		}
		int l = Kruskal(n,m);
		if (l==0) printf("No new highways need\n");
		if(num>0) cout<<endl; 
	}
	return 0;
}
