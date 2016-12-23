#include <bits/stdc++.h>
using namespace std;

typedef pair<string,int> P;
const int INF = 1<<30;

string str;
int dir[4] = {-1,1,-4,4};
map<string,int> dp;


void bfs(){
	queue<string> Q;
	Q.push("01234567");
	dp["01234567"] = 0;

	while(!Q.empty()){
		string now = Q.front(); Q.pop();
		int p;
		for(int i=0; i<8; i++) if(now[i]=='0'){
			p = i;
			break;
		}

		for(int i=0; i<4; i++){
			int next = p+dir[i];
			if(next>=0 && next<8 && !(p==3&&i==1) && !(p==4 && i==0)){
				string nn = now;
				swap(nn[p],nn[next]);
				if(dp.find(nn) == dp.end()){
					dp[nn] = dp[now]+1;
					Q.push(nn);
				}
			}
		}
	}
}

int main(){
	bfs();
	while(getline(cin,str)){
		str.erase(remove(str.begin(),str.end(),' '),str.end());
		printf("%d\n",dp[str]);
	}

}