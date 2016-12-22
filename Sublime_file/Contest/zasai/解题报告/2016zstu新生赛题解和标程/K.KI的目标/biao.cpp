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

const int M = 1000000+10;
struct Edge {
	int v,w,nxt;
	Edge () {}
	Edge (int _v,int _w,int _nxt):v(_v),w(_w),nxt(_nxt) {}
}e[M<<1];
int head[M], E;
int val[M];
int n;

int dfs (int o,int u,ll cur) {
	int ret=1;
	for (int i=head[u],v,w; ~i; i=e[i].nxt) {
		v=e[i].v, w=e[i].w;
		if (v==o) continue;
		//printf ("val[%d]=%d, cur-w=%lld\n", v,val[v], cur-w);
		if (val[v]<cur-w) {
			continue;
		}
		ret += dfs (u, v, max((ll)val[v],cur-w));
	}
	//printf ("u=%d, ret=%d\n", u, ret);
	return ret;
}

int main () {
	freopen ("K.in", "r", stdin);
	freopen ("wr.txt", "w", stdout);
	int CASE;
	scanf ("%d", &CASE);
	while (CASE --) {
		scanf ("%d", &n);
		memset (head, -1, sizeof(int)*(n+1));
		E=0;
		for (int i=1,u,v,w; i<n; i++) {
			scanf ("%d%d%d", &u, &v, &w);
			e[E] = Edge(v,w,head[u]);
			head[u] = E++;
			e[E] = Edge(u,w,head[v]);
			head[v] = E++;
		}
		for (int i=1; i<=n; i++) scanf ("%d", val+i);
		printf ("%d\n", dfs (1, 1, val[1]));
		//break;
	}
	showtime;
	return 0;
}
