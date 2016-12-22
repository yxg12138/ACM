#include <iostream>
#include <cstring>
using namespace std;


int main(){
	int T,n;
	cin >> T;
	while(T--){
		int t;
		cin >> n;
		if(n == 4){
			cout << 11 << " " << 4 << endl;
			continue;
		}
		if(n % 2){
			t = n / 2;
			cout << '7';
			for(int i=0; i<t-1; i++)
				cout << '1';
			cout << " " << "17";
			for(int i=0; i<t-2; i++)
				cout << '1';
			cout << endl;
		}else{
			t = n / 2;
			for(int i=0; i<t; i++)
				cout << '1';
			cout << " " << "77";
			for(int i=3; i<t; i++)
				cout << '1';
			cout << endl;

		}
	}
}