"""
Problem link: https://leetcode.com/problems/is-subsequence/
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative 
positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
Example:
Input: s = "abc", t = "ahbgdc"
Output: true
"""
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return true;
        if(t.size()==0) return false;
        int j = 0;
        for(int i = 0; i < t.size() && j < s.size(); i++){
            if(s[j] != t[i] && i == t.size()-1) return false;
            else if(s[j] == t[i] && i>=j) j++;
        }
        if(j==s.size()) return true;
        return false;
    }
};
