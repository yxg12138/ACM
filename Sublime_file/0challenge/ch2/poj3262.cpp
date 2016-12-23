#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e5+10;
ll T[maxn],D[maxn];
int N;

struct node{
	int T;
	int D;
}cow[maxn];

bool cmp(node a,node b){
	return a.D*b.T > b.D*a.T;
}

int main(){
	ll ans = 0, t = 0, sum = 0;
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d%d",&cow[i].T,&cow[i].D);
		sum += cow[i].D;
	}

	sort(cow,cow+N,cmp);

	for(int i=0; i<N; i++){
		t = cow[i].T*2;
		sum -= cow[i].D;
		ans += sum * t;
	}

	printf("%lld\n",ans);
}