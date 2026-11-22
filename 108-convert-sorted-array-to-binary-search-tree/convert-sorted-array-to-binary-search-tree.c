static struct TreeNode* build(int* nums, int lo, int hi) {
    if (lo > hi) return NULL;

    int mid = lo + (hi - lo) / 2;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left  = build(nums, lo, mid - 1);
    root->right = build(nums, mid + 1, hi);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return build(nums, 0, numsSize - 1);
}