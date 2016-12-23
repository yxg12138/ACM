#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

struct edge{
	int to,dis,cost;
	edge(){}
	edge(int to,int dis,int cost) : to(to),dis(dis),cost(cost){}
};

typedef pair<int,int> P;

vector<edge> G[maxn];

int d[maxn];
int V,M;

void dijkstra(int s){
	priority_queue<P> Q;
	memset(d,0x3f,sizeof(d));
	d[s] = 0;
	Q.push(P(0,s));

	while(!Q.empty()){
		P p = Q.top(); Q.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i=0; i<G[v].size(); i++){
			edge e = G[v][i];
			if(d[e.to] > d[v]+e.dis){
				d[e.to] = d[v]+e.dis;
				Q.push(P(-d[e.to],e.to));
			}
		}
	}
}


int main(){
	while(scanf("%d%d",&V,&M) && V){
		for(int i=0; i<V; i++) G[i].clear();

		for(int i=0; i<M; i++){
			int u,v,d,c;
			scanf("%d%d%d%d",&u,&v,&d,&c);
			--u,--v;
			G[u].push_back(edge(v,d,c));
			G[v].push_back(edge(u,d,c));
		}

		dijkstra(0);

		int ans = 0;
		for(int i=1; i<V; i++){
			int min_cost = 0x3f3f3f3f;
			for(int j=0; j<G[i].size(); j++){
				if(d[G[i][j].to]+G[i][j].dis==d[i] && G[i][j].cost<min_cost)
					min_cost = G[i][j].cost;
			}
			ans += min_cost;
		}
		printf("%d\n",ans);	
	}
}