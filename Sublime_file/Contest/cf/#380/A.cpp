#include <bits/stdc++.h>
using namespace std;

int n;
char stra[200];
char og[2];

int main(){
	og[0] = 'o';
	og[1] = 'g';
	cin >> n >> stra;
	for(int i=0; i<n; i++){
		if(!(stra[i]=='o' && stra[i+1]=='g' && stra[i+2]=='o')){
			putchar(stra[i]);
			continue;
		}
		int flag = 0;
		// cout << i << " ";
		int j;
		for(j=i; j<n; j++){
			if(stra[j] != og[flag]){
				if(flag==1) i = j-1;
				else i = j-2;
				break;
			}
			if(j==n-1 && flag) {
				i=j-1;break;
			}

			flag = !flag;
		}
		
		putchar('*');putchar('*');putchar('*');
		if(j == n) break;
	}
	puts("");
	return 0;
}