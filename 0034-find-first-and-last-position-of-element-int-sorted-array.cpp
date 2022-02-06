"""
Problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example: 
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
"""

class Solution {
public:
    
    int firstPosition(vector<int>& arr, int n, int k){
        int s = 0, e = n-1;
        int m = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[m]==k){
                ans = m;
                e = m-1;
            }
            else if(arr[m]<k){
                s = m+1;
            }
            else if(arr[m]>k){
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return ans;
    }

    int lastPosition(vector<int>& arr, int n, int k){
        int s = 0, e = n-1;
        int m = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[m]==k){
                ans = m;
                s = m+1;
            }
            else if(arr[m]<k){
                s = m+1;
            }
            else if(arr[m]>k){
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(firstPosition(nums, n, target));
        ans.push_back(lastPosition(nums, n, target));
        return ans;
    }
};
