#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30;
typedef long long ll;
ll n,a,b,c;
ll pr[4];
ll ans;

struct node{
	int cnt;
	ll p;
	node(int cnt=0,int p=0) : cnt(cnt),p(p) {}
};

void bfs(int cnt,int p){
	int k = 0;
	ans = INF;
	queue<node> q;
	q.push(node(cnt,p));

	while(!q.empty()){
		k++;
		if(k == 1000) break;
		node t = q.front(); q.pop();

		if(t.cnt % 4 == 0) ans = min(ans,t.p);
		if(t.cnt%4 && t.p<ans){
			for(int i=1; i<=3; i++){
				q.push(node(t.cnt+i,t.p+pr[i]));
			}
		}
	}

}


int main(){
	cin >> n >> a >> b >> c;
	int t = n%4;
	
	if(t){
		pr[1] = a;
		pr[2] = min(a*2,b);
		pr[3] = min(c,min(a*3,a+b));
		bfs(t,0);
		cout << ans << endl;
	}else{
		cout << 0 << endl;
	}


}