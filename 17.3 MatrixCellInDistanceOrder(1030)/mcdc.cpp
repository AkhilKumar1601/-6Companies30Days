#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int maxDist = rows + cols - 1;
        vector<vector<vector<int>>> buckets(maxDist);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // push to bucket with abs(rCenter - i) + abs(cCenter - j) index.
                buckets[abs(rCenter - i) + abs(cCenter - j)].push_back({i, j});
            }
        }

        vector<vector<int>> cells;
        for (auto bucket : buckets) {
            for (auto cell : bucket) {
                cells.push_back(cell);
            }
        }

        return cells;
    }
};