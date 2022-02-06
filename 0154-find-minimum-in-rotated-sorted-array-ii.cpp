"""
Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
You must decrease the overall operation steps as much as possible.
Example:
Input: nums = [1,3,5]
Output: 1
"""
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() -1;
        while(s < e){
            int m = s + (e-s)/2;
            if(nums[m] > nums[e]){
                s = m+1;
            }else if(nums[m] < nums[e]){
                e = m;
            }else e--;
            m = s + (e-s)/2;
        }
        return nums[s];
    }
};
