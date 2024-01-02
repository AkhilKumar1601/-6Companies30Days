#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void solve(vector<string>& ans, string digits, string mapping[], string output, int in){
        //Base Case
        if(in >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[in] - '0';
        string value = mapping[number];

        for(int i = 0; i < value.length(); i++){
            output.push_back(value[i]);
            solve(ans,digits,mapping,output,in+1);
            output.pop_back(); //backtracking.
        }
    }
public:
    vector<string> letterCombinations(string digits) {
      vector<string> ans;
      if(digits.length() == 0)return ans;
      string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

      string output = "";
      solve(ans,digits,mapping,output,0);
      return ans;
    }
};