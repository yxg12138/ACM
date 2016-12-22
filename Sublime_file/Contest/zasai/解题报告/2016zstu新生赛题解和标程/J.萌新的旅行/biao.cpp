#include <stdio.h>
#include <time.h>
#include <bitset>
#include <string.h>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <math.h>
#include <queue>
#include <complex>
#include <functional>
#include <limits.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define pi (acos(-1.0))
#define fi first
#define se second
#define lson (o<<1),l,mid
#define rson (o<<1|1),mid+1,r
#define MP make_pair
#define sqr(x) ((x)*(x))
#define ALL(v) (v).begin(),(v).end()
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)
const double eps = 1e-9 ;
const int inf = 0x3f3f3f3f ;
const ll INF = (ll)4e18 ;
const int MOD=91250681,BAS=257;
inline int sign(double x){return x<-eps?-1:x>eps;}
inline int clz(int x){return __builtin_clz(x);}
inline int clz(ll x){return __builtin_clzll(x);}
inline int lg2(int x){return !x ? -1 : 31-clz(x);}
template <class T> inline int SZ(T x){return (int)x.size();}

const int M = 100000+10;
int a[M<<1], n;
int ans[M];
int T[M<<1<<2];
struct Segtree {
#define mid (l+r>>1)
	void build (int o,int l,int r) {
		if (l == r) {T[o]=a[l];return;}
		build (lson); build (rson);
		T[o] = min(T[o<<1], T[o<<1|1]);
	}
	int bins (int o,int l,int r,int x,int minn) {
		if (l>=x) {
			if (T[o]>=minn) return -1;
			if (l == r) return l;
		}
		int ret=-1;
		if (x<=mid) ret = bins(lson,x,minn);
		if (~ret) return ret;
		return bins (rson,x,minn);
	}
#undef mid
}sgt;

int main () {
	freopen ("J3.in", "r", stdin);
	freopen ("w3.txt", "w", stdout);
	int CASE;
	scanf ("%d", &CASE);
	while (CASE --) {
		scanf ("%d", &n);
		for (int i=0; i<n; i++) scanf ("%d", a+i);
		for (int i=0,x; i<n; i++) {
			scanf ("%d", &x);
			a[i]-=x;
			a[i+n] = a[i];
		}
		for (int i=1; i<2*n; i++) a[i]+=a[i-1];
		a[2*n] = INT_MIN;
		sgt.build (1,0,2*n);
		ans[0] = sgt.bins(1,0,2*n,0,0)+1;
		if(ans[0]==0) ans[0]=1;
		ans[0] = min (ans[0], n);
		int maxn=ans[0];
		for (int i=1; i<n; i++) {
			ans[i] = sgt.bins(1,0,2*n,i,a[i-1]);
			if (ans[i]==-1) ans[i]=1;
			else ans[i]-=i-1;
			ans[i] = min (ans[i], n);
			maxn = max(maxn, ans[i]);
		}
		vector<int> b;
		for (int i=0; i<n; i++) {
			if (ans[i]==maxn) b.push_back (i);
		}
		//int sz = SZ(b);
		for (int i=0; i<b.size(); i++)
			printf("%d%c", b[i]," \n"[i==(int)b.size()-1]);
	}
	showtime;
	return 0;
}
