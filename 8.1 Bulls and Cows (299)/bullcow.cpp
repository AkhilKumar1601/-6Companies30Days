#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> secret_freq;
        unordered_map<char,int> guess_freq;

        int bulls = 0, cows = 0;

        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]) bulls++;
            else{
                secret_freq[secret[i]]++;
                guess_freq[guess[i]]++;
            }
        }

        for(auto it : guess_freq){
            cows += min(it.second,secret_freq[it.first]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};