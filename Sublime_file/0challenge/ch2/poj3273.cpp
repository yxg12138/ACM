#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
const int maxn = 1e5+10;
int N,M;
int a[maxn];

int main(){
	scanf("%d%d",&N,&M);
	int lef = 0, rig = 0,maxx = 0;
	for(int i=0; i<N; i++) {
		scanf("%d",&a[i]);
		lef = max(lef,a[i]);
		rig += a[i];
	}
	
	while(lef < rig){
		int mid = (lef+rig) / 2;
		int sum = 0;
		int i, cnt = 1;
		for(i=0; i<N; i++) {
			sum += a[i];
			if(sum > mid) { sum = a[i]; cnt++;}
		}

		if(cnt > M) lef = mid+1;
		else rig = mid;
	}
	
	printf("%d\n",lef);

}