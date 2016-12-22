/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
WA51
从前往后考虑是错的	出现本来考试的那天其实是用来复习的问题。
因为一场考试可能有多个天数可以考，但考试天数处于后面的拥有的复习天数总是比天数处于前面的要多，所以从后往前考虑不会有问题
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

#include <bits/stdc++.h>  
using namespace std;

const int maxn = 1e5+10;

int d[maxn],a[maxn];

int main()  
{  
	int n,m;  
	cin>>n>>m;  
	
	for(int i=0; i<n; i++)
		cin >> d[i];  
	for(int i=0;i<m;i++)
		cin >> a[i];

	sort(a,a+m);

	int cnt = 0, ptr = 0, ans = 0;
	  
	for(int i=0; i<n; i++){
		if(ptr == m) {
			ans = i;
			break;
		}
		if(d[i] == 0) cnt++;
		else{
			if(cnt < a[ptr])
				cnt++;
			else{
				cnt -= a[ptr];
				ptr++;
			}
		}
	}

	if(ptr != m) cout << -1 << endl;
	else{
		if(ans == 0) cout << n << endl;
		else cout << ans << endl;
	}
}  