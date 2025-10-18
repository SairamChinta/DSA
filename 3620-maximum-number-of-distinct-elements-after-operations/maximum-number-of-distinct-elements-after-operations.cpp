class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
     sort(nums.begin(), nums.end());
        
        int distinctCount = 0;
        long long lastPickedValue = LLONG_MIN; 
        
        for (int num : nums) {
            long long currentNum = (long long)num;
            long long currentK = (long long)k;

            long long candidate = max(lastPickedValue + 1, currentNum - currentK);
            
            if (candidate <= currentNum + currentK) {
                distinctCount++;
                lastPickedValue = candidate;
            }
        }
        
        return distinctCount;   
    }
};