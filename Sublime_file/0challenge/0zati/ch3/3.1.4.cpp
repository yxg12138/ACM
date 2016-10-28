//最大化平均值
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6+10;
const int maxn = 1e4+10;
int n,k;
int w[maxn],v[maxn];

double y[maxn];

bool C(double x){
	for(int i=0; i<n; i++)
		y[i] = v[i] - x*w[i];
	sort(y,y+n);

	double sum = 0;
	for(int i=0; i<k; i++){
		sum += y[n-i-1];
	}

	return sum>=0;
}


void solve(){
	double lb = 0,ub = INF;
	for(int i=0; i<100; i++){
		double mid = lb + (ub-lb)/2;
		if(C(mid)) lb = mid;
		else ub = mid;
	}

	printf("%.2lf\n",lb);

}

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> w[i] >> v[i];
	}
	solve();

}