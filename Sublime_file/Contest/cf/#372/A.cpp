#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
typedef long long ll;

int n,c;
ll a[maxn];

int main(){
	cin >> n >> c;
	for(int i=0; i<n; i++) cin >> a[i];
	
	ll ans = 1, tmp = 0;
	for(int i=0; i<n-1; i++){
		if(a[i+1]-a[i] > c) { tmp=0; ans=1; continue;}
		tmp++;
		ans++;
	}

	cout << ans << endl;
}