#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int gcd(int a,int b){
	return b==0 ? a : gcd(b,a%b);
}

int p[maxn];

int main(){
	int n,cnt=0;
	cin >> n;
	for(int i=1; i<=n; i++){
		if(n%i==0) p[cnt++] = i;
	}

	int a,b,ans = 2e9;
	for(int i=0; i<cnt; i++){
		for(int j=i; j<cnt; j++){
			if(p[i]*p[j]==n && (p[j]-p[i])<ans){
				// cout << p[i] << " " << p[j] << endl;
				ans = p[j]-p[i];
				a = p[i], b =  p[j];
			}
		}
	}

	// int a,b;
	// long long t = (long long)(sqrt(n*1.0))+1;
	// if(abs(sqrt(n*1.0)-n/sqrt(n*1.0)) < 1e-30) {
	// 	cout << t-1 << " " << t-1 << endl;
	// 	return 0;
	// }
	// long long ans = 3e9;

	// for(int i=t,j=t; i>0 && j<=n; i--,j++){
	// 	if(i*j == n){
	// 		if((j-i) < ans){
	// 			ans = j-i;
	// 			a = i, b = j;
	// 		}
	// 	}
	// }

	cout << a << " " << b << endl;
}