#include <bits/stdc++.h>
using namespace std;

set<pair<int,int> > p;

int gcd(int a,int b){
	return b==0 ? a : gcd(b,a%b);
}

int main(){
	int T,s,t;
	scanf("%d",&T);
	while(T--){
		int n;
		p.clear();
		scanf("%d%d%d",&s,&t,&n);
		int x,y;
		for(int i=0; i<n; i++){
			scanf("%d%d",&x,&y);
			x -= s,y -= t;		
			int k = gcd(x,y);	
			p.insert(make_pair(x/k,y/k));

		}
		printf("%d\n",p.size());

	}

}