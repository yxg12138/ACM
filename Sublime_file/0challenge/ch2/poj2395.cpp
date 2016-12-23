#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 2000+10;
const int maxe = 1e5+10;

int pa[maxn],rank[maxn];

void init(int n){
	for(int i=0; i<n; i++){
		pa[i] = i;
		rank[i] = 0;
	}
}

int find(int x){
	if(x==pa[x]) return x;
	else return pa[x] = find(pa[x]);
}

void unite(int x,int y){
	x = find(x); y = find(y);
	if(x==y) return;

	if(rank[x]<rank[y]){
		pa[x] = y;
	}else{
		pa[y] = x;
		if(rank[x]==rank[y])
			++rank[x];
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}

struct edge{
	int u,v,cost;
	edge(int u=0, int v=0, int cost=0) : u(u),v(v),cost(cost) {}
	bool operator<(const edge& rhs)const{
		return cost<rhs.cost;
	}	
};

edge es[maxe];
int V,E;

int kruskal(){
	sort(es,es+E);
	init(V);
	int res = 0;
	for(int i=0; i<E; i++){
		edge e = es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res = max(res,e.cost);
		}
	}

	return res;
}

int main(){
	scanf("%d%d",&V,&E);
	for(int i=0; i<E; i++){
		scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
		--es[i].u,--es[i].v;
	}

	printf("%d\n",kruskal());

}