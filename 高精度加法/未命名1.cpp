#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int a[506], b[506];
int lena, lenb;
int m;
string a1, b1;

int main(){
    cin>>a1>>b1;//������ַ�������ֻ������gets��cin��������scanf
    lena = a1.length();
    lenb = b1.length();
    for (int i = 0; i <= lena - 1; i++){  //�ַ���תΪ���֣������Ӧ�������±� 
        a[lena - i - 1] = a1[i] -'0';
    }
    for(int i = 0; i <= lenb - 1; i++){
        b[lenb - i - 1] = b1[i] - '0';
    }
    if(lena >= lenb){
        for(int i = 0; i <= lena - 1; i++){
            int ss = a[i];
            a[i] = (b[i] + a[i] + m)%10;
            m = (ss + b[i] + m)/10;
        }
        if(m) a[lena] = m;
        else lena--;
        for(int i = lena; i >= 0; i--) printf("%d",a[i]);
        return 0;
    }
    else{
        for(int i = 0; i <= lenb-1; i++){
            int ss = b[i];
            b[i] = (b[i] + a[i] + m)%10;
            m = (ss + a[i] + m) /10;
        }
        if(m) b[lenb] = m;
        else lenb--;
        for(int i = lenb; i >= 0; i--) printf("%d",b[i]);
        return 0;
    }
    return 0;
}
