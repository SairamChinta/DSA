class Solution {
public:
    vector<string> result;

    void backtrack(string& s, int index, int parts, string current) {
        if (parts == 4 && index == s.size()) {
            result.push_back(current.substr(0, current.size() - 1));
            return;
        }
        if (parts == 4 || index == s.size()) return;
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string part = s.substr(index, len);
            if ((part[0] == '0' && part.size() > 1) || stoi(part) > 255)
                continue;
            backtrack(s, index + len, parts + 1, current + part + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};
