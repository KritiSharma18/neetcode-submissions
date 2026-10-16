class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";

        auto& v = it->second;
        int lo = 0, hi = (int)v.size() - 1;
        string res = "";
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid].first <= timestamp) {
                res = v[mid].second;   // candidate; look right
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }
};