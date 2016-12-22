#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int x, a[105] = {0}, sum = 0,min = 10000;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &x);
		a[x]++;
		sum += x;
	}
	int tmp = sum;
	for (int i = 100; i >= 0; i--)
	{
		if (a[i] == 2)
			sum -= 2 * i;
		if (a[i] >= 3)
			sum -= 3 * i;
		if (sum < min)
			min = sum;
		sum = tmp;
	}
	printf("%d\n", min);



	return 0;
}