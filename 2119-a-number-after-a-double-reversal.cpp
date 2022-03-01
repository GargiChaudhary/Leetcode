"""
Problem link: https://leetcode.com/problems/a-number-after-a-double-reversal/
Reversing an integer means to reverse all its digits.
For example, reversing 2021 gives 1202. Reversing 12300 gives 321 as the leading zeros are not retained.
Given an integer num, reverse num to get reversed1, then reverse reversed1 to get reversed2. Return true if reversed2 equals num. Otherwise return false.
Example:
Input: num = 526
Output: true
Explanation: Reverse num to get 625, then reverse 625 to get 526, which equals num.
"""
class Solution {
public:
    int reverse(int num){
        int ans = 0;
        while(num!=0){
            int r = num%10;
            ans = ans*10 + r;
            num = num/10;
        }
        return ans;
    }
    bool isSameAfterReversals(int num) {
        int reversed1 = reverse(num);
        int reversed2 = reverse(reversed1);
        if(num == reversed2)
            return true;
        else
            return false;
    }
};
