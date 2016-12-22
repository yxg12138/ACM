#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int main(){
	long long n,m;
	cin >> n >> m;

	if(m == (1LL<<(n-1))){
		cout << n << endl;
		return 0;
	}
	long long t=1,ans;
	long long k = (1LL<<(n-1));
	while(1){
		ans = m%k;
		t++;
		k /= 2;
		if(ans == k){
			cout << n-t+1 << endl;
			break;
		}
	}
}