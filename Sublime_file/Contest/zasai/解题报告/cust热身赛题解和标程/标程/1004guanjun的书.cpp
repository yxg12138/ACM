#include <iostream>
#include <cstdio>
using namespace std;
const int N=1005;
int n,a[N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int tmp=n,ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]==tmp)
            {
                ans++;
                tmp--;
            }
        }
        printf("%d\n",n-ans);
    }

    return 0;
}
