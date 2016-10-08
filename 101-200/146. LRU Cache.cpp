class LRUCache {
  unordered_map<int, pair<int, int>> kvc;
  queue<int> kq;
  int capacity;

public:
  LRUCache(int capacity) { this->capacity = capacity; }
  int get(int key) {
    auto it = kvc.find(key);
    if (it != kvc.end()) {
      it->second.second += 1;
      kq.push(key);
      return it->second.first;
    } else {
      return -1;
    }
  }
  void set(int key, int value) {
    auto it = kvc.find(key);
    if (it != kvc.end()) {
      it->second.first = value;
      it->second.second += 1;
    } else {
      if (kvc.size() >= capacity) {
        while (kq.size() > 0) {
          auto tmp = kq.front();
          kq.pop();
          auto it = kvc.find(tmp);
          it->second.second--;
          if (it->second.second == 0) {
            kvc.erase(it);
            break;
          }
        }
      }
      kvc.emplace(std::make_pair(key, std::make_pair(value, 1)));
    }
    kq.push(key);
  }
};
