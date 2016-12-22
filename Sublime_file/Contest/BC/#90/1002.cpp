#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[100005],pa[100005],d[100005];

int main(){
	int T,n,x;
	scanf("%d",&T);
	while(T--){
		memset(d,0,sizeof(d));
		scanf("%d",&n);
		d[0] = 0;
		for(int i=1; i<n; i++){
			scanf("%d",&x);
			d[i] = d[x]+1;
		}
		long long s = 0;

		for(int i=0; i<n; i++){
			scanf("%I64d",&a[i]);
		}
		for(int i=0; i<n; i++){
			if(d[i] % 2) s ^= a[i];
		}
		if(s != 0) cout << "win\n";
		else cout << "lose\n";
	}
}