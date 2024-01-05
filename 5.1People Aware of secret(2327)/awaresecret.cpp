#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> v(2001,0);
        int mod = pow(10,9) + 7;

        v[1] = 1;   //Person1 discovers a secret.

        for(int i = 0; i < n; i++){
            for(int j = i + delay; j < i + forget; j++){
                v[j] = (v[j] + v[i]) % mod;//j[k] - how many person know the secret, j[i] - to how many they share the secret.
            }
        }

        int i = 0; 
        long long int totalPersonKnowSecret = 0;
        
        while(forget--){
            totalPersonKnowSecret = (totalPersonKnowSecret + v[n-i]) % mod;
            i++;
        }

        return totalPersonKnowSecret;
    }
};