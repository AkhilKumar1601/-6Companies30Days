#include<iostream>
#include<limits.h>

using namespace std;

#define ll long long 

class Solution {
public:
    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
    }

    int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a * b) / gcd(a, b);
    }
    //Don't need to write gcd and lcm function my compiler doesn't support c++17 version that's why i have to.
    
    bool possibleAns(ll d1,ll d2,ll uC1, ll uC2,ll mid){
        ll divByD1 = mid/d1, divByD2 = mid/d2;
        ll notDivByD1 = mid - divByD1, notDivByD2 = mid - divByD2;
        ll notDivByD1D2 = mid - mid/lcm(d1,d2);

        if(notDivByD1 >= uC1 && notDivByD2 >= uC2 && notDivByD1D2 >= uC1 + uC2){
            return true;
        } 
        return false;
    }
    int minimizeSet(int d1, int d2, int uC1, int uC2) {
        ll ans = INT_MAX, l = 1, h = INT_MAX;

        while(l <= h){
            ll mid = l + (h-l)/2;
            if(possibleAns(d1,d2,uC1,uC2,mid)){
                ans = min(ans,mid);
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};