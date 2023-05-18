#include <bits/stdc++.h>

using namespace std;
/*
// Definition for a Node.
*/
class Node
{
 public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
 public:
    int maxDepth(Node* root)
    {
        stack<pair<Node*, int>> st;
        pair<Node*, int> ptr;
        int res = 0;

        if (root) {
            st.push(make_pair(root, 1));

            // dfs
            while (!st.empty()) {
                ptr = st.top();
                st.pop();

                if (!ptr.first->children.empty()) {
                    for (auto c : ptr.first->children) {
                        st.push(make_pair(c, ptr.second + 1));
                    }
                } else {
                    // leaf node
                    res = max(res, ptr.second);
                }
            }
        }

        return res;
    }
};
