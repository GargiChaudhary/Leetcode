"""
Problem link: https://leetcode.com/problems/champagne-tower/
We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.
Example:
Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). 
There will be no excess liquid so all the glasses under the top glass will remain empty.
"""
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0) return 0;
        vector<vector<double>> v(102, vector<double>(102,0));
        v[0][0] = (double)poured;
        for(int i = 0; i < query_row; i++){
            for(int j = 0; j <= i; j++){
                double flow = (v[i][j]-1.0)/2.0;
                if(flow > 0){
                    v[i+1][j] += flow;
                    v[i+1][j+1] += flow;
                }
            }
        }
        return min(1.0, v[query_row][query_glass]);
    }
};

