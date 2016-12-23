#include <bits/stdc++.h>
using namespace std;

const int maxk = 1e5;
const int maxx = 1e5;
int X,K,A[maxk];

bool win[maxx];

void solve(){
	win[0] = false; //轮到自己，没有硬币是必败态

	for(int j=1; j<=X; j++){
		win[j] = false;

		for(int i=0; i<K; i++)
			win[j] |= A[i]<=j && !win[j-A[i]];
	}

	if(win[X]) puts("Alice");
	else puts("Bob");
}

int main(){
	cin >> X >> K;
	for(int i=0; i<K; i++)
		cin >> A[i];

	solve();
}