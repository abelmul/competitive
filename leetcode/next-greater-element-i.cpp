class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> greater;
        stack<int> st; // monotonic
        vector<int> res;

        res.reserve(nums1.size());

        // construct greater map by monotonic stack
        for(auto n : nums2) {
            while(!st.empty() && st.top() < n) {
                greater[st.top()] = n;
                st.pop();
            }

            st.push(n);
        }

        for(auto n : nums1) {
            if (greater.find(n) == greater.end()) {
                res.push_back(-1);
            } else {
                res.push_back(greater[n]);
            }
        }


        return res;
    }
};