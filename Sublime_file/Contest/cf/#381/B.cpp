#include <bits/stdc++.h>
using namespace std;

int a[105],sum[105];

int main(){
	int n,m;
	cin >> n >> m;

	sum[0] = 0;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}

	int le,ri;
	int ans = 0;
	for(int i=0; i<m; i++){
		cin >> le >> ri;
		if(sum[ri]-sum[le-1] > 0){
			ans += sum[ri]-sum[le-1];
		}
	}

	cout << ans << endl;

}