#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e5+10;
typedef long long ll;
int N,L[maxn];

void solve(){
	ll ans = 0;

	while(N>1){
		int min1 = 0,min2 = 1;
		if(L[min1] > L[min2]) swap(min1,min2);

		for(int i=2; i<N; i++){
			if(L[i] < L[min1]){
				min2 = min1;
				min1 = i;
			}
			else if(L[i] < L[min2]){
				min2 = i;
			}
		}

		int t = L[min1]+L[min2];
		ans += t;

		if(min1 == N-1) swap(min1,min2);
		L[min1] = t;
		L[min2] = L[N-1];
		N--;
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&L[i]);
	solve();
	
	return 0;
}