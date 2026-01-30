class MyHashSet {
public:
    vector<bool>hash;
    MyHashSet() {
        hash.resize(1000001,false);
    }
    
    void add(int key) {
        hash[key]=true;
        
    }
    
    void remove(int key) {
        if(hash[key])
            hash[key]=false;
        
        
    }
    
    bool contains(int key) {
        if(hash[key])
            return true;
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */