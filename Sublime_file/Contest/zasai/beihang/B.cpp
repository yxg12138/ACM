#include <iostream>
#include <cstring>
using namespace std;

int sc[10],ans;
double a[10],b[10];

int main(){
	int c[10];
	c[1] = 4; c[2] = 3; c[3] = 5;
	c[4] = 6; c[5] = 4; c[6] = 6;
	c[7] = 5; c[8] = 4; c[9] = 3;

	int T;
	cin >> T;
	while(T--){
		ans = 0;
		for(int i=1; i<=9; i++){
			for(int j=0; j<c[i]; j++)
				cin >> sc[j];
			for(int j=0; j<c[i]; j++)
				cin >> a[j];
			for(int j=0; j<c[i]; j++)
				cin >> b[j];

			for(int j=0; j<c[i]; j++){
				if(a[j]>=3 && b[j]>=3)
					ans += sc[j];
			}
		}

		cout << ans << endl;
	}
}