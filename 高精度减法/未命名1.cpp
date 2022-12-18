#include<bits/stdc++.h>
using namespace std;
int A[1005],B[1005],C[1005],Ans[1005],len_A,len_B,len_Ans;
void Read(int *A,int &len)
{
	string cur;
	cin>>cur;
	len=cur.length();
	for(int i =0;i<len;i++) A[i]=cur[i]-48;
	reverse(A,A+len);
}
int main()
{
	Read(A,len_A);
	Read(B,len_B);
	len_Ans = max(len_A,len_B);
	for(int i =0;i<len_Ans;i++)
	{
		Ans[i] = A[i]-B[i]-C[i];
		if(Ans[i]<0) C[i+1]++,Ans[i]+=10;
	}
	while(len_Ans>1&&Ans[len_Ans-1]==0) len_Ans--;
	for(int i = len_Ans-1;i>=0;i--)
	cout<<Ans[i];
	return 0;
}
