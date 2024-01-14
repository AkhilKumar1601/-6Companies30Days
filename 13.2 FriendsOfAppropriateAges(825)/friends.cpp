#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int freq[120+1]={};//age frequency        
        for(int age:ages) {
            freq[age]++;
        }
        //
        int result=0;
        int fromAge=0;//minimum age of request for current step = start of window
        int countRequests=0; //sum[ freq[fromAge].. freq[age] ]
        for(int age=0; age<=120; ++age) {
            //
            countRequests+=freq[age];//right pointer move - update window
            //
            int minAge=age/2+7;//minimum age 
            while((fromAge<=minAge) and (fromAge<age)) { //move left pointer if needed
                countRequests-=freq[fromAge];
                fromAge++;
            }
            if (age<=minAge) continue; //first rule
            result+= (countRequests-1)*freq[age];
        }
        return result;
    }
};