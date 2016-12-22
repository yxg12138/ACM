#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7;

int a[maxn],mp[maxn];
int n,x;
long long ans;

int main(){
	cin >> n >> x;
	for(int i=0; i<n; i++){
		cin >> a[i];
		ans += mp[a[i]^x];
		mp[a[i]]++;
	}

	cout << ans << endl;
}