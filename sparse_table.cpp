#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int K = 20;

int n,l,r;
int a[N];
int sp[K][N];
int spx[K][N];

void sparse_min () {
    for(int i = 0; i < n; i++) sp[0][i] = a[i];
    for(int len = 1; len < K; len++) {
        for(int st = 0; st < n; st++) {
            if(st+(1<<len)>n) break;
            sp[len][st] = min (sp[len-1][st], sp[len-1][st+(1<<(len-1))]);
        }
    }
}

void sparse_max () {
    for(int i = 0; i < n; i++) spx[0][i] = a[i];
    for(int len = 1; len < K; len++) {
        for(int st = 0; st < n; st++) {
            if(st+(1<<len)>n) break;
            spx[len][st] = min (spx[len-1][st], spx[len-1][st+(1<<(len-1))]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    //for idempotent function ( min,max,gcd )
    //O(1)
    //int msb = 31-__builtin_clz(r-l+1);
    //int ans = min(sp[msb][l],sp[msb][r-(1<<msb)+1]);
    return 0;
}
