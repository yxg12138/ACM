#include <bits/stdc++.h>
using namespace std;

const int maxn = 300+10;
char s[maxn];

int main(){
	int n,cnt = 0, a=0,c=0,g=0,t=0;
	scanf("%d%s",&n,&s);
	for(int i=0; i<n; i++){
		if(s[i]=='?') {
			cnt++;
			continue;
		}
		if(s[i]=='A') a++;
		else if(s[i]=='C') c++;
		else if(s[i]=='G') g++;
		else if(s[i]=='T') t++;
	}

	int mx = n/4;
	if(mx < a || mx < g || mx < c || mx < t) {
		cout << "===\n";
		return 0;
	}
	int nd = (mx-a)+(mx-c)+(mx-g)+(mx-t);

	// cout << "mx" << mx << " nd" << nd << " cnt" << cnt << endl;


	if(cnt != nd || n%4!=0) cout << "===\n";
	else{
		for(int i=0; i<n; i++){
			if(s[i]=='?'){
				if(a<mx){
					a++;
					s[i] = 'A';
				}else if(c<mx){
					c++;
					s[i] = 'C';
				}else if(g<mx){
					g++;
					s[i] = 'G';
				}else if(t<mx){
					t++;
					s[i] = 'T';
				}
			}
		}
		printf("%s\n",s);
	}


}