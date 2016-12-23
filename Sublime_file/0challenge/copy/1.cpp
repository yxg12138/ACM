#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

int N,S[maxn],T[maxn];
pair<int,int> itv[maxn];

void solve(){
	int ans = 0, t = 0;
	for(int i=0; i<N; i++){
		if(t < itv[i].second){
			ans++;
			t = itv[i].first;
		}
	}

	cout << ans << endl;
}


int main(){
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> itv[i].second >> itv[i].first;
	sort(itv,itv+N);

	solve();
}