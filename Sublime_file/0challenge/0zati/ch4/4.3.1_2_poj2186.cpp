#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e4+10;
const int maxm = 5e4+10;
int N,M;
int A[maxm],B[maxm];
vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;
bool used[maxn];
int cmp[maxn];

void add_edge(int from,int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v){
	used[v] = 1;
	for(int i=0; i<G[v].size(); i++)
		if(!used[G[v][i]]) dfs(G[v][i]);
	vs.push_back(v);
}


void rdfs(int v,int k){
	used[v] = 1;
	cmp[v] = k;
	for(int i=0; i<rG[v].size(); i++){
		if(!used[rG[v][i]]) rdfs(rG[v][i],k);
	}
}

int scc(){
	memset(used,0,sizeof(used));
	vs.clear();
	for(int v=0; v<N; v++)
		if(!used[v]) dfs(v);

	memset(used,0,sizeof(used));
	int k = 0;
	for(int i=vs.size()-1; i>=0; i--)
		if(!used[vs[i]]) rdfs(vs[i],k++);

	return k;
}

void solve(){
	int n = scc();

	int u=0,num=0;
	for(int v=0; v<N; v++){
		if(cmp[v]==n-1) {
			u = v;
			num++;
		}
	}

	memset(used,0,sizeof(used));
	rdfs(u,0);
	for(int i=0; i<N; i++){
		if(!used[i]){
			num = 0;
			break;
		}
	}

	printf("%d\n",num);
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0; i<M; i++){
		scanf("%d%d",&A[i],&B[i]);
		add_edge(A[i]-1,B[i]-1);
	}

	solve();
}