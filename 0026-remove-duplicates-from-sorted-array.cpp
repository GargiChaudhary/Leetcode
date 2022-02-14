"""
Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.
Return k after placing the final result in the first k slots of nums.
Example:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
"""
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                j++;
            }else{
                nums[i-j] = nums[i];
            }
        }
        nums.erase(nums.end()-j , nums.end()); //erasing all the duplicate elements residing at the end part of the array
        return nums.size();
    }
};
