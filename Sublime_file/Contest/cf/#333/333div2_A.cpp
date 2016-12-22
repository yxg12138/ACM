#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	long long x1, y1, x2, y2,tmp, i, j, a[100];
	long long sum1 = 0, sum2 = 0;
	scanf("%I64d %I64d", &x1, &y1);
	for (i = 0; i < x1; i++)
	{
		scanf("%I64d", &a[i]);
	}
	sum1 = a[x1 - 1];
	tmp = y1;
	for (i = x1 - 2; i >= 0; i--)
	{
		sum1 += a[i] * y1;
		y1 *= tmp;
	}
	scanf("%I64d %I64d", &x2, &y2);
	for (j = 0; j < x2; j++)
	{
		scanf("%I64d", &a[j]);
	}
	sum2 = a[x2 - 1];
	tmp = y2;
	for (j = x2 - 2; j >= 0; j--)
	{
		sum2 += a[j] * y2;
		y2 *= tmp;
	}
	if (sum1 == sum2)
		printf("=\n");
	if (sum1 > sum2)
		printf(">\n");
	if (sum1 < sum2)
		printf("<\n");


	return 0;
}