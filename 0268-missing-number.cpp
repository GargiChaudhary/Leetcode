"""
Problem link: https://leetcode.com/problems/missing-number/
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Example:
Input: nums = [3,0,1]
Output: 2
"""
class Solution {
public:
    int sum(int n){
        int s = 0;
        for(int i = 1; i <= n; i++){
            s+=i;
        }
        return s;
    }
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ans += nums[i];
        }
        return sum(n)-ans;
    }
};
