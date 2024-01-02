#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalRows,totalCols;
    int rowIndex = 0,colIndex = 0; // start with first row and first column
    Solution(int m, int n) {
        this->totalRows = m;
        this->totalCols = n;
    }
    
    vector<int> flip() {
        int flippedRowIndex = rowIndex, flippedColIndex = colIndex; // for returning purpose
        if(colIndex + 1 < totalCols) colIndex++; // will iterate over columns till we can
        else if(rowIndex + 1 < totalRows){ // will switch to next row and first col
            rowIndex++;
            colIndex = 0;
        }
        else rowIndex = 0,colIndex = 0; // will point back to first row and col
        // work as reset and continue to cycle again
        return {flippedRowIndex,flippedColIndex};
    }
    
    void reset() {
        // no need of it, we have taken care of it in the flip() part
    }
};
