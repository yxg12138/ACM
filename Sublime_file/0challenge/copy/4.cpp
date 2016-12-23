#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 3000;

int C,L;
pair<int,int> cow[maxn],spf[maxn];
priority_queue<int,vector<int>, greater<int> > Q;

int main(){
	scanf("%d%d",&C,&L);
	for(int i=0; i<C; i++)
		scanf("%d%d",&cow[i].first,&cow[i].second);
	for(int i=0; i<L; i++)
		scanf("%d%d",&spf[i].first,&spf[i].second);

	sort(cow,cow+C);
	sort(spf,spf+L);

	int j=0,ans=0;
	for(int i=0; i<L; i++){
		
		while(j<C && cow[j].first<=spf[i].first){
			Q.push(cow[j].second);
			j++;
		}

		while(!Q.empty() && spf[i].second){
			int x = Q.top(); Q.pop();
			if(x < spf[i].first) continue;
			ans++;
			spf[i].second--;
		}
	}
	printf("%d\n",ans);


}