#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

map<int,int> q;
multiset<int> q0;
multiset<int> q1;
multiset<int>::iterator it;

int i,j,t,n,m,c;
struct P{
	int a,b;
}L[maxn];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1; i<=n; i++)
			scanf("%d%d",&L[i].a,&L[i].b);
		for(i=1; i<=m; i++){
			scanf("%d",&c);
			q[c]++;
		}

		for(i=n-1; i>=1; i--){
			q[i] += q[i+1];
		}

		for(i=1; i<=n; i++){
			L[i].b += q[i];
			//cout << L[i].b << endl;
		}

		for(i=1; i<=n; i++){
			if(L[i].a == 0){
				while(q1.size()){
					it = q1.begin();
					if(*it < L[i].b){
						q1.erase(it);
					}else{
						break;
					}
				}
				q0.insert(L[i].b);
			}
			else if(L[i].a == 1){
				while(q0.size()){
					it = q0.begin();
					if(*it < L[i].b){
						q0.erase(it);
					}else{
						break;
					}
				}
				q1.insert(L[i].b);
			}
		}

		cout << q0.size()+q1.size() << endl;
		q.clear(); q0.clear(); q1.clear();
	}
}