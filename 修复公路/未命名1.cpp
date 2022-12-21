#include<bits/stdc++.h>
using namespace std;
int find(int x);
int n,m;

int p[100005],Rank[100005];
struct v
{
	int a,b,c;
}s[100005]; 
int cmp(v a,v b){
	return a.c<b.c;
}
void mag(int i ,int j)
{
    int x = find(i),y = find(j); 
    if(Rank[x] < Rank[y]){       
        p[x]=y;
    }
    else{
        p[y]=x;
    }
    if(Rank[x] == Rank[y] && x != y){  
        Rank[x]++;
    }
}
int g;
bool pd()
{
	g=p[1];
	for(int i =2;i<=n;i++)
	{
		if(find(p[i])!=find(g)) return false;
	
	}
	return true;
}
int find(int x)
{
	return x == p[x] ? x : (p[x] = find(p[x]));
}
int main()
{
	
	scanf("%d%d",&n,&m);
	int d,e,f;
	for(int i =1;i<=m;i++)
	{
		cin>>d>>e>>f;
		s[i].a=d;s[i].b=e;s[i].c=f;
	}
	sort(s+1,s+1+m,cmp);
	for(int i =1;i<=m;i++)
	{
		p[i]=i;Rank[i]=1;
	}
	int x,y;
	for(int i =1;i<=m;i++)
	{
		x=s[i].a;y=s[i].b;
		mag(x,y);
		if(pd())
		{
		
		cout<<s[i].c;
		return 0;
	}
	}
	cout<<"-1";
	return 0;
}
