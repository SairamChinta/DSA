class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> temp;
        backtrack(nums, used, temp, res);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, used, temp, res);
            temp.pop_back();
            used[i] = false;
        }
    }
};
