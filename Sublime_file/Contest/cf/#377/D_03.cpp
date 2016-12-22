#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int n,m,d[maxn];

struct subject{
	int late,a;
	bool operator<(const subject& rhs) const{
		return late < rhs.late;
	}
}s[maxn];

bool C(int t){
	for(int i=1; i<=m; i++) s[i].late = 0;
	for(int i=1; i<=t; i++) if(d[i]) s[d[i]].late = i;

	sort(s+1,s+1+m);
	int cnt=0,last=0;
	for(int i=1; i<=m; i++){
		if(s[i].late == 0) return false;
		cnt += s[i].late - last - 1;
		if(cnt < s[i].a) return false;
		cnt -= s[i].a;
		last = s[i].late;
	}
	return true;
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> d[i];
	for(int i=1; i<=m; i++) cin >> s[i].a;

	int le = 1, ri = n, ans = n+1;

	while(le <= ri){
		int mid = (le+ri) / 2;
		if(C(mid)) ans = min(ans,mid),ri=mid-1;
		else le = mid+1;
	}

	if(ans == n+1) cout << -1 << endl;
	else cout << ans << endl;
}