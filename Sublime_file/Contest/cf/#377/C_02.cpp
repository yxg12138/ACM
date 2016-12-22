#include <bits/stdc++.h>
using namespace std;
long long a[5];
int main()
{
    long long mx=0;
    for(int i=1;i<=3;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    mx--;
    long long ans=0;
    for(int i=1;i<=3;i++)
    {
        if(mx>a[i])
            ans+=mx-a[i];
    }
    cout<<ans<<endl;
}