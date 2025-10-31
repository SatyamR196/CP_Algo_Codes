struct SegmentTree {
    int* tree;

    SegmentTree(std::vector<int> arr) {
        tree = new int[4 * arr.size()]();

        // In the constructor we use zero indexing for cur_left, cur_right, and idx on update(),
        // since we assume the input array is 0-indexed.
        // The "cur" parameter is always 1 to ensure 1-indexing in the segment tree itself.
        // cur_left, cur_right, and idx can be 0- or 1-indexed relative to each other
        // depending on how we calculate segments.

        for (int i = 0; i < arr.size(); i++) {
            update(1, 0, arr.size() - 1, i, arr[i]);
        }
    }

    void update(int cur, int cur_left, int cur_right, int idx, int val) {
        // If we reach a leaf node (left == right == idx), update the value
        if (cur_left == cur_right && cur_left == idx) {
            tree[cur] = val;
        } else {
            // Compute midpoint of the segment
            int cur_mid = (cur_left + cur_right) / 2;

            // Left child: cur * 2, right child: cur * 2 + 1
            if (idx <= cur_mid) {
                update(cur * 2, cur_left, cur_mid, idx, val);
            } else {
                update(cur * 2 + 1, cur_mid + 1, cur_right, idx, val);
            }

            // After updating, recalculate the parent node value
            tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
        }
    }

    int query(int cur, int cur_left, int cur_right, int query_left, int query_right) {
        // Out of range: no overlap
        if (cur_left > query_right || cur_right < query_left)
            return 0;

        // Completely within range: total overlap
        if (query_left <= cur_left && cur_right <= query_right)
            return tree[cur];

        // Partial overlap: query both children
        int cur_mid = (cur_left + cur_right) / 2;

        return query(cur * 2, cur_left, cur_mid, query_left, query_right) +
               query(cur * 2 + 1, cur_mid + 1, cur_right, query_left, query_right);
    }
};
