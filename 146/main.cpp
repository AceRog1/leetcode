#include <iostream>

using namespace std;

class LRUCache {
private:
    pair<int, int> arr[0];
    int size;
    size_t hash(int key) const{
        return size%key;
    }
public:
    LRUCache(int capacity) {
        size = capacity;
        arr[size];
    }

    int get(int key) {
        int pos = size%key;
        return arr[pos].second;
    }

    void put(int key, int value) {
        size_t add = hash(key);
        pair<int, int> newVal(key, value);
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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
