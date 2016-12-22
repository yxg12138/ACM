#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5+10;
const ll INF = 1e18+10;
ll ans[maxn];

struct node{
	ll num;
	int pos;
}tree[maxn<<2];

void pushup(int pos){
	tree[pos].num = min(tree[pos<<1].num,tree[pos<<1|1].num);
}

void build(int l,int r,int pos){
	if(l == r){
		tree[pos].num = abs(ans[l]);
		tree[pos].pos = l;
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	pushup(pos);
}

void update(int p,ll v,int l,int r,int pos){
	if(p==r && p==l){
		tree[pos].num = abs(v);
		return;
	}
	int mid = (l+r) / 2;
	if(p <= mid)
		update(p,v,l,mid,pos<<1);
	else
		update(p,v,mid+1,r,pos<<1|1);
	pushup(pos);
}

int query(ll x,int l,int r,int pos){
	if(l==r && tree[pos].num==x)
		return tree[pos].pos;
	int mid = (l+r) / 2;
	if(tree[pos<<1].num == x)
		return query(x,l,mid,pos<<1);
	else
		return query(x,mid+1,r,pos<<1|1);
}

int main(){
	int n,m,k,flag=0;
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++){
		cin >> ans[i];
		if(ans[i] < 0) flag++;
	}
	build(1,n,1);
	while(m--){
		ll x = tree[1].num;
		int pos = query(x,1,n,1);
		if(flag & 1){
			if(ans[pos] >= 0)
				ans[pos] += k;
			else
				ans[pos] -= k;
			update(pos,ans[pos],1,n,1);
		}else{
			if(ans[pos] >= 0){
				ans[pos] -= k;
				if(ans[pos] < 0) flag++;
			}else{
				ans[pos] += k;
				if(ans[pos] >= 0) flag--;
			}
			update(pos,ans[pos],1,n,1);
		}
	}

	for(int i=1; i<=n; i++)
		cout << ans[i] << " ";
	cout << endl;
}