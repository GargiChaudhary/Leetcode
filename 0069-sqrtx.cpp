"""
Problem link: https://leetcode.com/problems/sqrtx/description/
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
"""
class Solution {
public:
    int mySqrt(int x) {
        int s = 0, e = x;
        int ans = 0;
        while(s <= e){
            long long int m = s + (e-s)/2;
            if(m*m == x){
                return m;
            }
            else if(m*m < x){
                ans = m;
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        return ans;
    }
};
