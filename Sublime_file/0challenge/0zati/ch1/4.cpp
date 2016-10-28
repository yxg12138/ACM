//2.1.6
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int perm[maxn];

void permutation(int n){
	for(int i=0; i<n; i++)
		perm[i] = i;

	do{
		for(int i=0; i<n; i++)
			printf("%d ",perm[i]);
		printf("\n");
	}while(next_permutation(perm,perm+n));
	
}


int main(){
	int n;
	while(scanf("%d",&n)==1){
		permutation(n);
	}

}