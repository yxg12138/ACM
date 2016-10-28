#include <cstdio>


int main(){
	int n, D, p, L, v,kase = 0;

	while (scanf("%d%d", &n, &D) == 2 && D)
	{
		double ans = 0;
		for (int i = 0; i < n; i++){
			scanf("%d%d%d", p, L,v);
			D -= L;
			ans += 2.0*L / v;
		}
		ans += D;
		printf("Case %d: %.3lf\n\n",++kase, ans);



	}


}