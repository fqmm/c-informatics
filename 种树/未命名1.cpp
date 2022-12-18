#include<bits/stdc++.h>
using namespace std;
int g[30005]={0};
struct v
{
	int l,r,m;
}j[50005];
inline int read()
{
	int x=0,y=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') y=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*y;
}
int num(int l,int r)
{
	int k=0;
	for(int i =l;i<=r;i++)
	{
		k+=g[i];
	}
	return k;
}
void f(int t,int l,int r)
{
    for(int i =r;t>0;i--)
	{
		if(g[i]==0)
		{
		
		g[i]+=1;t--;
	}

		}	
}
int cmp(const v &a,const v&b){
	return a.r<b.r;
}
int main()
{
	int n,h,t,e;
	int ans;
	
	n=read();h=read();
	for(int i =1;i<=h;i++)
	{
		j[i].l=read();j[i].r=read();j[i].m=read();
		
	 } 
	 sort(j+1,j+1+h,cmp);
	 for(int i =1;i<=h;i++)
	 {
	 	e=num(j[i].l,j[i].r);
		t=j[i].m-e;
		f(t,j[i].l,j[i].r);
	 }
	 for(int i =1;i<=n;i++)
	 {
	 	ans+=g[i];
	 }
	 cout<<ans;
	return 0;
}
