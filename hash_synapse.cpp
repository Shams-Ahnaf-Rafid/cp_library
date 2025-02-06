#include<bits/stdc++.h>
using namespace std;

const int base1=1e6+3;
const int base2=998244353;
const int mod1=1e9+7;
const int mod2=1e9+9;

void init(string& str, int base, int mod, int hashv[],int basep[]){
    hashv[0]=str[0]-'\0'+1;
    for(int i=1;i<str.size();i++){
            hashv[i]=(1LL*hashv[i-1]*base+str[i]-'\0'+1)%mod;
    }
    basep[0]=1;
    for(int i=1;i<str.size();i++)basep[i]=(1LL*basep[i-1]*base)%mod;
}

int query(int i,int j,int hashv[],int basep[],int base,int mod){
    if(i==0)return hashv[j];
    int ans=(hashv[j]-1LL*hashv[i-1]*basep[j-i+1])%mod;
    if(ans<0)ans+=mod;
    return ans ;
}

int hash1[1200005],hash2[1200005],pow1[1200005],pow2[1200005];

void init(string& str){
    init(str,base1,mod1,hash1,pow1);
    init(str,base2,mod2,hash2,pow2);
}

long long int gethash(int i,int j){
    long long int ans=query(i,j,hash1,pow1,base1,mod1)*(1LL<<31)+query(i,j,hash2,pow2,base2,mod2);
    return ans;
}
