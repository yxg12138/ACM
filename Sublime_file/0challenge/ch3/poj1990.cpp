#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const int maxn = 2e5+10;

pair<int,int> cow[maxn];
int N;
ll cnt_bit[maxn],dis_bit[maxn];

ll sum(ll* bit,int i){
    ll s = 0;
    while(i > 0){
        s += bit[i];
        i -= i&-i;
    }

    return s;
}

ll sum(ll* bit,int from,int to){
    return sum(bit,to-1) - sum(bit,from-1);
}

void add(ll* bit,int i,ll x){
    while(i <= maxn){
        bit[i] += x;
        i += i&-i;
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d%d",&cow[i].first,&cow[i].second);

    sort(cow,cow+N);

    ll res = 0;
    for(int i=0; i<N; i++){
        int v = cow[i].first, x = cow[i].second;
        ll left = sum(cnt_bit,1,x), right = sum(cnt_bit,x+1,maxn);
        res += v*(left*x-(sum(dis_bit,1,x)) + (sum(dis_bit,x+1,maxn) - right*x));
        add(cnt_bit,cow[i].second,1);
        add(dis_bit,cow[i].second,cow[i].second);
    }

    printf("%lld\n",res);

    return 0;
}
