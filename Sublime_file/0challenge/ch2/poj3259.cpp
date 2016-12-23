#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int maxn = 3000;
int N,W,M;
vector<pair<int,int> > G[maxn];
int d[maxn],inq[maxn],cnt[maxn];
bool flag;

void init(){
	memset(d,0x3f,sizeof(d));
	memset(inq,0,sizeof(inq));
	memset(cnt,0,sizeof(cnt));
	for(int i=0; i<=N; i++) G[i].clear();
	flag = 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		
		scanf("%d%d%d",&N,&W,&M);
		init();
		int s,e,t;
		for(int i=0; i<W; i++){
			scanf("%d%d%d",&s,&e,&t);
			G[s].push_back(make_pair(e,t));
			G[e].push_back(make_pair(s,t));
		}
		for(int i=0; i<M; i++){
			scanf("%d%d%d",&s,&e,&t);
			G[s].push_back(make_pair(e,-t));
		}

		queue<int> Q;
		Q.push(1);
		d[1] = 0,inq[1] = 1,cnt[1]++;
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			for(int i=0; i<G[u].size(); i++){
				int v = G[u][i].first;
				if(d[u]+G[u][i].second<d[v]){
					d[v] = d[u]+G[u][i].second;
					if(inq[v] == 1) continue;
					inq[v] = 1;
					Q.push(v);
					cnt[v]++;
					if(cnt[v]>N-1) { flag=1; break;}
				}

			}
			inq[u] = 0;
			if(flag) break;
		}
		
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}