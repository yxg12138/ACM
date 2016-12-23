	#include <cstdio>
	#include <cmath>

	const int INF = 1e5+10;
	const int maxn = 1e4+10;

	int n,k;
	double L[maxn];

	bool C(double x){
		int num = 0;
		for(int i=0; i<n; i++)
			num += (int)(L[i]/x);
		return num >= k;
	}

	void solve(){
		double lb = 0,ub = INF;

		while(ub-lb>1e-3){
			double mid = lb + (ub-lb)/2;
			if(C(mid)) lb = mid;
			else ub = mid;
		}

		printf("%.2lf\n",floor(ub*100)/100);
	}


	int main(){
		scanf("%d%d",&n,&k);
		for(int i=0; i<n; i++)
			scanf("%lf",&L[i]);
		solve();
	}