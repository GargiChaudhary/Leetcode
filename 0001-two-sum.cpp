"""
Problem Link: https://leetcode.com/problems/two-sum/
Given an array of integers, 
return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and 
you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> temp;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    temp.push_back(i);
                    temp.push_back(j);
                }
            }
        }
        return temp;
    }
};

//Optimizing it with maps
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(m.find(diff) != m.end()){
                return {m[diff],i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
