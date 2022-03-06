"""
Problem link: https://leetcode.com/problems/defanging-an-ip-address/
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".
Example:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
"""
class Solution {
public:
    string defangIPaddr(string address) {
        string s = "";
        for(int i = 0; i < address.length(); i++){
            if(address[i] == '.'){
                s.push_back('[');
                s.push_back('.');
                s.push_back(']');
            }else{
                s.push_back(address[i]);
            }
        }
        return s;
    }
};
