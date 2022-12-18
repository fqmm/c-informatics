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
    int a;
    int b[125][125]={0},c[125][125]={0};
    scanf("%d",&a);
	for(int i =1;i <= a;i++)
	{
		for(int j =1;j<=a;j++)
		{
		
		b[i][j]=read(); 
		c[i][j]=b[i][j]+c[i-1][j]+c[i][j-1]-c[i-1][j-1];
	}
	 } 
	 long long ans=0,t=0;
	 for(int i =1;i<=a;i++)
	 {
	 	for(int j =1;j<=a;j++)
	 	{
	 		for(int k =1;k<=i;k++)
	 		{
	 			for(int l = 1;l<=j;l++)
	 			{
	 				t = c[i][j]-c[k-1][j]-c[i][l-1]+c[k-1][l-1];
	 				if(ans<=t) ans=t;
				 }
			 }
		 }
	 }
	 cout<<ans;
    return 0;
}
