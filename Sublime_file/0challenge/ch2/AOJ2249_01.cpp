#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;

struct edge{
	int to,dis,cost;
	edge(){}
	edge(int to,int dis,int cost) : to(to),dis(dis),cost(cost){}
	bool operator>(const edge& rhs) const{
		return dis != rhs.dis ? dis>rhs.dis : cost>rhs.cost;
	}
};

int V,M;
bool vis[maxn];

vector<edge> G[maxn];

int dijkstra(int s){
	int res = 0;
	priority_queue<edge,vector<edge>,greater<edge> > Q;

	Q.push(edge(0,0,0));

	while(!Q.empty()){
		edge p = Q.top(); Q.pop();
		int v = p.to;
		if(vis[v]) continue;
		vis[v] = true;
		res += p.cost;
		for(int i=0; i<G[v].size(); i++){
			Q.push(edge(G[v][i].to,p.dis+G[v][i].dis,G[v][i].cost));
		}
	}

	return res;
}


int main(){
	while(scanf("%d%d",&V,&M) && V){
		memset(vis,0,sizeof(vis));
		for(int i=0; i<=V; i++) G[i].clear();

		for(int i=0; i<M; i++){
			int u,v,d,c;
			scanf("%d%d%d%d",&u,&v,&d,&c);
			--u,--v;
			G[u].push_back(edge(v,d,c));
			G[v].push_back(edge(u,d,c));
		}

		printf("%d\n",dijkstra(0));

	}
}