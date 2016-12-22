
inline ll mul(ll a,ll b,ll mod){
	a = (a%mod + mod) % mod;
	b = (b%mod + mod) % mod;
	return ((a*b-(ll)((long double)a/mod*b + .5L) * mod) % mod + mod) % mod;
}