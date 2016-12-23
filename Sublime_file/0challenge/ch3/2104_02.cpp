#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


const int maxn = 1e5+10;
int n,m,a[maxn];
int num[maxn];
int I[maxn],J[maxn],K[maxn];

vector<int> dat[maxn*4];

void build(int rt,int le,int ri){
    if(ri-1 == le){
        dat[rt].push_back(a[le]);
    } else{
        int m = (le+ri)/2;
        build(rt*2+1,le,m);
        build(rt*2+2,m,ri);
        dat[rt].resize(ri-le);
        merge(dat[rt*2+1].begin(),dat[rt*2+1].end(),dat[rt*2+2].begin(),dat[rt*2+2].end(),dat[rt].begin());
    }
}

int query(int i,int j,int x,int rt,int le,int ri){
    if(j<=le || i>=ri) return 0;
    else if(i<=le && j>=ri){
        return upper_bound(dat[rt].begin(),dat[rt].end(),x) - dat[rt].begin();
    }else{
        int lc = query(i,j,x,rt*2+1,le,(le+ri)/2);
        int rc = query(i,j,x,rt*2+2,(le+ri)/2,ri);
        return lc+rc;
    }
}


void solve(){
    for(int i=0; i<n; i++) num[i] = a[i];
    sort(num,num+n);

    build(0,0,n);

    for(int i=0; i<m; i++){
        int le = I[i], ri = J[i]+1, k = K[i];

        int lb = -1, ub = n-1;
        while(ub-lb>1){
            int mid = (ub+lb)/2;
            int c = query(le,ri,num[mid],0,0,n);

            if(c >= k) ub = mid;
            else lb = mid;
        }

        printf("%d\n",num[ub]);
    }
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&I[i],&J[i],&K[i]);
        I[i]--,J[i]--;
    }

    solve();

    return 0;
}
