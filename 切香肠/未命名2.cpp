#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(n%k==0){
		cout<<0;
		return 0;
	}
	else if(k%n==0)
	{
		cout<<(k/n-1)*n;
	 } 
	 else
	 {
	 	cout<<n;
	 }
	return 0;
}
