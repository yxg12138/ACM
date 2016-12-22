#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
char s[maxn];

int main(){
	scanf("%s",s);
	int len = strlen(s);

	int cnt=0;
	for(int i=0; i<len-1; i++){
		while(s[i]==s[i+1]) i++;
		cnt++;
	}
	if(s[len-2]!=s[len-1]) cnt++;
	printf("%d\n",cnt-1);
}