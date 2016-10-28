#include <iostream>
using namespace std;

int main()
{
	int n,i,j,a[105],vis[105] = {0},sum=0;
	cin >> n;
	for(i=1; i<=n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int ave = 2*sum/n;
	for(i=1; i<=n; i++)
	{	
		if(!vis[i])
			for(j=1; j<=n; j++)
			{
				if(!vis[j])
				{
					if(a[i]+a[j] == ave && i!=j)
					{
						if(a[i] <= a[j])
							cout << i << " " << j << endl;
						else
							cout << j << " " << i << endl;
						vis[i] = 1,vis[j] = 1;
						break;
					}
				}

			}
	}

	return 0;
}