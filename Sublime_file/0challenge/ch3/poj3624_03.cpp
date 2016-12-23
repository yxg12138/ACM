#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const int maxn = 2e5+10;

int fmaxx[maxn][20],fminn[maxn][20];

int N,Q;

void init(){
    int lg = floor(log10(double(N))/log10(double(2)));

    for(int j=1; j<=lg; j++){
        for(int i=1; i<=N+1-(1<<j); i++){
            fmaxx[i][j] = max(fmaxx[i][j-1],fmaxx[i+(1<<(j-1))][j-1]);
            fminn[i][j] = min(fminn[i][j-1],fminn[i+(1<<(j-1))][j-1]);
        }
    }
}

int main()
{
    int x,le,ri,lg;

    scanf("%d%d",&N,&Q);

    for(int i=1; i<=N; i++){
        scanf("%d",&x);
        fmaxx[i][0] = fminn[i][0] = x;
    }

    init();

    for(int i=0; i<Q; i++){
        scanf("%d%d",&le,&ri);
        if(le > ri) swap(le,ri);
        lg = floor(log10(double(ri-le+1))/log10(double(2)));

        printf("%d\n",max(fmaxx[le][lg],fmaxx[ri-(1<<lg)+1][lg]) -
                      min(fminn[le][lg],fminn[ri-(1<<lg)+1][lg]));
    }

    return 0;
}
