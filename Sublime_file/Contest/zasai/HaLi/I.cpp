#include <bits/stdc++.h>
using namespace std;

const int maxn = 6e4+10;

struct cmd{
	int type,x;
	cmd(int type=0,int x=0) : type(type),x(x) {}
}op[maxn];

bool ban[maxn], team[maxn], done[maxn];

int main(){
	int T;
	cin >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		for(int i=1; i<=m; i++){
			cin >> op[i].type >> op[i].x;
		}
		memset(done,false,sizeof(done));
		memset(ban,false,sizeof(ban));
		memset(team,false,sizeof(team));

		for(int i=m; i>=1; i--){
			if(ban[i]) continue;
			int tmp = op[i].x;
			if(op[i].type == 3){
				ban[tmp] = true;
			}else if(op[i].type == 2){
				if(!done[tmp]){
					team[tmp] = false;
					done[tmp] = true;
				}
			}else{
				if(!done[tmp]){
					team[tmp] = true;
					done[tmp] = true;
				}
			}
		}

		int cnt = 0;
		for(int i=1; i<=n; i++) if(team[i]) cnt++;
		cout << cnt << endl;
		for(int i=1; i<=n; i++){
			if(team[i])
				cout << i << " ";
		}
		cout << endl;
	} 

}