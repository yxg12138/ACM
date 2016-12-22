#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int n,k,a,b;
int BG[3];
char s[maxn];

int main(){
	BG[0] = 'G', BG[1] = 'B';
	cin >> n >> k >> a >> b;
	int t = 0, pp = 0;
	int cnt = 0, flag = 1;
	if(a > b) flag = 0;
	while(1){
		cnt = 0;
		// cout << "a " << a << "  " << "b " << b << endl;
		while(cnt < k){
			s[t++] = BG[flag];
			if(flag){
				// cout << "b " << b << endl;
				b--;
				if(b < 0) break;
			}
			else{ 
				// cout << "a " << a << endl;
				a--;
				if(a < 0) break;
			}
			if((flag && (b>=a)) || (!flag && (a>=b))) cnt++;
			else break;
			// cout << "a " << a << "  " << "b " << b << endl;
			if(t == n) pp = 1;
		}
		flag = !flag;
		if((a<0 && flag==1) || (b<0 && flag==0)) {
			break;
		} 
		if(pp) break;
	}
	if(pp){
		for(int i=0; i<n; i++)
			cout << s[i];
		cout << endl;
	}else{
		cout << "NO" << endl;
	}

}