#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5+10;

ll a[maxn],dp[maxn];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }

    ll ans = a[n];
    for(int i=n-1; i>1; i--){
        ans = max(ans,a[i]-ans);
    }

    cout << ans << endl;
}