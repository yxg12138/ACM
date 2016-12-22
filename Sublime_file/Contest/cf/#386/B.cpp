#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3+10;

char ch[maxn],s[maxn];
int len;

int main(){
	cin >> len >> ch;
	if(len%2){
		int l,r;
		int i = (len+1) / 2;
		s[i] = ch[0];
		int cnt = 1;
		l = i-1, r = i+1;

		while(1){
			if(l<0 || r<0) break;
			if(cnt%2)
				s[l] = ch[cnt++],l--;
			else
				s[r] = ch[cnt++],r++;
			
			if(cnt == len) break;
		}
	}else{
		int l,r;
		int i = len / 2;
		s[i] = ch[0];
		int cnt = 1;
		l = i-1, r = i+1;
		while(1){
			if(l<0 || r<0) break;
			if(cnt%2)
				s[r] = ch[cnt++],r++;
			else
				s[l] = ch[cnt++],l--;
			
			if(cnt == len) break;
		}
	}
	for(int i=1; i<=len; i++)
		cout << s[i];
	cout << endl;
}