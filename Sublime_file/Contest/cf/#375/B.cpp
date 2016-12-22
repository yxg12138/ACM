#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	char s[300];
	cin >> n >> s;

	int len=0,ans=-1, cnt=0;
	for(int i=0; i<n; i++){
		int j=i;
		while(s[j]!='(' && s[j]!='_' && j<n) j++;
		ans = max(j-i,ans);

		if(s[j] == '('){
			for(j++; j<n; j++){
				if(s[j] == ')') break;
				int o = j;
				while(s[o]!='_' && s[o]!=')' && o<n) o++;
				if(o != j) cnt++, j=o;
				if(s[o] == ')') break;
			}
		}
		i = j;
	}
	cout << ans << " " << cnt << endl;
}