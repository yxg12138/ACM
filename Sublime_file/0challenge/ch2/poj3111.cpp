#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
const int maxn = 1e5+10;
const int INF = 1e9;

int N,k;
double x;

struct node{
	int v,w;
	int id;
	bool operator<(const node& rhs) const{
		return v-x*w > rhs.v-x*rhs.w;
	}
}jewel[maxn];

int idx[maxn];


bool C(double mid){
	x = mid;
	sort(jewel,jewel+N);
	double t1=0,t2=0;
	for(int i=0; i<k; i++){
		t1 += jewel[i].v;
		t2 += jewel[i].w;
	}

	return t1/t2 >= mid;
}

int main(){
	scanf("%d%d",&N, &k);
	double lef=0, rig=0;
	for(int i=0; i<N; i++){
		scanf("%d%d",&jewel[i].v,&jewel[i].w);
		jewel[i].id = i+1;
		rig = max(rig, (double)jewel[i].v/jewel[i].w);
	}

	for(int i=0; i<50; i++){
		double mid = lef + (rig-lef)/2;
		if(C(mid)) lef = mid;
		else rig = mid;
	}

	for(int i=0; i<k; i++)
		idx[i] = jewel[i].id;

	sort(idx,idx+k);
	for(int i=0; i<k; i++)
		printf("%d ",idx[i]);
}