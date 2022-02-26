"""
Problem link: https://leetcode.com/problems/find-target-indices-after-sorting-array/
You are given a 0-indexed integer array nums and a target element target.
A target index is an index i such that nums[i] == target.
Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list.
The returned list must be sorted in increasing order.
Example:
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
"""
class Solution {
public:
    //separate function to calculate first occurence of target using binary search
    int firstOccurence(vector<int>& nums, int k){
        int s = 0, e = nums.size()-1;
        int m = s + (e-s)/2;
        int ans = -1; // if target not found in the given array then function will return -1
        while(s<=e){
            if(nums[m]==k){
                ans = m;
                e = m-1;
            }
            else if(nums[m]<k){
                s = m+1;
            }
            else if(nums[m]>k){
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return ans;
    }
    //separate function to calculate last occurence of target using binary search
    int lastOccurence(vector<int>& nums, int k){
        int s = 0, e = nums.size()-1;
        int m = s + (e-s)/2;
        int ans = -1; // if target not found in the given array then function will return -1
        while(s<=e){
            if(nums[m]==k){
                ans = m;
                s = m+1;
            }
            else if(nums[m]<k){
                s = m+1;
            }
            else if(nums[m]>k){
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans; // creating ans vector for storing target indices
        sort(nums.begin(),nums.end()); // sorting given vector array
        
        int first = firstOccurence(nums,target); 
        int last = lastOccurence(nums,target);
        
        if(first != -1 && last != -1){ // check if target is found 
            for(int i=first; i<=last; i++){ // iterate from first to last and push all the indices in ans vector
                ans.push_back(i);
            }
        }
        return ans;
    }
};
