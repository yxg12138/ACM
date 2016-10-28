//2.2.2
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;

int N,S[maxn],E[maxn];

pair<int,int> itv[maxn];

void solve(){
	for(int i=0; i<N; i++){
		itv[i].first = E[i];
		itv[i].second = S[i];
	}
	sort(itv,itv+N);

	int ans = 0,end = 0;
	for(int i=0; i<N; i++){
		if(end < itv[i].second){
			end = itv[i].first;
			ans++;
		}
	}

	printf("%d\n",ans);

}


int main(){
	while(scanf("%d",&N)){
		for(int i=0; i<N; i++)
			scanf("%d%d",&S[i],&E[i]);
		solve();
	}


}