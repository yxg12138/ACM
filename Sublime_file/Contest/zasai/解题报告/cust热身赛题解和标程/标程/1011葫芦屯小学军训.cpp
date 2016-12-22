#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1e3+5;
int a[N],n;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);//排序，可自行百度sort函数
        long long ans=0;
        for(int i=1;i<=n/2;i++)
        {
            ans+=a[n-i+1]-a[i];
        }
        printf("%lld\n",ans*2);
    }
    return 0;
}
