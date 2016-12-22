#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int _K=50268147,_B=6082187,_P=100000007;
int _X;
int row[1000006],col[1000006];
inline int get_rand(int _l,int _r){
	_X=((long long)_K*_X+_B)%_P;
	return _X%(_r-_l+1)+_l;
}
int n,m,k,seed,mxx=-1,mxy=-1;
int x[1000006],y[1000006];
void Init(){
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	scanf("%d%d%d%d",&n,&m,&k,&seed);
	_X=seed; mxx=-1,mxy=-1;
	for (int i=1;i<=k;++i){
		x[i]=get_rand(1,n),
		y[i]=get_rand(1,m);
		row[x[i]] = 1;
		col[y[i]] = 1;
	}
}


int main(){
	int T;
	cin >> T;
	while(T--){
		Init();
		int a1=0,a2=0,f=0;

		for(int j=1; j<=m; j++){
			if(col[j] == 0){
				a1++;
			}
		}

		for(int j=1; j<=n; j++){
			if(row[j] == 0){
				a2++;
			}
		}

		cout << a2 << " " << a1 << endl;
	}
}