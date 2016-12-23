#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
const int maxn = 1e5+10;

int n,c,f;
priority_queue<int> Q;

struct node{
	int sc;
	int re;
}cow[maxn];

bool cmp(node a,node b){
	if(a.sc == b.sc)
		return a.re < b.re;
	return a.sc > b.sc;
}

int sum,dp_le[maxn],dp_ri[maxn];
int main(){
	scanf("%d%d%d",&n,&c,&f);
	for(int i=0; i<c; i++){
		scanf("%d%d",&cow[i].sc,&cow[i].re);
	}

	sort(cow,cow+c,cmp);
	int nu = n/2;

	for(int i=0; i<nu; i++){
		Q.push(cow[i].re);
		sum += cow[i].re;
	}
	dp_le[nu-1] = sum;

	for(int i=nu; i<c; i++){
		if(cow[i].re >= Q.top())
			dp_le[i] = sum;
		else{
			sum = sum - Q.top() + cow[i].re;
			Q.pop();
			Q.push(cow[i].re);
			dp_le[i] = sum;
		}
	}
	sum = 0;
	while(!Q.empty()) Q.pop();

	for(int i=c-1; i>=c-nu; i--) {
		Q.push(cow[i].re);
		sum += cow[i].re;
	}
	dp_ri[c-nu] = sum;

	for(int i=c-nu-1; i>=0; i--){
		if(cow[i].re >= Q.top())
			dp_ri[i] = sum;
		else{
			sum = sum - Q.top() + cow[i].re;
			Q.pop();
			Q.push(cow[i].re);
			dp_ri[i] = sum;
		}
	}

	bool flag = false;
	for(int i=nu; i<c-nu; i++){
		if(cow[i].re + dp_le[i-1] + dp_ri[i+1] <= f){
			flag = true;
			printf("%d\n",cow[i].sc);
			break;
		}
	}
	if(!flag) printf("-1\n");

}