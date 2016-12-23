#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 4000+10;

int n;
int A[maxn],B[maxn],C[maxn],D[maxn];
int CD[maxn*maxn];


void solve(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			CD[i*n+j] = C[i]+D[j];
	}
	sort(CD,CD+n*n);

	long long res = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int cd = -(A[i]+B[j]);
			res += upper_bound(CD,CD+n*n,cd) - lower_bound(CD,CD+n*n,cd);
		}
	}
	printf("%lld\n",res);

}


int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&A[i]);
	for(int i=0; i<n; i++) scanf("%d",&B[i]);
	for(int i=0; i<n; i++) scanf("%d",&C[i]);
	for(int i=0; i<n; i++) scanf("%d",&D[i]);

	solve();
}

// 6
// -45 -41 -36 -36 26 -32
// 22 -27 53 30 -38 -54
// 42 56 -37 -75 -10 -6
// -16 30 77 -46 62 45
