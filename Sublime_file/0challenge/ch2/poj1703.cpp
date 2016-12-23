#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1e5*2+10;
int pa[maxn],rank[maxn];

void init(int n){
	for(int i=0; i<n; i++) {
		pa[i] = i;
		rank[i] = 0;
	}
}

int find(const int& x){
	if(pa[x]==x) return x;
	else return pa[x] = find(pa[x]);
}

void unite(int x,int y){
	x = find(x); y = find(y);
	if(x==y) return;
	if(rank[x]<rank[y]) pa[x] = y;
	else{
		pa[y] = x;
		if(rank[x]==rank[y])
			++rank[x];
	}
}

bool same(const int& x,const int& y){
	return find(x) == find(y);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,M;
		scanf("%d%d%*c",&N,&M);
		init(N*2);
		char op;
		int x,y;
		//getchar();
		while(M--){
			scanf("%c%d%d%*c",&op,&x,&y);
			if(op == 'A'){
				if(same(x,y))
					cout << "In the same gang." << endl;
				else if(same(x,y+N))
					cout << "In different gangs." << endl;
				else
					cout << "Not sure yet." << endl;
			}else{
				unite(x,y+N);
				unite(x+N,y);
			}
		}
	}
}