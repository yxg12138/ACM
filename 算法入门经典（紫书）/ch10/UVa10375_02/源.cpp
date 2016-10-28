/**************************
	wrong ³¬·¶Î§
**************************/
#include <cstdio>
#include <cstring>

const int maxn = 10000 + 5;
long long C[maxn][maxn];

void init(){
	memset(C, 0, sizeof(C));
	for (int i = 0; i < maxn; i++){
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
}

int main()
{
	init();
// 	int p, q, r, s;
// 	while (~scanf("%d%d%d%d",&p,&q,&r,&s))
// 	{
// 		double ans;
// 		printf("***************\n");
// 		printf("%lld %lld\n", C[p][q], C[r][s]);
// 		ans = C[p][q] * 1.0 / C[r][s]*1.0;
// 		printf("%.5lf\n", ans);
// 		printf("***************\n");
// 
// 	}
	printf("%lld\n", C[93][45]);
}