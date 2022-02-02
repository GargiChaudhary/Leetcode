"""
Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
Example:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
"""
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int m = s + (e-s)/2;
        if(nums[s]<nums[e]){
            return nums[s];
        }
        while(s < e){
            if(nums[m] >= nums[0]){
                s = m+1;
            }
            else{
                e = m;
            }
            m = s + (e-s)/2;
        }
        return nums[s];
    }
};
