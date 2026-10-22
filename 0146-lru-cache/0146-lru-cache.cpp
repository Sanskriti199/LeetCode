class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> pos;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (pos.find(key) == pos.end()) {
            return -1;
        }

        auto it = pos[key];
        int value = it->second;

        cache.splice(cache.begin(), cache, it);

        return value;
    }

    void put(int key, int value) {
        if (pos.find(key) != pos.end()) {
            auto it = pos[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }

        if (cache.size() == capacity) {
            int oldKey = cache.back().first;
            pos.erase(oldKey);
            cache.pop_back();
        }

        cache.push_front({key, value});
        pos[key] = cache.begin();
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */