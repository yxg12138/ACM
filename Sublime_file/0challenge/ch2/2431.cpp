#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1e4+10;
int L,P,N;
int A[maxn],B[maxn];

priority_queue<int> que;

void solve(){
	A[N] = L;
	B[N] = 0;
	N++;

	int ans = 0,pos = 0,tank = P;

	for(int i=0; i<N; i++){
		int d = A[i] - pos;

		while(tank - d < 0){
			if(que.empty()){
				puts("-1");
				return;
			}
			tank += que.top();
			que.pop();
			ans++;
		}

		tank -= d;
		pos = A[i];
		que.push(B[i]);
	}
	printf("%d\n",ans);
}


int main(){
	scanf("%d%d%d",&N,&L,&P);
	for(int i=0; i<N; i++)
		scanf("%d",&A[i]);
	for(int i=0; i<N; i++)
		scanf("%d",&B[i]);
	solve();
}