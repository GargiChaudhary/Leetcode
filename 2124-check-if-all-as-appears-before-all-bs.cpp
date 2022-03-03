"""
Problem link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.
Example:
Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
"""
class Solution {
public:
    bool checkString(string s) {
        bool seen_b = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'b')
                seen_b = 1;
            if(s[i] == 'a' && seen_b)
                return false;
        }
        return true;
    }
};
