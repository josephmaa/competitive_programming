/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            vector<int> unordered;
            vector<int> ordered;
            for (int i = 0; i < n; ++i) {
                if (q.front() != nullptr) {
                    unordered.push_back(q.front() -> val);
                    ordered.push_back(q.front() -> val);
                    q.push(q.front() -> left);
                    q.push(q.front() -> right);
                    q.pop();
                }
            }
            sort(ordered.begin(), ordered.end());
            map<int, int> m;
            for (int i = 0; i < unordered.size(); ++i) {
                if (unordered[i] != ordered[i]) {
                    m[unordered[i]] = i;
                }
            }
            while (m.size()) {
                pair<int, int> smallest = *m.begin();
                pair<int, int> largest = *m.end();
                // swap the two values
                unordered[smallest.second] = largest.first;
                unordered[largest.second] = smallest.first;
                if (unordered[smallest.second] == ordered[smallest.second]) {
                    m.erase(smallest.second);
                }
                if (unordered[largest.second] == ordered[largest.second]) {
                    m.erase(largest.second);
                }
                res++;
            }
        }
        return res;
    }
};