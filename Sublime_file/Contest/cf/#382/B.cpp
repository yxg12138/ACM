#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int a[maxn];

int main(){
	int n,n1,n2;
	cin >> n >> n1 >> n2;
	if(n1 > n2) swap(n1,n2);

	for(int i=0; i<n; i++)
		cin >> a[i];

	sort(a,a+n);

	long long sum1=0,sum2=0;
	for(int i=n-1; i>=n-n1; i--)
		sum1 += a[i];
	for(int i=n-n1-1; i>=n-n1-n2; i--)
		sum2 += a[i];

	double ans = (1.0*sum1/n1) + (1.0*sum2/n2);

	printf("%.8lf\n",ans);

}