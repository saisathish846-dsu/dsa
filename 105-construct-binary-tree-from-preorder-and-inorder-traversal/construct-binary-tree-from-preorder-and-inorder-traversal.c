#define OFFSET 3000

static struct TreeNode *build(int *preorder, int preStart, int preEnd,
                              int inStart, int inEnd, int *idx) {
    if (preStart > preEnd) return NULL;

    int rootVal = preorder[preStart];
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = rootVal;

    int mid = idx[rootVal + OFFSET];
    int leftSize = mid - inStart;

    root->left  = build(preorder, preStart + 1, preStart + leftSize,
                        inStart, mid - 1, idx);
    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        mid + 1, inEnd, idx);
    return root;
}

struct TreeNode *buildTree(int *preorder, int preorderSize,
                           int *inorder, int inorderSize) {
    int idx[2 * OFFSET + 1];
    for (int i = 0; i < inorderSize; i++) {
        idx[inorder[i] + OFFSET] = i;
    }
    return build(preorder, 0, preorderSize - 1, 0, inorderSize - 1, idx);
}