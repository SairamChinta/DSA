class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequencies
        for (char ch : s)
            freq[ch]++;

        // Move into vector for sorting
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Sort by frequency descending, then lexicographically ascending
        sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            if (a.second != b.second)
                return a.second > b.second; // higher frequency first
            return a.first < b.first;       // smaller char first
        });

        // Build result string
        string result;
        for (auto& [ch, count] : vec) {
            result.append(count, ch);
        }

        return result;
    }
};
