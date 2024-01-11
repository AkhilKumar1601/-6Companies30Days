#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int index, int n){
        if(index == special.size()){
            int temp = 0;
            for(int i=0; i<n; i++){
                temp += (needs[i] * price[i]);
            }
            return temp;
        }

        int flag = 0;
        for(int i=0; i<n; i++){
            if(special[index][i] > needs[i]) flag = 1;
        }


        if(flag == 0){
            for(int i=0; i<n; i++){
                needs[i] -= special[index][i];
            }
            int consider = special[index][n] + solve(price, special,needs,index,n);
            for(int i=0; i<n; i++){
                needs[i] += special[index][i];
            }
            return min(consider, solve(price, special,needs,index+1,n));
        }

        return solve(price, special,needs,index+1,n);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price,special,needs,0,price.size());
    }
};