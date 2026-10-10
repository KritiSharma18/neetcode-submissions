class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

       
        vector<vector<int>> buckets(nums.size() + 1);

        for (auto p : freq) {
            int number = p.first;
            int count = p.second;

            buckets[count].push_back(number);
        }

        
        vector<int> ans;

        for (int i = nums.size(); i >= 1; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                ans.push_back(buckets[i][j]);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
