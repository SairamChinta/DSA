class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!str.empty()) {   // avoid pushing empty strings
                    st.push(str);
                    str = "";
                }
            } else {
                str += s[i];
            }
        }

        // push the last word if any
        if (!str.empty()) st.push(str);

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += " ";
        }

        return ans;
    }
};
