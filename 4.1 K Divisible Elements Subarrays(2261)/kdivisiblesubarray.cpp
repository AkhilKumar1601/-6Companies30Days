#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
      unordered_set<string> s;
      for(int i = 0; i < nums.size(); i++){
          for(int j = i; j < nums.size(); j++){
              int count = 0; 
              string temp = "";
              for(int m = i; m <= j; m++){
                  temp.push_back(nums[m]);
                  if(nums[m] % p == 0) count++;
                  if(count > k) break;
              }
             if(count <= k){
                  s.insert(temp);
             }
          }
      }
      return s.size(); 
    }
};