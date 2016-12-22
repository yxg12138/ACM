#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

int n,m,k;
int x,s;
int a[maxn], b[maxn], c[maxn], d[maxn];

int C(int x){
	int le = 0, ri = k;
	while(le<ri){
		int mid = (le+ri+1)/2;
		if(d[mid] <= x) le = mid;
		else ri = mid - 1;
	}

	return c[le];
}

int main(){
	cin >> n >> m >> k;
	cin >> x >> s;
	a[0] = x;
	b[0] = 0;
	c[0] = 0;
	d[0] = 0;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= k; i++) cin >> c[i];
	for (int i = 1; i <= k; i++) cin >> d[i];

	long long ans = 1LL * n * x;

	for(int i=0; i<=m; i++){
		int now = s-b[i];
		if(now < 0) continue;
		ans = min(ans,1LL * a[i] * (n-C(now)));
	}

	cout << ans << endl;
}