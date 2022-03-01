"""
Problem link: https://leetcode.com/problems/counting-bits/
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
Example:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
"""
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        
        for(int i = 1; i <= n; i++){
            int temp = i;
            int c = 0;
            while(temp>0){
                if(temp&1){
                    c++;
                }
                temp = temp>>1;
            }
            ans.push_back(c);
        }
        return ans;
    }
};
