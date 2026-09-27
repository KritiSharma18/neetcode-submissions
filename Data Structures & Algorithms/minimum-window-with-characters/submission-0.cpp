class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0);
        for (char c : t) need[c]++;

        int required = t.size();   
        int left = 0;
        int bestStart = 0, bestLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (need[c] > 0) required--;
            need[c]--;             

            while (required == 0) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                char lc = s[left];
                need[lc]++;       
                if (need[lc] > 0) required++;  
                left++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
