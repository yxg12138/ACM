#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	int n,t;
	cin >> n >> t >> s;
	int i=0;
	while(s[i] != '.') i++;
	while(i<n && s[i]<'5') i++;
	if(i == n){
		cout << s << endl;
		return 0;
	}
	i--; int len=0;
	while(t>0){
		if(s[i] != '.') s[i]++;
		else{
			i--; len=i;
			while(i>=0 && s[i]=='9') s[i--] = '0';
			if(i == -1) cout << '1';
			else s[i]++;
			break;
		}
		if(s[i] < '5'){
			len = i;
			break;
		}else{
			len = i;
			i--;
		}

		t--;
	}

	for(int i=0; i<=len; i++)
		cout << s[i];
	cout << endl;
}

