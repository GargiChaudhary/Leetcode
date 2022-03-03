"""
Problem link: https://leetcode.com/problems/squares-of-a-sorted-array/
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
Example:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
"""
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0); //creating ans vector of same size as nums array and declaring all elements as 0
        //creating two pointers left and right
        int left = 0;
        int right = nums.size()-1;
        for(int i = nums.size()-1; i >= 0; i--){ //iterating from last index to first
            // if value at right is greater than putting it's square on the last index(i'th index) and decrement right
            if(abs(nums[left])<abs(nums[right])){ 
                ans[i] =  nums[right] * nums[right];
                right--;
            }// if value at left is greater than putting it's square on the last index(i'th index) and increment left
            else{
                ans[i] =  nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};
