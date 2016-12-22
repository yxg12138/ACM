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
#define sqr(x) (x)*(x)
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

const int M = 1000+10;
int cnt[M], n;

int main () {
	freopen ("read.txt", "r", stdin);
	freopen ("w.txt", "w", stdout);
	int CASE;
	scanf ("%d", &CASE);
	while (CASE --) {
		scanf ("%d", &n);
		int maxn = 0;
		memset (cnt, 0, sizeof(cnt));
		for (int i=0, x; i<n; i++) {
			scanf ("%d", &x);
			cnt[x] ++;
			maxn = max(maxn, cnt[x]);
		}
		for (int i=1, flag=0; i<=1000; i++) {
			if (cnt[i]==maxn) {
				if (flag) printf(" %d", i);
				else printf ("%d", i), flag=1;
			}
		} puts ("");
	}
	return 0;
}
