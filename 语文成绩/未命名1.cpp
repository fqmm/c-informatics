#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,y=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') y=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*y;
}
int main()
{
	int n ,p,a[5000005]={0};int k[5000005]={0};
	int b;
	n=read();p=read();
	for(int i =1;i<= n;i++)
	{
	    a[i]=read();
		k[i]=a[i]-a[i-1];
	 } 
	 int l,r,c;
	  while(p--)
	  {
	  	l=read();r=read();c=read();
	  	k[l]+=c;k[r+1]-=c;
	  }
	  int ans=k[1];
	  for(int i = 2;i<=n;i++)
	  {
	  	k[i]=k[i]+k[i-1];
	  	if(k[i]<ans) ans=k[i];
	  }
	 // sort(k+1,k+n+1);
	  cout<<ans;
	  //cout<<k[1];
	return 0;
}
