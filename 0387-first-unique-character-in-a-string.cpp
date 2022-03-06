"""
Problem link: https://leetcode.com/problems/first-unique-character-in-a-string/
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example:
Input: s = "leetcode"
Output: 0
"""
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        for(char i : s){
            m[i]++;
        }
        int minIndex = INT_MAX;
        int c = 0;
        for(auto i : m){
            if(i.second == 1){
                c++;
                if(s.find(i.first) < minIndex){
                    minIndex = s.find(i.first);
                }
            }
        }
        if(c==0) return -1;
        return minIndex;
    }
};
