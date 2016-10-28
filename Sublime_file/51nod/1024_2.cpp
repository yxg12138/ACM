#include <bits/stdc++.h>
using namespace std;

set<double> s;

int main()
{
	int m,n,a,b;
	scanf("%d%d%d%d",&m,&n,&a,&b);
	for(int i=a; i<a+n; i++)
		for(int j=b; j<b+m; j++)
		{
			s.insert(1.0*j*log2(1.0*i));
		}
	printf("%d\n",s.size());


	return 0;
}
