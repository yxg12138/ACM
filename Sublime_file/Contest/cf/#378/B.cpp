#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
long long le[maxn],ri[maxn];
long long ans,tmpr,tmpl,maxr,maxl,sum1,sum2,n,flag;

int main()
{
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> le[i] >> ri[i];
		if(ri[i]-le[i] > maxr){
			tmpr = i;
			maxr = ri[i]-le[i];
		}
		if(le[i]-ri[i] > maxl){
			tmpl = i;
			maxl = le[i]-ri[i];
		}
		sum1 += le[i];
		sum2 += ri[i];
	}

	if((abs(sum1-sum2) < abs(sum1-le[tmpr]+ri[tmpr]-(sum2-ri[tmpr]+le[tmpr])))){
		ans = tmpr;
		flag = 1;
	}
	if(abs(sum1-sum2) < abs(sum1+ri[tmpl]-le[tmpl]-(sum2-ri[tmpl]+le[tmpl]))){
		ans = tmpl;
		flag = 1;
	}
	if(abs(sum1-le[tmpr]+ri[tmpr]-(sum2-ri[tmpr]+le[tmpr])) < abs(sum1+ri[tmpl]-le[tmpl]-(sum2-ri[tmpl]+le[tmpl]))){
		ans = tmpl;
		flag = 1;
	}
	if(abs(sum1-le[tmpr]+ri[tmpr]-(sum2-ri[tmpr]+le[tmpr])) > abs(sum1+ri[tmpl]-le[tmpl]-(sum2-ri[tmpl]+le[tmpl]))){
		ans = tmpr;
		flag = 1;
	}
	if(!flag) ans = 0;
	cout << ans << endl;
	
	return 0;
}