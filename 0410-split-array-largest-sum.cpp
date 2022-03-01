"""
Problem Link: https://leetcode.com/problems/split-array-largest-sum/
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.
Example:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
"""
class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int mid){
        int c=1;
        int temp=0;
        for(int i=0; i<nums.size(); i++){
            if(temp + nums[i] <= mid) temp += nums[i];
            else{
                temp = nums[i];
                if(temp > mid || nums[i] > mid)
                    return false;
                c++;
            }
        }
        return c<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int s = 0;
        int e = 0;
        for(int i = 0; i < nums.size(); i++){
            e += nums[i];
        }
        int mid = s + (e-s)/2;
        int ans = INT_MAX;
        while(s <= e){
            if(isPossible(nums,m,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};
