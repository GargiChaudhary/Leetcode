"""
Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice.
The relative order of the elements should be kept the same.
Return k after placing the final result in the first k slots of nums.
Example:
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
"""
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n : nums){
            if(i < 2 || n > nums[i-2]){
                nums[i++] = n;
            }
        }
        return i;
    }
};
