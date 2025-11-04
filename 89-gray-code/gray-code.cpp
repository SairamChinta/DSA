class Solution {
public:
    vector<int> grayCode(int n) {
         vector<int> res;
        int size = 1 << n; // total numbers = 2^n
        res.reserve(size);
        for (int i = 0; i < size; i++) {
            res.push_back(i ^ (i >> 1)); // formula for gray code
        }
        return res;
    }
};