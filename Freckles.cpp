#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double a[105][5]={0};
int father[105];
struct edge
{
	int u;
	int v;
	double dis;
}ed[10005];
bool cmp(edge a,edge b)
{
	return a.dis<b.dis;
}
int find(int x)
{
	if(x==father[x]) return x;
	int temp = find(father[x]);
	return temp;
}
double Kruskal(int n,int m)
{
    double ans=0;
	int num = 0;
	for(int i = 1;i <= m;i++)
	{
		int fu = find(ed[i].u);
		int fv = find(ed[i].v);
		if(fu!=fv)
		{
			father[fu]=fv;
			ans+=ed[i].dis;
			num++;
			if(num==n-1) break;
    	}
	}
	if(num!=n-1) return -1;
	else return ans;
}
int main()
{
	int num;
	scanf("%d",&num);
	while(num--)
	{
		int m = 0;
		int n;
		scanf("%d",&n);
		for(int i = 1;i<=n;i++)
		father[i]=i;
		for(int i = 1;i <= n;i++)
		{
			double x,y;
			scanf("%lf%lf",&x,&y);
			a[i][1]=x;a[i][2]=y;
		}
		for(int i =1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
		{
			double d = sqrt(pow(a[i][1]-a[j][1],2)+pow(a[i][2]-a[j][2],2));
			m++;
			ed[m].u=i;ed[m].v=j;ed[m].dis=d;
		}
		sort(ed+1,ed+m+1,cmp);
		printf("%.2lf\n",Kruskal(n,m));
		if(num) cout<<endl;
	}
}
