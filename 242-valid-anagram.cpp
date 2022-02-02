"""
Problem link: https://leetcode.com/problems/valid-anagram/
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example:
Input: s = "anagram", t = "nagaram"
Output: true
"""
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> shash(26,0);
        vector<int> thash(26,0);
        if(s.size()!=t.size()){
            return false;
        }
        for(int i = 0; i < s.size(); i++){
            shash[s[i]-'a']++;
            thash[t[i]-'a']++;
        }
        if(shash==thash){
            return true;
        }
        else{
            return false;
        }
    }
};
