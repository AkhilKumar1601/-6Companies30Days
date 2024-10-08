#include<iostream>
using namespace std;

class Solution {
public:
    using ll =long long;
    ll mod=1e9+7;
    ll find(ll a,ll b)
    {
        ll res=1;
        while(b)
        {
            if(b&1)
            {
                res=((res%mod)*(a%mod))%mod;
            }
            a=((a%mod)*(a%mod))%mod;
            b>>=1;
        }
        return res%mod;
    }
    int minNonZeroProduct(int p) 
    {
        if(p==1)
        {
            return 1;
        }
        ll ans=0;
        ll x1=(1ll<<p)-1;
        ll x2=x1-1;
        ans=find(x2,x1/2)%mod;
        ans=((ans%mod)*(x1%mod))%mod;
        return (int)ans%mod;
    }
};