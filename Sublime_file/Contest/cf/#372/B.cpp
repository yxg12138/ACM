#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4+10;

char s[maxn];
int mask[maxn];

int main(){
	cin >> s;
	int len = strlen(s);
	memset(mask,-1,sizeof(mask));

	if(len < 26) {puts("-1"); return 0;}
	int i,j,k;
	for(i=0,j=0; j<len; j++){
		if(s[j] == '?'){
			if(j-i == 25) break;
			continue;
		}

		k = s[j] - 'A';
		if(mask[k] != -1){
			i = max(i,mask[k]+1);
			mask[k] = j;
		}else mask[k] = j;

		if(j-i == 25) break;
	}

	if(j==len || j-i<25) puts("-1");
	else{
		int x = 0;
		for(k=i; k<=j; k++){
			if(s[k] == '?'){
				for(; x<26 && mask[x]>=i; x++);
				s[k] = x+'A'; mask[x] = i;
			}
		}

		for(i=0; i<len; i++)
			if(s[i]=='?') s[i] = 'A';
		puts(s);
	}
}