#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
const int maxn = 1000+10;
const int INF = 1e9;

int N,k;
double x;

struct node{
	int a,b;
	bool operator<(const node& rhs)const{
		return a-x*b > rhs.a-x*rhs.b;
	}

}test[maxn];

bool C(double mid){
	x = mid;
	sort(test,test+N);
	double t1=0,t2=0;
	for(int i=0; i<N-k; i++){
		t1 += test[i].a;
		t2 += test[i].b;
	}

	return t1/t2 > mid;
}

int main(){
	while(scanf("%d%d",&N,&k)==2 && (N||k)){
		for(int i=0; i<N; i++) scanf("%d",&test[i].a);
		for(int i=0; i<N; i++) scanf("%d",&test[i].b);


		double lef = 0, rig = 1;
		while(abs(rig-lef) > 1e-4){
			double mid = lef + (rig-lef)/2;
			if(C(mid)) lef = mid;
			else rig = mid;
		}

		printf("%d\n",(int)(lef*100+0.5));
	}
}