#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x,y,x2,y2,n;
ll a[305],b[305],c[305];

int main(){
	cin >> x >> y >> x2 >> y2;
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}

	int ans = 0;
	for(int i=1; i<=n; i++){
		ll exm1,exm2;
		exm1 = a[i]*x+b[i]*y+c[i];
		exm2 = a[i]*x2+b[i]*y2+c[i];

		if(exm1 > 0)
			exm1 = 1;
		else if(exm1 < 0)
			exm1 = -1;
		if(exm2 > 0)
			exm2 = 1;
		else if(exm2 < 0)
			exm2 = -1;

		if(exm1 * exm2 < 0)
			ans++;

	}

	cout << ans << endl;
}