#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1<<30;

int main(){
	int n,m;
	cin >> n >> m;
	int le,ri,ans_l,ans = INF;
	for(int i=0; i<m; i++){
		cin >> le >> ri;
		if(ri-le+1 < ans){
			ans = ri-le+1;
			ans_l = le;
		}
	}

	cout << ans << endl;
	int val = (ans-(ans_l-1)%ans)%ans;

	for(int i=1; i<=n; i++){
		cout << val;
		if(i == n) cout << endl;
		else cout << " ";
		val = (val+1)%ans;
	}
}