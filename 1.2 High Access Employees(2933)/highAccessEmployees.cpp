#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> mp;

        //Creation of map.
        for(auto& it : access_times){//it by reference isliya taki employee ki copy create na ho
            string employeeName = it[0];
            int time = stoi(it[1]);
            mp[employeeName].push_back(time);
        }

        vector<string> ans;

        //Sort Access time of each employee - used to find access time is high or not.
        for(auto& it : mp){
            sort(it.second.begin(),it.second.end());  //vector of time sort ho jayaga.
            vector<int>& time = it.second;
            for(int i = 2; i < time.size(); i++){
                //Check High Access employee. 
                if(time[i] - time[i -2] < 100){ //100 means 1 hr - 1:00.
                    ans.push_back(it.first);
                    break;
                }
            }
        }

        return ans;
    }
};