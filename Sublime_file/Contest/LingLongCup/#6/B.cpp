#include <iostream>
using namespace std;

typedef long long ll;

ll a,b,p;

ll a1[100] = {0,1,20,300,4000,50000,600000,7000000,80000000,900000000,10000000000};

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> a >> b >> p;

		ll ans = 0;
		for(ll i=a; i<=b; i++){
			int t = i;
			int k = ans;
			while(t){
				if(t%10 == p) {
					ans++;
				}
				t /= 10;
			}
			// if(ans-k > 1)
			// if(ans!=k)
			// 	cout << i << " ";
		}
		cout << endl;

		cout << ans << endl;
	}
}