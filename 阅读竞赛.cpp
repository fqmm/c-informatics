#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a>=b) cout<<"0";
	
	else{
		if(y>=x){
			cout<<"Impossible";
			return 0;
		}
		cout<<ceil((b-a)/(x-y))+1;
	}
	return 0;
}
