"""
Problem link: https://leetcode.com/problems/sort-colors/
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, 
white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
  
Example: 
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
"""
  
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n-1;
        while(i<=k){
            if(nums[i]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[k]);
                k--;
            }
            else{
                i++;
            }
        }
    }
};
