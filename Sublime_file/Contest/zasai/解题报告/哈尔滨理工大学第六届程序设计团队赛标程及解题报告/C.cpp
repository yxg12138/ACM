#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

int m,t;
int n;
int ans;

int main()
{
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&n);
            ans^=n;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
