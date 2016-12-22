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
ll h[M];
int R[M], n, k, Q;

struct Babylon {
#define mid (l+r>>1)
	struct Node {
		int maxv, maxr;
		inline void init (int _maxv,int _maxr) {
			maxv=_maxv, maxr=_maxr;
		}
	}T[M<<2];
	void build (int o,int l,int r) {
		if (l == r) {T[o].init(R[l]-l+1,R[l]); return;}
		build (lson); build (rson);
		T[o].maxv=max(T[o<<1].maxv, T[o<<1|1].maxv);
		T[o].maxr=max(T[o<<1].maxr, T[o<<1|1].maxr);
	}
	int bins (int o,int l,int r,int pl,int pr) {
		if (pl<=l && r<=pr) {
			if (T[o].maxr<pr) return -1;
			if (l == r) return l;
		}
		int ret=-1;
		if (pl<=mid) ret=bins(lson,pl,pr);
		if (~ret) return ret;
		if (pr>mid) ret=bins(rson,pl,pr);
		return ret;
	}
	int ask (int o,int l,int r,int pl,int pr) {
		if (pl>=pr) return 1;
		if (pl<=l && r<=pr) return T[o].maxv;
		int ret=-1;
		if (pl<=mid) ret=ask (lson,pl,pr);
		if (pr>mid) ret=max(ret, ask(rson,pl,pr));
		return ret;
	}
	int ask (int pl,int pr) {
		int x = bins (1,0,n-1,pl,pr);
		return max(pr-x+1, ask(1,0,n-1,pl,x-1));
	}
#undef mid
}my;

int main () {
	freopen ("a.in", "r", stdin);
	freopen ("w.txt", "w", stdout);
	int CASE;
	scanf ("%d", &CASE);
	while (CASE --) {
		scanf ("%d%d%d", &n,&k,&Q);
		for (int i=0; i<n; i++) scanf (LLD, h+i);
		ll tmp = 1;
		int L=0;
		for (int i=0; i<n; i++, tmp+=k) { 
			while (h[i]<tmp) {
				R[L++] = i-1;
				tmp-=k;
			}
		}
		for (int i=L; i<n; i++) R[i] = n-1;
//////////////////////////////////////////////////////////////////
		my.build (1,0,n-1);
		int l, r;
		while (Q --) {
			scanf ("%d%d", &l,&r);
			printf ("%d\n", my.ask(--l,--r));
		}
	}
	showtime;
	return 0;
}
