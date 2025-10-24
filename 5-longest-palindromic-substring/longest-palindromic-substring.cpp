class Solution {
public:
    string longestPalindrome(string s) {
    if (s.empty()) {
        return "";
    }

    int start = 0;
    int maxLength = 0;

    // Helper lambda function to expand around a center
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return length of the palindrome
        return right - left - 1;
    };

    for (int i = 0; i < s.length(); ++i) {
        // Odd length: center is 'i'
        int len1 = expandAroundCenter(i, i);
        
        // Even length: center is between 'i' and 'i+1'
        int len2 = expandAroundCenter(i, i + 1);
        
        int len = max(len1, len2);
        
        if (len > maxLength) {
            maxLength = len;
            // Calculate new start index
            start = i - (len - 1) / 2;
        }
    }

    return s.substr(start, maxLength);
}};