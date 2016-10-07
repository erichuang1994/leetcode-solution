class LRUCache {
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    t = 0;
  }

  int get(int key) {
    if (kv.find(key) != kv.end()) {
      auto timestamp = kt[key];
      tk.erase(timestamp);
      t++;
      kt[key] = t;
      tk[t] = key;
      return kv[key];
    } else {
      return -1;
    }
  }

  void set(int key, int value) {
    if (kv.find(key) != kv.end()) {
      auto timestamp = kt[key];
      tk.erase(timestamp);
    } else if (kv.size() >= capacity) {
      auto it = tk.begin();
      auto rt = it->first;
      auto rk = it->second;
      tk.erase(it);
      kt.erase(rk);
      kv.erase(rk);
    }
    t++;
    kv[key] = value;
    kt[key] = t;
    tk[t] = key;
  }

private:
  unordered_map<int, int> kv;
  map<int, int> tk;
  unordered_map<int, int> kt;
  int capacity;
  int t;
};
