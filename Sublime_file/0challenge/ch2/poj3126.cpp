#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 10000+10;

bool is_prime[maxn];

void init(){
	int i,j;
	for(i=1000; i<maxn; i++){
		for(j=2; j<i; j++){
			if(i%j==0){
				is_prime[i] = false;
				break;
			}
		}
		if(i == j) is_prime[i] = true;
	}
}

int bfs(int first, int last){
	bool vis[maxn];
	queue<int> q;
	int v,i,j,tmp,vtmp,cnt[maxn],t[4];

	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));

	q.push(first);
	vis[first] = true;

	while(!q.empty()){
		v = q.front(); q.pop();

		t[0] = v/1000; t[1] = v%1000/100; t[2] = v%100/10; t[3] = v%10;

		for(j=0; j<4; j++){
			tmp = t[j];
			for(i=0; i<10; i++){
				if(i!=tmp){
					t[j] = i;
					vtmp = t[0]*1000+t[1]*100+t[2]*10+t[3];
					if(!vis[vtmp] && is_prime[vtmp]){
						cnt[vtmp] = cnt[v]+1;
						vis[vtmp] = true;
						q.push(vtmp);
					}
					if(vtmp == last) return cnt[vtmp];
				}
				t[j] = tmp;
			}
		}

		if(v == last) return cnt[v];
	}

	return -1;
}

int main(){
	int T,a,b,ans=0;
	init();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		ans = bfs(a,b);
		if(ans != -1) printf("%d\n",ans);
		else printf("Impossible\n");
	}

}