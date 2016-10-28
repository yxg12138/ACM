#include <iostream>  
#include<bits/stdc++.h>  
#define N 1100  
using namespace std;  
  
char s[N];  
int d[N][N];  
  
int main()  
{  
    scanf("%s",s);  
    int len=strlen(s);  
    memset(d[0],0,sizeof(d[0]));  
    memset(d[len+1],0,sizeof(d[len+1]));  
    for(int i=0;i<len;i++)  
        for(int j=len-1;j>=0;j--)  
            if(s[i]==s[j])  
                d[i+1][j+1]=d[i][j+2]+1;  
            else  
                d[i+1][j+1]=max(d[i][j+1],d[i+1][j+2]);  
    cout<<len-d[len][1]<<endl;  
}  