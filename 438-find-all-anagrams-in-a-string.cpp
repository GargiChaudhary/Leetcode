"""
Problem link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
"""
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> phash(26,0);
        vector<int> shash(26,0);
        vector<int> ans;
        if(s.size()<p.size()){
            return {};
        }
        for(int i = 0; i < p.size(); i++){
            phash[p[i]-'a']++;
            shash[s[i]-'a']++;
        }
        if(phash==shash){
            ans.push_back(0);
        }
        for(int i = p.size(); i < s.size(); i++){
            shash[s[i]-'a']++;
            shash[s[i-p.size()]-'a']--;
            if(phash==shash){
                ans.push_back(i+1-p.size());
            }
        }
        return ans;
        
    }
};
