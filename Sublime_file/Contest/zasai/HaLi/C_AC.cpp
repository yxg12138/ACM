#include <bits/stdc++.h>
using namespace std;


int main(){
	int T,n,k,ans;
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> k;
			ans ^= k;
		}

		cout << ans << endl;
	}


}