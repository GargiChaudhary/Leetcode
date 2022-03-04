"""
Problem Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
Example:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
"""
class Solution {
    bool isPossible(vector<int> &weights,int mid,int days){
        int c=1;
        int temp=0;
        for(int i=0;i<weights.size();i++){
            if(temp+weights[i]<=mid) temp+=weights[i];
            else{
                temp=weights[i];
                c++;
            }
        }
        return c<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
        int e=INT_MAX;
        int ans=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(weights,mid,days)){ 
                ans=min(ans,mid);
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};
