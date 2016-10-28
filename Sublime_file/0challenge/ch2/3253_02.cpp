//优先队列
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 2e5+10;
typedef long long ll;
int N,L[maxn];

void solve(){
	ll ans = 0;

	priority_queue<int,vector<int>,greater<int> > que;
	for(int i=0; i<N; i++)
		que.push(L[i]);

	while(que.size() > 1){
		int l1,l2;
		l1 = que.top(),que.pop();
		l2 = que.top(),que.pop();
		int t = l1+l2;
		ans += t;
		que.push(t);;
	}
	printf("%lld\n",ans);
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&L[i]);
	solve();
	
	return 0;
}