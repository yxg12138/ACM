#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define left lll
#define right rrr
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
typedef long long LL;
int a[200000+233];
int n,m;
LL last,left,right,mid,q;
int main (int argc, char *argv[])
{
	int noc;scanf("%d",&noc);
	while (noc--){
		int n;scanf("%d",&n);
		FOR(i,1,n)	scanf("%d",&a[i]);
		last=1;
		FOR(i,2,n){
			if (a[i]<a[last]){
				last++;
				a[last]=a[i];
			}
		}
		n=last;
		scanf("%d",&m);
		FOR(i,1,m){
			scanf("%lld",&q);
			while (1){
				left=0;
				right=n+1;
				while (right-left>1){
					mid=(right+left)/2;
					if (a[mid]<=q){
						right=mid;
					}else left=mid;
				}
				if (right==n+1)	break;
				q=q%a[right];
			}
			printf("%lld\n",q);
		}
	}
	return 0;
}
