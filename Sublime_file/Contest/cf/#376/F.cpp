#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5+10;

int a[maxn],num[maxn*2],pre[2*maxn];

int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		num[a[i]]++;
	}

	for(int i=1; i<=2*maxn; i++)
		pre[i] = pre[i-1]+num[i];

	ll ans = 0;
	for(int i=1; i<=maxn; i++){
		if(!num[i]) continue;

		ll sum = 0;
		for(int j=i; j<=maxn; j+=i){
			ll tmp = pre[j+i-1]-pre[j-1];
			sum += (ll)tmp*j;
		}
		ans = max(ans,sum); 
	}

	cout << ans << endl;
}