#include <iostream>
#include <utility>

using namespace std;

class LRUCache {
private:
    pair<int, int>** arr;
    int size;
    [[nodiscard]] size_t hash(int key) const{
        if (key == 0)
            return 0;
        return key%size;
    }
public:
    LRUCache(int capacity) {
        size = capacity;
        arr = new pair<int, int>*[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = nullptr;
    }

    int get(int key) {
        int pos = key%size;
        return arr[pos]->second;
    }

    void put(int key, int value) {
        size_t add = hash(key);
        auto  newVal = new pair<int, int>(key, value);
        arr[add] = newVal;
    }

    ~LRUCache(){
        delete arr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

    // Test 1
    LRUCache lru(2);         // null

    lru.put(1, 1);        // null
    lru.put(2, 2);        // null
    cout << lru.get(1) << "\n"; // 1
    lru.put(3, 3);        // null
    cout << lru.get(2) << "\n"; // -1
    lru.put(4, 4);        // null
    cout << lru.get(1) << "\n"; // -1
    cout << lru.get(3) << "\n"; // 3
    cout << lru.get(4) << "\n"; // 4

    return 0;
}
