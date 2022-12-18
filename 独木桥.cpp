#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,n,minxx=0;
	int minx = 0,maxx = 0;
	int s[5005];
	cin>>l>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i = 1;i<=n;i++)
	{
		if(s[i]>=(l/2)) minx=l-s[i]+1;
		else minx =s[i];
		
		minxx=max(minxx,minx);
	}
	int maxt = 0;
	for(int i =1;i<=n;i++)
	{
	    if(s[i]>=(l/2)) maxt=s[i];
	    else maxt = l-s[i]+1;
	    maxx = max(maxx,maxt);
	}
	cout<<minxx<<" "<<maxx;
	return 0;
}
