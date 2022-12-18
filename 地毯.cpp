#include<cstdio>
#include<iostream>
using namespace std;
int cf[2000][2000]={0};
int main()
{
    int n,m;
    int x1,y1,x2,y2;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int i=x1;i<=x2;i++)
        {
            cf[i][y1]++;
            cf[i][y2+1]--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cf[i][j]+=cf[i][j-1];
            printf("%d ",cf[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
