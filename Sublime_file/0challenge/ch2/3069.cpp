#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000+10;
int N,R;
int x[maxn];

void solve(){
	sort(x,x+N);

	int i = 0,ans = 0;
	while(i < N){
		int s = x[i++];
		while(i<N && x[i]<=s+R) i++;

		int p = x[i-1];
		while(i<N && x[i]<=p+R) i++;

		ans++;
	}

	printf("%d\n",ans);

}

int main(){
	scanf("%d%d",&N,&R);
	for(int i=0; i<N; i++)
		scanf("%d",&x[i]);
	solve();
}