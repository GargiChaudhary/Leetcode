"""
Problem link: https://leetcode.com/problems/reverse-string/
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
Example:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
"""
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size()-1;
        while(l<r) swap(s[l++],s[r--]);
    }
};
