#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 2005;

int N,cnt;
char S[maxn];

void solve(){
	int a = 0,b = N-1;
	while(a <= b){
		bool left = false;
		for(int i=0; a+i<=b; i++){
			if(S[a+i]<S[b-i]){
				left = true;
				break;
			}else if(S[a+i]>S[b-i]){
				left = false;
				break;
			}
		}

		if(left) cout << S[a++],cnt++;
		else cout << S[b--],cnt++;
		if(cnt%80==0) printf("\n");
	}
	printf("\n");
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> S[i];

	solve();

}