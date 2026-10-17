class LRUCache {
private:
    int cap;
    list<pair<int,int>> order;   // {key, value}, front = most recently used
    unordered_map<int, list<pair<int,int>>::iterator> pos;  // key -> node in list

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;

        // Move this node to the front (mark as recently used)
        order.splice(order.begin(), order, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            // Key exists: update value and move to front
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
            return;
        }

        // New key: insert at front
        order.push_front({key, value});
        pos[key] = order.begin();

        // Over capacity: evict least recently used (back of list)
        if ((int)order.size() > cap) {
            int lruKey = order.back().first;
            pos.erase(lruKey);
            order.pop_back();
        }
    }
};
