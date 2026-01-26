class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;  // To handle the case when prefix sum itself equals k
        int ps = 0, c = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            ps += nums[i];  // update prefix sum
            if (mpp.find(ps - k) != mpp.end()) {
                c += mpp[ps - k];  // add how many times (ps - k) has occurred
            }
            mpp[ps]++;  // update frequency of current prefix sum
        }
        
        return c;
    }
};
