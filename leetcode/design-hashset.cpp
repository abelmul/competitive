#include <bits/stdc++.h>

using namespace std;

class MyHashSet
{
 private:
    vector<list<int>> container;

 public:
    MyHashSet() : container(10000) {}  // 10000 is defined arbitrarily

    void add(int key)
    {
        if (!contains(key)) {
            auto h = hash<int>{}(key) % 10000;
            container[h].push_back(key);
        }
    }

    void remove(int key)
    {
        auto h = hash<int>{}(key) % 10000;
        for (auto it = container[h].begin(); it != container[h].end(); ++it) {
            if (*it == key) {
                container[h].erase(it);
                break;
            }
        }
    }

    bool contains(int key)
    {
        auto h = hash<int>{}(key) % 10000;
        for (auto it = container[h].begin(); it != container[h].end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
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
