/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

    vector<int> hashMap;
    bool hasDuplicate = false;

    int getGreatest(Node* root) {
        int value = root->data;
        
        if(root->right == NULL && root->left == NULL) {
            return value;
        }
        
        int tmp = getGreatest(root->left);
        
        if(tmp > value) {
            value = tmp;
        }
        
        tmp = getGreatest(root->right);
        
        if(tmp > value) {
            value = tmp;
        }
        
        return value;
    }

    int getSmallest(Node* root) {
        int value = root->data;
        
        if(root->right == NULL && root->left == NULL) {
            return value;
        }
        
        int tmp = getSmallest(root->left);
        
        if(tmp < value) {
            value = tmp;
        }
        
        tmp = getSmallest(root->right);
        
        if(tmp < value) {
            value = tmp;
        }
        
        return value;
    }

    bool checkIntegrity(Node *root) {
        int greatestLeft = -1;
        int smallestRight = -1;
        
        if(root->left != NULL)
            greatestLeft = getGreatest(root->left);

        if(root->right != NULL)
            smallestRight = getSmallest(root->right);
        
        if(greatestLeft >= 0 && greatestLeft > root->data) {
            return false;
        }
        
        if(smallestRight >= 0 && smallestRight < root->data) {
            return false;
        }
        
        if(root->right != NULL && checkIntegrity(root->right) == false) {
            return false;
        }
        
        if(root->left != NULL && checkIntegrity(root->left) == false) {
            return false;
        }
        
        return true;
    }

    bool hasDuplicateValues(Node* root) {        
        if(root->right != NULL && checkDuplicates(root->right, root->data) == true) {
            return true;
        }
        
        if(root->left != NULL && checkDuplicates(root->left, root->data) == true) {
            return true;
        }
        
        if(root->right != NULL && hasDuplicateValues(root->right)) {
            return true;
        }
        
        if(root->left != NULL && hasDuplicateValues(root->left)) {
            return true;
        }
        
        
        return false;
    }

    bool checkDuplicates(Node* root, int value) {
        if(root->data == value) {
            return true;
        }
        
        if(root->right != NULL && checkDuplicates(root->right, value) == true) {
            return true;
        }
        
        if(root->left != NULL && checkDuplicates(root->left, value) == true) {
            return true;
        }
        
        return false;
    }

    bool retBST(Node *root) {
       if(root->right == NULL && root->left == NULL) {
          return true;
       }
       
       if(root->right != NULL && root->right->data <= root->data) {
          return false;
       }
        
        if(root->left != NULL && root->left->data >= root->data) {
            return false;
        }
       
       return retBST(root->right) && retBST(root->left);
   }

   bool checkBST(Node* root) {
       return checkIntegrity(root) && retBST(root) && !hasDuplicateValues(root);
   }
