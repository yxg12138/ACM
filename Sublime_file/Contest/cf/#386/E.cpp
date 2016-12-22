#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

int n,m,x,f[maxn];
set<int> s;
int a[maxn];

int main(){
	cin >> n >> m;
	int om,em;
	if(m%2) om=m/2+1, em=m/2;
	else om=em=m/2;
	int odd=0,even=0;
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		if(s.count(x)) f[i] = 1;
		else a[i] = x,s.insert(x);
		if(x%2) odd++;
		else even++;
	}

	int k = 1,flag = 0;
	if(odd <= even) k=1;
	else k=2;
	int cnt = 0;
	for(int i=n-1; i>=0; i--){
		cout << odd << " " << even << "a : " << a[i] << endl;
		if(a[i]==0 || (odd<=even)){
			k = 1;
			while(k<=m && s.count(k)!=0){
				k += 2;
			}
			if(k > m) {
				flag = 1; break;
			}
			s.insert(k);
			cnt++;
			a[i] = k;
			cout << "change: " << a[i] << endl;
			even--,odd++;
		}else if(a[i]==0 || (odd>even)){
			k = 2;
			while(k<=m && s.count(k)!=0){
				k += 2;
			}
			if(k > m) {
				flag = 1; break;
			}
			s.insert(k);
			cnt++;
			a[i] = k;
			cout << "change: " << a[i] << endl;
			odd--,even++;
		}
	}
	if(odd == even && flag==0){
		cout << cnt << endl;
		for(int i=0; i<n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}else {
		cout << -1 << endl;
	}
}