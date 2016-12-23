#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 1e5+10;
int n,m,a[maxn];
int I[maxn],J[maxn],K[maxn];

int num[maxn];
vector<int> dat[maxn*4];

void build(int rt,int le,int ri){
	if(ri-1==le){
		dat[rt].push_back(a[le]);
	}else{
		int m = (le+ri)/2;
		int lch = rt*2+1, rch = rt*2+2;
		build(lch,le,m);
		build(rch,m,ri);
		dat[rt].resize(ri-le);
		merge(dat[lch].begin(),dat[lch].end(),dat[rch].begin(),dat[rch].end(),
			 dat[rt].begin());
	}
}

int query(int a,int b,int x,int rt,int le,int ri){
	if(le>=b || ri<=a) return 0;
	else if(le>=a && ri<=b){
		return upper_bound(dat[rt].begin(),dat[rt].end(),x) - dat[rt].begin();
	}else{
		int lch =rt*2+1, rch = rt*2+2;
		int m = (le+ri)/2;
		int lc = query(a,b,x,lch,le,m);
		int rc = query(a,b,x,rch,m,ri);
		return lc+rc;
	}
}

void solve(){
	for(int i=0; i<n; i++) num[i] = a[i];
	sort(num,num+n);

	build(0,0,n);
	for(int i=0; i<m; i++){
		int le=I[i],ri=J[i]+1,k=K[i];
		int lb=-1,ub=n-1;
		while(ub-lb>1){
			int mid=(ub+lb)/2;
			int c = query(le,ri,num[mid],0,0,n);
			if(c >= k) ub = mid;
			else lb = mid;
		}

		printf("%d\n",num[ub]);
	}

}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);

	for(int i=0; i<m; i++){
		scanf("%d%d%d",&I[i],&J[i],&K[i]);
		I[i]--,	J[i]--;
	}

	solve();

}