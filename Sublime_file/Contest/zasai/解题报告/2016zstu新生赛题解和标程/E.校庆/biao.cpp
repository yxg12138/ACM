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

int year, month, date;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main () {
	freopen("read.txt", "r", stdin);
	freopen("wr.txt", "w", stdout);
	int CASE;
	for (int i=1; i<13; i++) a[i]+=a[i-1];
	int flag = 2016*365+2016/4-2016/100+2016/400+a[9]+28;
	scanf ("%d", &CASE);
	while (CASE --) {
		scanf ("%d%d%d", &year, &month, &date);
		int tmp = (year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400+a[month-1]+date;
		if ((year%4==0&&year%100!=0) || (year%400==0)) 
			if (month>=3) tmp++;
		printf ("%d\n", flag-tmp);
	}
	return 0;
}
