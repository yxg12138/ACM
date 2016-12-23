#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e5+5;

ll sum[maxn*4],add[maxn*4];

struct node{
	int l,r;
	int mid() { return (l+r)/2; }
}tree[maxn*4];

void pushup(int rt){
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushdown(int rt,int m){
	if(add[rt]){
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += add[rt] * (m-(m>>1));
		sum[rt<<1|1] += add[rt] * (m>>1);
		add[rt] = 0;
	}
}

void build(int l,int r,int rt){
	tree[rt].l = l;
	tree[rt].r = r;
	add[rt] = 0;
	if(l == r){
		scanf("%lld",&sum[rt]);
		return;
	}

	int m = tree[rt].mid();
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void update(int va,int l,int r,int rt){
	if(tree[rt].l==l && tree[rt].r==r){
		add[rt] += va;
		sum[rt] += va*(r-l+1);
		return;
	}

	if(tree[rt].l == tree[rt].r) return;
	pushdown(rt,tree[rt].r-tree[rt].l+1);
	int m = tree[rt].mid();
	if(r <= m) update(va,l,r,rt<<1);
	else if(l>m) update(va,l,r,rt<<1|1);
	else{
		update(va,l,m,rt<<1);
		update(va,m+1,r,rt<<1|1);
	}

	pushup(rt);
}

ll query(int l, int r, int rt){
	if(tree[rt].l==l && tree[rt].r==r) return sum[rt];
	pushdown(rt,tree[rt].r-tree[rt].l+1);
	int m = tree[rt].mid();
	ll res = 0;
	if(r<=m) res += query(l,r,rt<<1);
	else if(l>m) res += query(l,r,rt<<1|1);
	else{
		res += query(l,m,rt<<1);
		res += query(m+1,r,rt<<1|1);
	}
	return res;

}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		build(1,n,1);
		while(m--){
			char ch[2];
			scanf("%s",ch);
			int a,b,c;
			if(ch[0] == 'Q'){
				scanf("%d%d",&a,&b);
				printf("%lld\n",query(a,b,1));
			}else{
				scanf("%d%d%d",&a,&b,&c);
				update(c,a,b,1);
			}
		}
	}
}
