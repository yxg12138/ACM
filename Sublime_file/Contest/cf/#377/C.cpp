#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main()
{
    ll b,d,s;
    cin>>b>>d>>s;
    ll ans = inf;
    ll maxn = max(max(b,d),s);
    ll minn = min(min(b,d),s);
    if(maxn==minn)
    {
        ans = 0;
    }
    else if((b==maxn&&d==maxn) || (b==maxn&&s==maxn) || (s==maxn&&d==maxn)) {
        ans = maxn-1-minn; 
    }else{
        ans = maxn*3-2-b-d-s;
    }
    printf("%I64d\n",ans);
}
