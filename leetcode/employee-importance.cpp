#include <bits/stdc++.h>

using namespace std;

/*
// Definition for Employee.
*/

class Employee
{
 public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
 public:
    int getImportance(vector<Employee*> employees, int id)
    {
        int res = 0;

        unordered_map<int, Employee*> mp;
        stack<int> st;
        Employee* ptr;

        for (auto e : employees) {
            mp[e->id] = e;
        }

        st.push(id);

        while (!st.empty()) {
            ptr = mp[st.top()];
            st.pop();

            cout << ptr->id << " " << ptr->importance << "\n";
            res += ptr->importance;

            for (auto s : ptr->subordinates) {
                st.push(s);
            }
        }

        return res;
    }
};
