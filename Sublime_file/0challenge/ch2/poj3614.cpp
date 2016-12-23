#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 3000;

int C,L;
priority_queue<int,vector<int>, greater<int> > Q;
pair<int,int> cow[maxn],bot[maxn];

int main(){
	scanf("%d%d",&C,&L);
	for(int i=0; i<C; i++) scanf("%d%d",&cow[i].first,&cow[i].second);
	for(int i=0; i<L; i++) scanf("%d%d",&bot[i].first,&bot[i].second);
	
	sort(cow,cow+C);
	sort(bot,bot+L);

	int j=0,ans=0;

	for(int i=0; i<L; i++){
		while(j<C && cow[j].first<=bot[i].first){
			Q.push(cow[j].second);
			j++;
		}

		while(!Q.empty() && bot[i].second){
			int x=Q.top(); Q.pop();
			if(x<bot[i].first) continue;
			ans++;
			bot[i].second--;
		}
	}	

	printf("%d\n",ans);

}