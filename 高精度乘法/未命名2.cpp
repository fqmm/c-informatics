#include<bits/stdc++.h>
using namespace std;
int A[8005],B[8005],C[8005],Ans[8005],len_A,len_B,len_Ans;
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
	len_Ans=len_A+len_B-1;
	for(int i = 0;i<len_A;i++)
			for(int j= 0;j<len_B;j++)
			Ans[i+j]+=A[i]*B[j];
			for(int i = 0;i<len_Ans;i++)
			if(Ans[i]>9) Ans[i+1]+=Ans[i]/10,Ans[i]%=10;
			
			while(Ans[len_Ans])  len_Ans++;
			for(int i =len_Ans-1;i>=0;i--)
			cout<<Ans[i];
		
	
	return 0;
}
