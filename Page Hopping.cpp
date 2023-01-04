#include<iostream>
#include<cstring>
#include <cstdio>
using namespace std;
int way[105][105],n=-1,c=0;
int main()
{
   //	freopen("1.in","r",stdin);
  //  freopen("UVA00821_1.out","w",stdout);
	
	int a,b;
	while(true)
	{
	n=-1;
	memset(way,0x3f,sizeof(way));
	for (register int i = 1; i <= 105; i++)
    way[i][i] = 0;
	scanf("%d%d",&a,&b);
	if(a==0&&b==0)
	{
	break;
    }
	way[a][b]=1; 
	n=max(n,max(a,b));
	while(true)
	{
	scanf("%d%d",&a,&b);
	if(a==0&&b==0)
	{
	break;
    }
	n=max(n,max(a,b));
	way[a][b]=1;
    }
    
	for(int k = 1;k <= n;k++)
	for(int i = 1;i<=n;i++)
	for(int j = 1;j<=n;j++)
	way[i][j] = min(way[i][j],way[i][k]+way[k][j]);
	    
	double num=0,t=0;
	for(int i =1;i<=n;i++)
		for(int j = 1;j<=n;j++)
		{
			if(i!=j&&way[i][j]<0x3f3f3f3f) 
			{
				t=t+way[i][j]; 
				num++;
			}
		}
		 printf("Case %d: average length between pages = %.3lf clicks\n", ++c, t / num);
		}
	return 0;
} 
