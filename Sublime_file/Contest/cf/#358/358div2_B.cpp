#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 100005;
long long a[maxn];

int main()
{
	int n,mex=1;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%I64d",&a[i]);
	sort(a,a+n);
	for(int i=0; i<n; i++)
		if(a[i] >= mex)
			mex++;

	printf("%d\n",mex);

	return 0;
}