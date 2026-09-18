class TimeMap {
   public:
    unordered_map<string, map<int, string>> mp;
    TimeMap() { mp.clear(); }

    void set(string key, string value, int timestamp) { mp[key][timestamp] = value; }

    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";

        auto ub = mp[key].upper_bound(timestamp);
        if (ub == mp[key].begin()) return "";
        ub--;
        return ub->second;
    }
};
