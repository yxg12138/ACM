#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const int maxn = 1000+10;

bool is_prime[maxn];

void init(){
	int i,j;
	for(int i=0; i<=maxn; i++) is_prime[i] = true;

	is_prime[0] = is_prime[1] = false;
	for(i=2; i<=maxn; i++){
		if(is_prime[i]){
			for(j = i*i; j<=maxn; j+=i)
				is_prime[j] = false;
		}
	}
}

ll fact(int n){
	ll res = 1;
	while(n > 1){
		res *= n;
		n--;
	}

	return res;
}

P solve(int n){
	int i,j;
	queue<int> q;
	for(i=2; i<=maxn; i++){
		if(!is_prime[i]) continue;
		if(n%i == 0){
			j = 0;
			while(n%i == 0){
				n /= i;
				j++;
			}
			q.push(j);
			if(n == 1) break;
		}
	}

	if(n > 1) q.push(1);

	P res = P(0,1);
	while(!q.empty()){
		int m = q.front(); q.pop();
		res.first += m;
		res.second *= fact(m);
	}

	res.second = fact(res.first) / res.second;

	return res;
}

int main(){
	int n;
	init();
	while(cin >> n){
		P res = solve(n);
		printf("%lld %lld\n",res.first,res.second);
	}
}