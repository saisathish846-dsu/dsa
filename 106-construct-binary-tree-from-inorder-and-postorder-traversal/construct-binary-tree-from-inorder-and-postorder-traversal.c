static struct TreeNode* build(int* inorder, int* postorder, int* postIdx,
                              int* idx, int lo, int hi) {
    if (lo > hi) return NULL;

    int rootVal = postorder[*postIdx];
    (*postIdx)--;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;

    int mid = idx[rootVal + 3000];   // offset to handle negative values

    root->right = build(inorder, postorder, postIdx, idx, mid + 1, hi);  // right first
    root->left  = build(inorder, postorder, postIdx, idx, lo, mid - 1);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int idx[6001];
    for (int i = 0; i < inorderSize; i++) {
        idx[inorder[i] + 3000] = i;
    }

    int postIdx = postorderSize - 1;
    return build(inorder, postorder, &postIdx, idx, 0, inorderSize - 1);
}