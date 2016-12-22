#include <iostream>
using namespace std;

int main()
{
	long long n,x,k=0,ans=0,maxn=0;
	for(int i=1; i<=n; i++)
	{
		cin>>x;
		if(x>k)
		{
			ans++;
			k = x;
		}
		else
		{
			if(ans>maxn)
				maxn= ans;
			k = x;
			ans = 1;
		}
	}
	cout << ans << endl;




	return 0;
}