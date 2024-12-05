// Here key = element of arrary , value = it's next greater element.
    int n = arr.size();
    stack<int> st;
    unordered_map<int, int> nge;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() < nums2[i]) {
            nge[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }

    while (!st.empty()) {
        nge[st.top()] = -1;
        st.pop();
    }
