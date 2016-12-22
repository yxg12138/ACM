#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793238;

int n,d,angle;

int main(){
	while(scanf("%d%d",&n,&d)!=EOF){
		double ans = 0;
		for(int i=0; i<n; i++) {
			scanf("%d",&angle);
			double h = d*sin(pi/180 * angle)*1.0;
			ans += 0.5*d*h;
		}
		printf("%.3lf\n",ans);
	}
}
