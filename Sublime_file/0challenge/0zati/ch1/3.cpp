//2.1.6
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
bool used[maxn];
int perm[maxn];

void permutation1(int pos,int n){

	if(pos == n-1){
		for(int i=0; i<n; i++)
			printf("%d ",perm[i]);
		printf("\n");
	}

	for(int i=0; i<n; i++){
		if(!used[i]){
			perm[pos] = i;
			used[i] = 1;
			permutation1(pos+1,n);
			used[i] = false;
		}
	}
}

int main(){
	int n;
	while(scanf("%d",&n)==1){
		memset(used,0,sizeof(used));	
		permutation1(0,n);
	}
	
}