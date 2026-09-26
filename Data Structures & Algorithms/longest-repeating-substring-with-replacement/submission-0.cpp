class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int answer = 0;

        for (char target = 'A'; target <= 'Z'; target++) {
            int left = 0;
            int changes = 0;   

            for (int right = 0; right < n; right++) {
                if (s[right] != target) {
                    changes++;
                }

                while (changes > k) {
                    if (s[left] != target) {
                        changes--;
                    }
                    left++;
                }

                int windowLength = right - left + 1;
                if (windowLength > answer) {
                    answer = windowLength;
                }
            }
        }

        return answer;
    }
};
