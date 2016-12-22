#include <bits/stdc++.h>
using namespace std;

int a[105];

int main(){
	int T,n,cnt;
	cin >> T;
	while(T--){
		cnt = 0;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> a[i];
			if(a[i] == 1) cnt++;
		}

		 printf("%.2f\n",cnt*1.0/n);

	}
}