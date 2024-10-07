#include <iostream>
#include <utility>

using namespace std;

class LRUCache {
private:
    pair<int, int>** arr;
    int size, maxSize;
    [[nodiscard]] size_t hash(int key) const{
        if (key == 0)
            return 0;
        return key%maxSize;
    }
public:
    LRUCache(int capacity) {
        maxSize = capacity;
        size = 0;
        arr = new pair<int, int>*[maxSize];
        for (size_t i = 0; i <= maxSize; i++)
            arr[i] = nullptr; //arr[i] = new pair<int, int>;
    }

    int get(int key) {
        int pos = key%maxSize;
        if (arr[pos]->first == key) return arr[pos]->second;
        else return -1;
    }

    void put(int key, int value) {
        if (size < maxSize){
            auto  newVal = new pair<int, int>(key, value);
            arr[size] = newVal;
            size++;
        } else {
            size_t add = hash(key);
            auto  newVal = new pair<int, int>(key, value);
            arr[add] = newVal;
        }
    }

    ~LRUCache(){
        for (size_t i = 0; i < maxSize; i++)
            delete arr[i];
        delete[] arr;
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
