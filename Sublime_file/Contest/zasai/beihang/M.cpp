#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5+10;

int a[maxn],b[maxn];
long long ans;

bool cmp(int p,int q){
	return p > q;
}

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		ans = 0;
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%d",&a[i]);
		for(int i=0; i<n; i++) scanf("%d",&b[i]);

		sort(a,a+n);
		sort(b,b+n,cmp);

		for(int i=0; i<n; i++){
			ans += a[i]*b[i];
		}

		printf("%lld\n",ans);
	}
}