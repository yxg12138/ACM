#include<bits/stdc++.h>  
using namespace std;  
map<int,int>a,b,c;  
int main()  
{  
    int n,num,i,j,ans,k,m,t,t1,t2,ok;  
    cin>>n>>num;  
    ans=100;  
    ok=0;  
    m=num;  
    k=0;  
    while(num) {  
        if(num%2) a[k]++;  
        num=num/2;  
        k++;   
    }  
    t1=k;  
    for(i=1;i<=n;i++) {  
        cin>>t;  
        k=0;  
        if(t>m) continue;  
        while(t) {  
            if(t%2) {  
                if(a[k]==0) break;  
                b[k]=1;   
            }  
            else b[k]=0;  
            k++;  
            t=t/2;  
        }  
        if(t) continue;  
        for(j=0;j<k;j++) {  
            if(b[j]) {  
                c[j]++;  
            }  
            ok=1;  
        }  
    }  
    if(!ok) printf("0\n");  
    else {  
        for(i=0;i<t1;i++) {  
            if(a[i]) ans=min(ans,c[i]);  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}