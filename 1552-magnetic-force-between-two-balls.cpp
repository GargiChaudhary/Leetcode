"""
Problem link: https://leetcode.com/problems/magnetic-force-between-two-balls/description/
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket.
Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force 
between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.
Example:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot 
achieve a larger minimum magnetic force than 3.
"""

class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mid){
        int ballsCount = 1;
        int lastPos = position[0];
        for(int i = 0; i < position.size(); i++){
            if(position[i] - lastPos >= mid){
                ballsCount++;
                if(ballsCount == m) return true;
                lastPos = position[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int ans = -1;
        int s = 0, e = -1;
        for(int i = 0; i < position.size(); i++){
            e = max(e, position[i]);
        }
        while(s <= e){
            int mid = s + (e-s)/2;
            if(isPossible(position, m, mid)){
                ans = mid;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return ans;
    }
};
