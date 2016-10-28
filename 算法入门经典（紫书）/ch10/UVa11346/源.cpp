#include <cstdio>
#include <cmath>

int main(){
	double a, b, s;
	scanf("%lf%lf%lf", &a, &b, &s);
	double m = a*b;
	double ans;
	if (s < 1e-6) ans = 1;
	else if (s > m)  ans = 0;
	else ans = (m - s - s*log(m / s)) / m;
	printf("%.2lf\%\n", ans*100);

}