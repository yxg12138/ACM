#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
const int maxn = 5e4+10;
const int INF = 1e9;

int N,M,k;
int a[maxn],sum,risk;

struct node{
	int w,s;
	bool operator<(const node& rhs) const{
		return w+s > rhs.w+rhs.s;
	}
}cow[maxn];


int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d%d",&cow[i].w,&cow[i].s);
		sum += cow[i].w;
	}

	sort(cow,cow+N);
	risk = -INF;

	for(int i=0; i<N; i++){
		sum -= cow[i].w;
		risk = max(risk,sum-cow[i].s);
	}

	printf("%d\n",risk);

}