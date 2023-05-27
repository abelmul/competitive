#include <bits/stdc++.h>

using namespace std;

class ThroneInheritance
{
 private:
    unordered_map<string, pair<vector<string>, bool>> adjList;
    string king;

 public:
    ThroneInheritance(string kingName)
    {
        adjList[kingName] = {{}, true};
        king = kingName;
    }

    void birth(string parentName, string childName)
    {
        adjList[childName] = {{}, true};
        adjList[parentName].first.push_back(childName);
    }

    void death(string name) { adjList[name].second = false; }

    vector<string> getInheritanceOrder()
    {
        vector<string> res;

        string name;

        stack<string> st;
        st.push(king);

        while (!st.empty()) {
            name = st.top();
            st.pop();

            if (adjList[name].second) {
                res.push_back(name);
            }

            for (auto n = adjList[name].first.rbegin(); n < adjList[name].first.rend(); ++n) {
                st.push(*n);
            }
        }

        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
