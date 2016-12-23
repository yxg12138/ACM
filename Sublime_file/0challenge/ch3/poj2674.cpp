#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

const int maxn = 32000+10;

struct node{
	double pos;
	char name[260];
	bool operator<(const node& rhs) const {
		return abs(pos) < abs(rhs.pos);
	}
};

node ih[maxn];

int main(){

	int N;
	while(cin>>N && N){
		double L,V;
		cin >> L >> V;
		for(int i=0; i<N; i++){
			char pn;
			cin >> pn >> ih[i].pos >> ih[i].name;
			if(pn=='n' || pn=='N'){
				ih[i].pos = -ih[i].pos;
			}
		}

		sort(ih,ih+N);

		double max_d = 0;
		int id = 0;
		bool right = true;

		for(int i=0; i<N; i++){
			double nd = (ih[i].pos<0 ? 0 : L) -ih[i].pos;
			if(nd > max_d+1e-6){
				max_d = nd;
				id = i;
				right = ih[i].pos>0;
			}
		}

		int cnt = 0;
		if(right){
			for(int i=id; i<N; i++){
				if(ih[i].pos<0)
					++cnt;
			}

			id += cnt;
		}else{
			for(int i=id; i>=0; i--){
				if(ih[i].pos>0)
					++cnt;
			}

			id -= cnt;
		}
		
		double res = max_d/V;

		//printf("%.2lf %s\n",res,ih[id].name);
		cout << setw(13) << fixed << setprecision(2) << (int)(res * 100) / 100.0 << ' ' << ih[id].name << endl;
	}


}