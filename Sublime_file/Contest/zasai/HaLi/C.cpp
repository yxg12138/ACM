/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				TLE
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

map<int,int> mp;
int ans,a[maxn];

int main(){
	int T,n;
	cin >> T;
	while(T--){
		mp.clear();
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}

		for(int i=0; i<n; i++){
			if(mp[a[i]]%2==1){
				ans = a[i];
				break;
			}
		}

		cout << ans << endl;
	}
}