#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct edge{
	int to,cost;
	edge(){}
	edge(int to,int cost) : to(to),cost(cost){}
};

const int maxn = 1000+10;
int d[maxn][maxn];
int V,M,E,X;

typedef pair<int,int> P;

vector<edge> G[maxn];

void dijkstra(int s){
	priority_queue<P> Q;
	memset(d[s],0x3f,sizeof(d[s]));
	d[s][s] = 0;
	Q.push(P(0,s));

	while(!Q.empty()){
		P p = Q.top(); Q.pop();
		int v = p.second;
		if(d[s][v] < p.first) continue;
		for(int i=0; i<G[v].size(); i++){
			edge e = G[v][i];
			if(d[s][e.to] > d[s][v]+e.cost){
				d[s][e.to] = d[s][v]+e.cost;
				Q.push(P(-d[s][e.to],e.to));
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&V,&M,&X);
	--X;
	for(int i=0; i<V; i++) d[i][i] = 0;
	while(M--){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		--u,--v;
		G[u].push_back(edge(v,c));
	}

	for(int i=0; i<V; i++){
		dijkstra(i);
	}

	int ans = 0;
	for(int i=0; i<V; i++){
		ans = max(ans,d[i][X]+d[X][i]);
	}

	printf("%d\n",ans);

	return 0;
}