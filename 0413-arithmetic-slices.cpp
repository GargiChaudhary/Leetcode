"""
Problem link: https://leetcode.com/problems/arithmetic-slices/
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.
A subarray is a contiguous subsequence of the array.
Example:
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
"""
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        int c = 0, n = 0, diff;
        int tdiff = nums[1]-nums[0];
        for(int i = 1; i + 1 < nums.size(); i++){
            diff = nums[i+1]-nums[i];
            if(diff == tdiff){
                n++;
            }else{
                tdiff = diff;
                n = 0;
            }
            c += n;
        }
        return c;
    }
};
