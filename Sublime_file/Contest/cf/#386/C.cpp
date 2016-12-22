#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
typedef long long ll;

ll s,x1,x2,t1,t2,p,d,dir;

int main(){
	cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;	
	if(x1 > x2) dir = 0;
	else dir = 1;

	ll minn = abs(x1-x2) * t2;

	if(d==-1) d=0;

	ll T,ss;
	if(d==0 && dir==0){
		if(p < x1){
			ss = p+s*2-x1;
			T = ss*t1+(x1-x2)*t1;
			minn = min(minn,T);
		}else{
			ss = p-x2;
			T = ss*t1;
			minn = min(minn,T);
		}
	}else if(d==0 && dir==1){
		ss = p + x2;
		T = ss*t1;
		minn = min(minn,T);
	}else if(d==1 && dir==0){
		ss = s*2-p-x2;
		T = ss*t1;
		minn = min(minn,T);
	}else if(d==1 && dir==1){
		if(p > x1){
			ss = s*2+x2-p;
			T = ss*t1;
			minn = min(minn,T);
		}else{
			ss = x1-p;
			T = ss*t1+(x2-x1)*t1;
			minn = min(minn,T);
		}
	}

	cout << minn << endl;
}