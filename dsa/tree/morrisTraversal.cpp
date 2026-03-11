#include <iostream>
#include <vector>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

vector<int> inOrder(Node* root) {
    vector<int> a;
    Node* curr = root;
    while(curr){
        if(!curr->left){
            a.push_back(curr->data);
            curr = curr->right;
        }else{
            Node* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right==curr){
                a.push_back(curr->data);
                prev->right = nullptr;
                curr = curr->right;
            }else{
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
    return a;
}


int main() {
  
    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //        / \  
    //       4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = inOrder(root);
  
     for (int data : res) {
        cout << data << " ";
    }
    
    return 0;
}