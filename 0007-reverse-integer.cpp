"""
Problem Link: https://leetcode.com/problems/reverse-integer/
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
Example:
Input: x = 123
Output: 321
"""
class Solution {
public:
    int reverse(int x) {
        int n = 0, r = 0;
        while(x!=0){
            r = x%10;
            
            if((INT_MIN/10) >n||n > (INT_MAX/10)){
                return 0;
            }
            n = r + (10*n);
            x = x/10;
        }
        return n;
    }
};
