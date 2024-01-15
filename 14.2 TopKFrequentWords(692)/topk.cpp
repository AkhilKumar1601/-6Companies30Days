#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string> x, pair<int, string> y) {
            if (x.first == y.first) {
                return x.second > y.second;
            } else {
                return x.first < y.first;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> M;
        for (auto word : words) {
            M[word] += 1;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto it = M.begin(); it != M.end(); it++) {
            pq.push({(*it).second, (*it).first});
        }

        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};