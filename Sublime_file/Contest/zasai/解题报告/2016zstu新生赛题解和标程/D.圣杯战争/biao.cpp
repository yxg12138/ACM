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
int a[M>>1], R[M<<1], SS, n, m, Q;
pair<int,int> ss[M];
ll g[M<<1];

//////////////////////////////////////////////////////////////////
struct Node {
	int maxr, maxlen;
	inline void init (int _maxr,int _maxlen) {
		maxr=_maxr, maxlen=_maxlen;
	}
}T[M*30];
int rt[M<<1], ls[M*30], rs[M*30];
struct Persist {
#define mid (l+r>>1)
	int MY;
	inline int alloc (int o) {
		ls[MY]=ls[o],rs[MY]=rs[o]; return MY++;
	}
	void build (int o,int l,int r) {
		T[o].init (-inf,-inf);
		if (l == r) return;
		build (ls[o]=MY++,l,mid);
		build (rs[o]=MY++,mid+1,r);
	}
	void ins (int o,int u,int l,int r,int x,int rr,int len){
		if (l==r) {T[u].init(rr,len); return;}
		if (x<=mid) ins(ls[o],ls[u]=alloc(ls[o]),l,mid,x,rr,len);
		else ins(rs[o],rs[u]=alloc(rs[o]),mid+1,r,x,rr,len);
		T[u].maxr= max(T[ls[u]].maxr, T[rs[u]].maxr);
		T[u].maxlen= max(T[ls[u]].maxlen, T[rs[u]].maxlen);
	}
	int askmaxr (int o,int l,int r,int pl,int pr) {
		if (pl>pr) return -1;
		if (pl<=l && r<=pr) return T[o].maxr;
		int ret=-inf;
		if (pl<=mid) ret=askmaxr (ls[o],l,mid,pl,pr);
		if (pr>mid) ret=max(ret,askmaxr(rs[o],mid+1,r,pl,pr));
		return ret;
	}
	int askmaxlen (int o,int l,int r,int pl,int pr) {
		if (pl<=l && r<=pr) return T[o].maxlen;
		int ret=-inf;
		if (pl<=mid) ret=askmaxlen (ls[o],l,mid,pl,pr);
		if (pr>mid) ret=max(ret, askmaxlen(rs[o],mid+1,r,pl,pr));
		return ret;
	}
	int bins (int o,int l,int r,int pl,int pr) {
		if (pl<=l&&r<=pr) {
			if (T[o].maxr<pr) return inf;
			if (l==r) return l;
		}
		int ret=inf;
		if (pl<=mid) ret=bins (ls[o],l,mid,pl,pr);
		if (ret!=inf) return ret;
		if (pr>mid) ret= bins (rs[o],mid+1,r,pl,pr);
		return ret;
	}
	int ask (int pl,int pr) {
		int ret = max (askmaxr(rt[pr],1,n,1,pl-1)-pl+1,
				max (pr-bins(rt[pr],1,n,pl,pr)+1,
					askmaxlen(rt[pr],1,n,pl,pr)));
		return max(min (ret, pr-pl+1), 0);
	}
#undef mid
}my;
//////////////////////////////////////////////////////////////////


int getr (ll x) {
	return upper_bound (g+1, g+1+n, x) - g-1;
}

int getl (int id,int x) {
	int l=1, r=id, ret=id;
	while (l<=r) {
		int mid=l+r>>1;
		if (g[id]-g[mid-1]>x) l=mid+1;
		else r=mid-1, ret=mid;
	}
	return ret;
}

int main () {
	freopen ("a.in", "r", stdin);
	freopen ("wrr.out", "w", stdout);
	int CASE;
	scanf ("%d", &CASE);
	while (CASE --) {
		//printf ("CASE=%d\n", CASE);
		scanf ("%d%d%d", &n,&m,&Q);
		for (int i=1; i<=n; i++) {
			scanf (LLD , g+i);
			g[i] += g[i-1];
		}
		for (int i=1; i<=m; i++) scanf("%d", a+i);
		memset (R, 0, sizeof(R[0])*(n+1));
		for (int i=1,x,l; i<=m; i++) {
			scanf ("%d", &x);
			if (x>g[a[i]]-g[a[i]-1]) {
				R[a[i]] = max(R[a[i]], getr(g[a[i]-1]+x));
				l = getl (a[i], x);
				R[l] = max (R[l], a[i]);
			}
		}
//////////////////////////////////////////////////////////////////
		SS=0, my.MY=0;
		my.build (rt[0]=my.MY++,1,n);
		for (int i=1; i<=n; i++)
			if (R[i]) ss[SS++] = MP(R[i],i);
		sort (ss, ss+SS);
		for (int i=1,j=0,lst; i<=n; i++) {
			rt[i]=rt[i-1];
			if (R[i]) my.ins(rt[i-1],rt[i]=my.alloc(rt[i-1]),1,n,i,R[i],-inf);
			while (j<SS && ss[j].fi==i) {
				rt[i]=my.alloc(lst=rt[i]);
				my.ins (lst,rt[i],1,n,ss[j].se,ss[j].fi,ss[j].fi-ss[j].se+1);
				j ++;
			}
		}
//////////////////////////////////////////////////////////////////
		int l, r, ans=0;
		while (Q --) {
			scanf ("%d%d", &l,&r);
			//printf ("l=%d,r=%d\n", l, r);
			l^=ans, r^=ans; if (l>r) swap(l,r);
			//printf ("l=%d,r=%d\n", l, r);
			printf ("%d\n", ans=my.ask(l,r));
		}
	}
	showtime;
	return 0;
}
