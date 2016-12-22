#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,k;
	cin >> n >> k;
	char s[105];
	cin >> s;
	int st,en;
	for(int i=0; i<n; i++){
		if(s[i] == 'G') st = i;
		if(s[i] == 'T') en = i;
	}

	if(st > en) swap(st,en);

	if((en-st)%k != 0) {
		cout << "NO" << endl;
		return 0;
	}

	for(int i=st+k; i<n; i+=k){
		if(s[i] == '#') {
			cout << "NO" << endl;
			return 0;
		}
		if(s[i] == 'T' || s[i] == 'G'){
			cout << "YES" << endl;
			return 0;
		}
	}

}