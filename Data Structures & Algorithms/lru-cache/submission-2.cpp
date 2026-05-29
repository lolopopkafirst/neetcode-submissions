class LRUCache {
public:
    unordered_map<int, pair<int, int>> um;
    int capacity;
    int counter = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(um.find(key) == um.end()){
            return -1;
        }
        else{
            um[key].second = counter;
            counter++;
            return um[key].first;
        } 
        
    }
    
    void put(int key, int value) {
        if(um.find(key) == um.end()){
            if(capacity > 0){
                counter++;
                um[key].first = value;
                um[key].second = counter;
                this->capacity--;
            }
            else{
                int min = 99999;
                int minkey = 0;
                for(auto&[key, p] : um){
    
                    if(p.second < min){
                        min = p.second;
                        minkey = key;
                    } 
                }
                cout << min << " ";
                cout << minkey << " ";
                um.erase(minkey);
                um[key] = {value, counter};
            }
        }
        else{
            um[key].first = value;
            um[key].second = counter;
        } 
        counter++;
    }
};
