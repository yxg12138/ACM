#include <iostream>
using namespace std;
long long a[32] = {0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};
long long b[100005];

int _find(int x)
{
	int l=0,r=31;
	while(l<r)
	{
		int mid = (l+r)/2;
		if(x == a[mid]) return 1;
		else if(x > a[mid]) l = mid + 1;
		else r = mid - 1;
	}

	return 0;
}

int main()
{
	int n,ans=0;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> b[i];
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
		{
			if(_find(b[i]+b[j]))
				ans++;
		}
	cout << ans << endl;




	return 0;
}