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

int V,M,E,X;

typedef pair<int,int> P;

vector<vector<edge> > G(maxn);
vector<vector<edge> > RG(maxn);

int d[maxn];
int rd[maxn];

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
			if(d[e.to] > d[v]+e.cost){
				d[e.to] = d[v]+e.cost;
				Q.push(P(-d[e.to],e.to));
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&V,&M,&X);
	--X;

	while(M--){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		--u,--v;
		G[u].push_back(edge(v,c));
		RG[v].push_back(edge(u,c));
	}

	dijkstra(X);

	G = RG;
	memcpy(rd,d,sizeof(d));
	dijkstra(X);

	for(int i=0; i<V; i++)
		d[i] += rd[i];

	printf("%d\n",*max_element(d,d+V));

	return 0;
}