#include <bits/stdc++.h>
using namespace std;

char str[120];

int main(){
	cin >> str;
	int le=0,ri=0,ans=0,flag=0,len = strlen(str);
	for(int i=0; i<len; i++){
		le = ri;
		if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='Y'){
			ri = i+1;
			flag = 1;
		}
		ans = max(ans,ri-le);
	}
	ans = max(ans,len-ri+1);	

	if(flag) cout << ans << endl;
	else cout << len+1 << endl;
}