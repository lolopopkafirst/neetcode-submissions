class LRUCache {
public:
    unordered_map<int, pair<int, list<int>::iterator>> um;
    int capacity;
    list<int> order;
    int counter = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(um.find(key) == um.end()){
            return -1;
        }
        order.erase(um[key].second);
        order.push_back(key);
        um[key].second = --order.end();
        return um[key].first;
    }
    
    void put(int key, int value) {
        if(um.find(key) != um.end()){
            order.erase(um[key].second);
        }
        else if(um.size() == capacity){
            int todelete = order.front();
            order.pop_front();
            um.erase(todelete);
        }
        order.push_back(key);
        um[key] = {value, --order.end()};
    }
};
