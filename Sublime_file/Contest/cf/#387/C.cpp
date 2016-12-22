#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
const int maxt = 1e6+10;
typedef long long ll;
int n,q,cnt[maxt];
ll ans[maxn];

struct node{
	int t,k,d;
}p[maxn];

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1; i<=q; i++){
		scanf("%d%d%d",&p[i].t,&p[i].k,&p[i].d);
	}

	int a[105],cnt = n,r;
	memset(a,0,sizeof(a));

	for(int i=1; i<=q; i++){
		// if(p[i].k > cnt) ans[i] = -1;
		// else{
			r = 0;
			for(int j=1; j<=n; j++){
				if(a[j] <= p[i].t) {
					// cout << "j" << j << endl;
					r++;
					if(r == p[i].k) break;
				}		
			}
			int c=0;
			if(r == p[i].k){
				for(int j=1; j<=n; j++){
					if(a[j] <= p[i].t) {
						// cout << "j" << j << endl;
						a[j] = p[i].t+p[i].d;
						// cout << "a " << a[j] << endl;
						ans[i] += j;
						c++;
						if(c == p[i].k) break;
					}				
				}
			}

			if(r!=p[i].k) ans[i]=-1;
			cout << ans[i] << endl;
		// }
	}


}