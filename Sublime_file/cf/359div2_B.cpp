#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n,a[105];
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n; i++)
	{
		for(int j=1; j<n; j++)
		{
			if(a[j] < a[j-1])
			{
				swap(a[j-1],a[j]);
				printf("%d %d\n",j,j+1);
			}
		}
	}



	return 0;
}