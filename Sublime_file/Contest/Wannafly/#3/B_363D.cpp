#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1<<30;
const int maxn = 2e5+7;

ll ans, n, m, k ,a[maxn], b[maxn];

bool C(int x){
	ll sum = 0, kk = k;
	for(int i=n; i>=1&&x>=1; i--,x--){
		if(a[i]>=b[x]) sum += b[x];
		else{
			if(kk>0 && a[i]+kk>=b[x]){
				sum += a[i];
				kk -= b[x]-a[i];
			}else return 0;
		}
	}
	if(kk<0 || x>=1) return 0;
	ans = sum-kk<=0 ? 0 : min(ans,sum-kk);
	return 1;
}

int main(){
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=m; i++) cin >> b[i];

	sort(a+1,a+1+n);
	sort(b+1,b+1+m);

	if(a[n]+k < b[1]){
		cout << "0 0\n";
		return 0;
	}

	ans = INF;
	int le = 1,ri = m;
	while(le <= ri){
		int mid = (le+ri)/2;
		if(C(mid)) le = mid + 1;
		else ri = mid-1;
	}

	ans = INF;
	bool t1 = C(le), t2 = C(ri);
	if(t1 && !t2) cout << le << " " << ans << endl;
	else cout << ri << " " << ans << endl;
}
