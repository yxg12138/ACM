#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+7;

long long a[maxn];
int n,k,x;
set<pair<long long,long long> > S;

int main(){
	cin >> n >> k >> x;
	int sig = 0;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i] < 0) sig ^= 1;
		S.insert(make_pair(abs(a[i]),i));
	}

	for(int i=1; i<=k; i++){
		int pos = S.begin()->second;
		S.erase(S.begin());
		if(a[pos] < 0) sig ^= 1;
		if(sig) a[pos] += x;
		else a[pos] -= x;

		if(a[pos] < 0) sig ^= 1;
		S.insert(make_pair(abs(a[pos]),pos));
	}

	for(int i=1; i<=n; i++)
		cout << a[i] << " ";
	cout << endl;
}