
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (root == NULL) {
			return output;
		}

		nodeQueue.emplace_back(root);
		while(nodeQueue.size() != 0) {
			auto it = nodeQueue.back();

			if (it->right == NULL && it->left == NULL) {
				output.emplace_back(it->val);
				nodeQueue.pop_back();
				continue;
			}

			if (it->right != NULL) {
				nodeQueue.emplace_back(it->right);
				it->right = NULL;
			}

			if (it->left != NULL) {
				nodeQueue.emplace_back(it->left);
				it->left = NULL;
			}
		}

		return output;
	}

	vector<TreeNode*> nodeQueue;
	vector<int> output;
};