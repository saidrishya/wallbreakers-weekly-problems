class MyHashSet {
public:
    /** Initialize your data structure here. */
    int a[1000001];
    MyHashSet() {
        memset(a,-1,sizeof(a));
    }
    
    void add(int key) {
        a[key] =22;
    }
    
    void remove(int key) {
        a[key] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return (a[key] == -1)? false : true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
