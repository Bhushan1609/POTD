//706
class MyHashMap {
public:
   int hashi[1000001];
    MyHashMap() {
        for (int i = 0 ; i < 1000001 ; i++){
            hashi[i] = -1;
        }
    }
    void put(int key, int value) {
        hashi[key] = value;
        return ;
    }
    int get(int key) {
        return hashi[key];
    }
    void remove(int key) {
        hashi[key] = -1;
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
