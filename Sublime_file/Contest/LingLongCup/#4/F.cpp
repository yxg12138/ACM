#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n%4==1 || n%4==0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}