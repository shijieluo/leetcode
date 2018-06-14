struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int st, int ed) {
        start = st, end = ed, sum = 0;
        left = NULL, right = NULL;
    }
};

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        root = build(nums, 0, nums.size() - 1);
    }
    
    int query(int st, int ed) {
        return query(root, st, ed);
    }
    
    int update(int pos, int val) {
        return update(root, pos, val);
    }
private:
    SegmentTreeNode* build(vector<int>& nums, int st, int ed) {
        if (st > ed) return NULL;
        SegmentTreeNode* node = new SegmentTreeNode(st, ed);
        if (st == ed) {
            node->sum = nums[st];
            return node;
        }
        
        int mid = (st + ed) / 2;
        node->left = build(nums, st, mid);
        node->right = build(nums, mid + 1, ed);
        if (node->left) node->sum += node->left->sum;
        if (node->right) node->sum += node->right->sum;
        return node;
    }
    
    int update(SegmentTreeNode* root, int pos, int val) {
        if (!root) return 0;
        int diff;
        if (root->start == pos && root->end == pos) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if (pos > mid) {
            diff = update(root->right, pos, val);
        } else {
            diff = update(root->left, pos, val);
        }
        root->sum = root->sum + diff;
        return diff;
    }
    
    int query(SegmentTreeNode* root, int st, int ed) {
        if (root == NULL) return 0;
        if (root->start == st && root->end == ed) 
            return root->sum;
        int mid = (root->start + root->end) / 2;
        if (st > mid) return query(root->right, st, ed);
        if (ed <= mid) return query(root->left, st, ed);
        return query(root->left, st, mid) + query(root->right, mid + 1, ed);
    }
    
    SegmentTreeNode* root;
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        tree = new SegmentTree(nums);
    }
    
    void update(int i, int val) {
        tree->update(i, val);
    }
    
    int sumRange(int i, int j) {
        return tree->query(i, j);
    }
private:
    SegmentTree* tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */