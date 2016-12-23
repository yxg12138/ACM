#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
const int maxn = 1e5+10;
ll N,M,k;
ll a[maxn];


bool C(int mid){
	ll minutes = 0;
	for(int i=0; i<N; i++){
		int more = a[i]-mid;
		if(more>0){
			minutes += ceil(more*1.0/k);
			if(minutes > mid) return false;
		}
	}

	return true;
}

int main(){
	scanf("%d",&N);
	ll lef = 0, rig = 0;
	for(int i=0; i<N; i++){
		scanf("%d",&a[i]);
		lef = min(lef,a[i]);
		rig = max(rig,a[i]);
	}
	scanf("%d",&k);
	--k;
	if(k == 0) {
		printf("%lld",rig);
		return 0;
	}
	lef /= k;
	while(lef < rig){
		int mid = (lef+rig)/2;
		if(C(mid)) rig = mid;
		else lef = mid+1;
	}

	printf("%lld\n",rig);
}