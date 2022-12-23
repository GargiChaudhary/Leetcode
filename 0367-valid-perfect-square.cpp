"""
Problem link: https://leetcode.com/problems/valid-perfect-square/description/
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.
"""
class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 0, e = num;
        while(s <= e){
            long long int m = s + (e-s)/2;
            if(m*m == num){
                return 1;
            }else if(m*m < num){
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        return 0;
    }
};
