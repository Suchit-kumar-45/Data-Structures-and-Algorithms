class MyHashMap {
public:
    vector<int>hash;
    MyHashMap() {
        hash.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        hash[key]=value;
        
    }
    
    int get(int key) {
        if(hash[key])
            return hash[key];
        else
            return 0;
        
    }
    
    void remove(int key) {
         hash[key]=-1;
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */