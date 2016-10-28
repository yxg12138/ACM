#include <cstdio>
int main(){
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
		printf("%.5lf\n", (a*b + b*(b - 1))*1.0 / (a + b)*(a + b - c - 1));
}