"""
Problem link: https://leetcode.com/problems/rotate-array/
Given an array, rotate the array to the right by k steps, where k is non-negative.
Example:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
"""
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> num;
        if(k>n){
            k = k%n;
        }
        for(int i = n-k; i < n; i++){
            num.push_back(nums[i]);
        }
        for(int i = 0; i < n-k; i++){
            num.push_back(nums[i]);
        }
        nums = num;
    }
};

//Second Approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++)
            ans[(i+k)%nums.size()] = nums[i];
        nums = ans;
    }
};
