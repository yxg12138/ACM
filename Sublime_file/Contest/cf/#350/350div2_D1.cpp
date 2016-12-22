#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005],b[1005],minn = 0xffffff;

int main()
{
	int n,k,t,sum=0;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	for(int i=1; i<=n; i++)
		scanf("%d",&b[i]);
	while(k>=0)
	{
		for(int i=1; i<=n; i++)
		{
			if(b[i]/a[i] < minn)
			{
				minn = b[i]/a[i];
				t = i;
			}
		}
		int tmp = a[t]-b[t]%a[t];
		if(k<tmp)  break;
		else
		{
			k -= tmp;
			b[t] += tmp;
			minn = b[t]/a[t];
		}
	}
	printf("%d\n",minn);

}