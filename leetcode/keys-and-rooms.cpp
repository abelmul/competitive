#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        deque<int> queue;
        int current;
        unordered_set<int> visited;

        queue.push_back(0);

        while (!queue.empty()) {
            current = queue.front();
            queue.pop_front();

            if (visited.find(current) != visited.end())
                continue;

            visited.insert(current);

            for (auto k : rooms[current]) {
                queue.push_back(k);
            }
        }

        return visited.size() == rooms.size();
    }
};
