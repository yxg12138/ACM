#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	vector<pair<ll,ll> > ans;

	while(cin>>n){
		ll le=1,ri=1,sum=0,sq=0;

		for(;;){
			while(sum < n){
				sq = ri*ri;
				sum += sq;
				ri++;
			}

			if(sq > n)
				break;

			if(sum == n){
				ans.push_back(make_pair(le,ri));
			}
			sum -= le*le;
			le++;
		}

		printf("%d\n", ans.size());

		for(vector<pair<ll,ll> >::iterator it=ans.begin(); it!=ans.end(); it++){
			int b = it->first, e = it->second;
			printf("%d ",e-b);

			for(int i=b; i<e; i++){
				printf("%d ",i);
			}

			printf("\n");
		}

	}


}