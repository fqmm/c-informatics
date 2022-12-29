
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005],x,y,temp;
int ans = 0;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
void floyd()
{
	for(register int k = 1;k<=n;k++)
	for(register int i =1;i<=n;i++)
	for(register int j =1;j <= n;j++)
	a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
}
int main()
{
	memset(a,0x3f,sizeof(a));
	n=read();m=read();
	for(int i =1;i<=m;i++)
	{
		x=read();y=read();temp=read();
		a[x][y]=min(a[x][y],temp);
	}
	floyd();
	for(int i = 2;i<=n;i++)
	{
		ans+=(a[1][i]+a[i][1]);
		//ans+=a[i][1];
	}
	printf("%d",ans);
	return 0;
 } 
