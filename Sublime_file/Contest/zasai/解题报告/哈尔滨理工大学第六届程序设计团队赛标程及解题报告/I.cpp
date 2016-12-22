#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
#define MAXN (60000)
struct cmd{
	int type,x;
	cmd(int type=0,int x=0):type(type),x(x) {};
}op[MAXN];
bool ban[MAXN],team[MAXN],done[MAXN];
int main (int argc, char *argv[])
{
	std::ios::sync_with_stdio(false);
	int noc;cin>>noc;
	while (noc--){
		int n,m;cin>>n>>m;
		FOR(i,1,m){
			cin>>op[i].type>>op[i].x;
		}
		memset(done,false,sizeof done);
		memset(ban,false,sizeof ban);
		memset(team,false,sizeof team);
		for(int i=m;i>=1;i--){
			if (ban[i])	continue;
			int temp=op[i].x;
			if (op[i].type==3){
				ban[temp]=true;
			}else if (op[i].type==2){
				if (!done[temp]){
					team[temp]=false;
					done[temp]=true;
				}
			}else{
				if (!done[temp]){
					team[temp]=true;
					done[temp]=true;
				}
			}
		}
		int cnt=0;
		FOR(i,1,n)	if (team[i])	cnt++;
		cout<<cnt<<endl;
		FOR(i,1,n)	if (team[i])	cout<<i<<" ";cout<<endl;
	}
	return 0;
}
