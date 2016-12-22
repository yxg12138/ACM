#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5+10;

int mod[maxn];
ll last,le,ri,mid,q;

int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%d",&mod[i]);
		
		last = 1;
		for(int i=2; i<=n; i++){
			if(mod[i] < mod[last]){
				last++;
				mod[last] = mod[i];
			}
		}

		n = last;
		scanf("%d",&m);
		for(int i=1; i<=m; i++){
			scanf("%lld",&q);
			while(1){
				le = 0, ri = n+1;
				while(ri-le > 1){
					mid = (ri+le) / 2;
					if(mod[mid] <= q) ri = mid;
					else le = mid;
				}
				if(ri == n+1) break;
				q = q%mod[ri];
			}
			printf("%lld\n",q);
		}
	}
}