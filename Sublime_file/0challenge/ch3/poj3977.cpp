#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;
const int maxn = 40;

ll num[maxn];

ll ll_abs(ll x){
	return x>=0 ? x : -x;
}

int main(){
	int n;
	while(cin>>n && n){
		for(int i=0; i<n; i++) cin >> num[i];

		map<ll,int> dp;
		pair<ll,int> res(ll_abs(num[0]),1);

		for(int i=0; i<(1<<(n/2)); i++){
			ll sum = 0;
			int cnt = 0;
			for(int j=0; j<(n/2); j++){
				if((i>>j)&1){
					sum += num[j];
					++cnt;
				}
			}

			if(cnt==0) continue;

			map<ll,int>::iterator it = dp.find(sum);

			if(it != dp.end())
				it->second = min(it->second,cnt);
			else
				dp[sum] = cnt;

			res = min(res,make_pair(ll_abs(sum),cnt));
		}

		for(int i=0; i<(1<<(n-n/2)); i++){
			ll sum = 0;
			int cnt = 0;

			for(int j=0; j<(n-n/2); j++){
				if((i>>j) & 1){
					sum += num[n/2+j];
					++cnt;
				}
			}

			if(cnt == 0) continue;

			res = min(res,make_pair(ll_abs(sum),cnt));

			map<ll,int>::iterator it = dp.lower_bound(-sum);

			if(it!=dp.end()){
				res = min(res,make_pair(ll_abs(sum+it->first),cnt+it->second));
			}

			if(it != dp.begin()){
				--it;
				res = min(res,make_pair(ll_abs(sum+it->first),cnt+it->second));
			}
		}

		cout << res.first << " " << res.second << endl;
	}


}
