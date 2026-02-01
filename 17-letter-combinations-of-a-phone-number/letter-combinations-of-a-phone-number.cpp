#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int ind, string &digits, string &path, vector<string> &ans, unordered_map<char, string> &phone) {
        if (ind == digits.size()) {
            ans.push_back(path);
            return;
        }

        for (char c : phone[digits[ind]]) {
            path.push_back(c);
            backtrack(ind + 1, digits, path, ans, phone);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans;
        string path = "";
        backtrack(0, digits, path, ans, phone);
        return ans;
    }
};
