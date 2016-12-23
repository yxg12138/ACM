#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
const int maxn = 1e5+10;
const int INF = 1e9;

ll N,C_N_2;
ll a[maxn];

bool C(int mid){
	ll cnt = 0;
	for(int i=0; i<N; i++){
		cnt += a+N - lower_bound(a+i+1,a+N, mid+a[i]);
	}
	return cnt <= C_N_2/2;
}

int main(){
	while(scanf("%d",&N)==1){
		ll minn=INF, maxx=-INF;
		for(int i=0; i<N; i++)
			scanf("%d",&a[i]);

		sort(a,a+N);
		C_N_2 = N*(N-1)/2;
		ll lb = 0, ub = a[N-1]-a[0];
		while(ub-lb > 1){
			int mid = (ub+lb)/2;
			if(C(mid)) ub = mid;
			else lb = mid;
		}

		cout << lb << endl;
	}
}