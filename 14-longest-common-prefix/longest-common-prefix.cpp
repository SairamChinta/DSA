class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string ans="";
        string f=strs[0];
        string l = strs[strs.size()-1];
        int ml=min(f.size(),l.size());
        for(int i =0;i<ml;i++){
            if(f[i]!=l[i]) break;
            ans += f[i];
        }
        return ans;
    }
};