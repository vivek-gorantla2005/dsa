#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

class Tree {
    public:
    struct node *createnode(int data){
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    struct node* insert(struct node *root, int data){
        if(root == NULL){
            return createnode(data);
        }else{
            if(data < root->data){
                root->left = insert(root->left, data);
            }else if(data > root->data){
                root->right = insert(root->right, data);
            }
            return root;
        }
    }

    int findmin(struct node *root){
        struct  node *temp = root;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp->data;
    }

    struct node *deletenode(struct node *root,int data){
        if(root == NULL){
            return root;
        }
        if(data < root->data){
            root->left = deletenode(root->left, data);
        }else if(data > root->data){
            root->right = deletenode(root->right, data);
        }else{
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }else if(root->left == NULL){
                struct node *temp = root->right;
                free(root);
                return temp;
            }else if(root->right == NULL){
                struct node *temp = root->left;
                free(root);
                return temp;
            }else{
                int min = findmin(root->right);
                root->data = min;
                root->right = deletenode(root->right, min);
            }
        }
        return root;
    }


    void inorder(struct node *root){
        if(root != NULL){
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main(){
    struct node *root = NULL;
    Tree tree;
    root = tree.insert(root,50);
    root = tree.insert(root,70);
    root = tree.insert(root,30);
    root = tree.insert(root,20);
    root = tree.insert(root,40);
    root = tree.deletenode(root,30);

    cout << "Inorder traversal: ";
    tree.inorder(root);

    return 0;
}
