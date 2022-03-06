"""
Problem link: https://leetcode.com/problems/sort-characters-by-frequency/
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
Example:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
"""
class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        char ch;
        int max = 0;
        map<char,int> m;
        for(char i : s) m[i]++;
        while(m.size()>0){
            for(auto i = m.begin(); i != m.end(); i++){
                if(i->second > max){
                    max = i->second;
                    ch = i->first;
                }
            }
            for(int i = 0; i < max; i++) 
                ans.push_back(ch);
            max = 0;
            m.erase(ch);
        }
        return ans;
    }
};
