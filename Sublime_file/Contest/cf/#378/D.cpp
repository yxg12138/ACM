#include <bits/stdc++.h>
using namespace std;


int a[3];
map<pair<int,int>, int> ma;
map<pair<int,int>, int> id;

int main(){
	int n,g1=0,g2=0,mx=0;

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[0] >> a[1] >> a[2];
		sort(a,a+3);

		if(a[0] > mx){
			g1 = i;
			g2 = 0;
			mx = a[0];
		}

		if(min(ma[make_pair(a[1],a[2])]+a[0],a[1]) > mx){
			mx = min(ma[make_pair(a[1],a[2])]+a[0],a[1]);
			g1 = id[make_pair(a[1],a[2])];
			g2 = i;
		}


		if(a[0] > ma[make_pair(a[1],a[2])]){
			ma[make_pair(a[1],a[2])] = a[0];
			id[make_pair(a[1],a[2])] = i;
		}
	}

	if(g2 != 0) cout << 2 << "\n" << g1+1 << " " << g2+1 << endl;
	else cout << 1 << "\n" << g1+1 << endl;

}