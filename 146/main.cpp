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
        return size%key;
    }
public:
    LRUCache(int capacity) {
        size = capacity;
        arr = new pair<int, int>*[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = nullptr;
    }

    int get(int key) {
        int pos = size%key;
        return arr[pos]->second;
    }

    void put(int key, int value) {
        size_t add = hash(key);
        auto  newVal = new pair<int, int>(key, value);
        arr[add] = newVal;
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



    return 0;
}
