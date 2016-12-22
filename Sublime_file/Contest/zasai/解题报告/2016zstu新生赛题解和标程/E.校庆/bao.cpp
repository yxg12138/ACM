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

int year, month, date;

int main() {
	freopen ("a.in", "r", stdin);
	int CASE;
	scanf ("%d", &CASE);
	while (CASE --) {
		scanf ("%d%d%d", &year,&month,&date);
		//printf ("%d %d %d\n", year, month, date);
		int cnt = 0;
		while (true) {
			if (year==2017&&month==10&&date==28) break;
			//printf ("%d %d %d\n", year, month, date);
			if(month==1) {
				if (date==31) month=2, date=1;
				else date ++;
			} else if (month==2) {
				if ((year%4==0&&year%100!=0) || (year%400==0)) {
					if(date==29)month=3, date=1;
					else date++;
				} else {
					if(date==28)month=3, date=1;
					else date++;
				}
			} else if (month==3) {
				if (date==31) month=4, date=1;
				else date++;
			} else if (month==4) {
				if (date==30) month=5, date=1;
				else date++;
			} else if (month==5) {
				if (date==31) month=6, date=1;
				else date++;
			} else if (month==6) {
				if (date==30) month=7, date=1;
				else date++;
			} else if (month==7) {
				if (date==31) month=8, date=1;
				else date++;
			} else if (month==8) {
				if (date==31) month=9, date=1;
				else date++;
			} else if (month==9) {
				if (date==30) month=10, date=1;
				else date++;
			} else if (month==10) {
				if (date==31) month=11, date=1;
				else date++;
			} else if (month==11) {
				if (date==30) month=12, date=1;
				else date++;
			} else {
				if (date==31) month=1, date=1, year++;
				else date++;
			}
			cnt ++;
			//if (year==2017&&month==10&&date==28) break;
		}
		printf ("%d\n", cnt);
	}
	return 0;
}
