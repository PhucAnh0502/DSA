#include<stdio.h> 
#include<stdlib.h> 
  
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
  
struct node* create_node(int data) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data   = data; 
    new_node->left  = new_node->right  = NULL; 
    return (new_node); 
} 
  
struct node *right_rotation(struct node *x) 
{ 
    struct node *y = x->left; 
    x->left = y->right; 
    y->right = x; 
    return y; 
} 
  
struct node *left_rotation(struct node *x) 
{ 
    struct node *y = x->right; 
    x->right = y->left; 
    y->left = x; 
    return y; 
} 
  
struct node *splaying(struct node *root, int data) 
{ 

    if (root == NULL || root->data == data) 
        return root; 
    if (root->data > data) 
    { 
        if (root->left == NULL) return root; 
        if (root->left->data > data) 
        { 
            root->left->left = splaying(root->left->left, data); 

            root = right_rotation(root); 
        } 
        else if (root->left->data < data)
        { 
            root->left->right = splaying(root->left->right, data); 
  
            if (root->left->right != NULL) 
                root->left = left_rotation(root->left); 
        } 
  
        return (root->left == NULL)? root: right_rotation(root); 
    } 
    else
    { 
        if (root->right == NULL) return root; 
        if (root->right->data > data) 
        { 
            root->right->left = splaying(root->right->left, data); 
            if (root->right->left != NULL) 
                root->right = right_rotation(root->right); 
        } 
        else if (root->right->data < data)
        { 
            root->right->right = splaying(root->right->right, data); 
            root = left_rotation(root); 
        } 
        return (root->right == NULL)? root: left_rotation(root); 
    } 
} 
  
struct node *find_node(struct node *root, int data) 
{ 
    return splaying(root, data); 
} 

struct node *add_node(struct node *root, int k) 
{ 
    if (root == NULL) return create_node(k); 
    root = splaying(root, k); 
    if (root->data == k) return root; 
    struct node *new_node  = create_node(k); 
    if (root->data > k) 
    { 
        new_node->right = root; 
        new_node->left = root->left; 
        root->left = NULL; 
    } 
    else
    { 
        new_node->left = root; 
        new_node->right = root->right; 
        root->right = NULL; 
    } 
    return new_node; 
}

struct node* delete_data(struct node *root, int data){ 
    struct node *temp; 
    if (!root) 
        return NULL; 
    root = splaying(root, data); 
    if (data != root->data) 
        return root; 
    if (!root->left) 
    { 
        temp = root; 
        root = root->right; 
    } 
    else
    { 
        temp = root; 
        root = splaying(root->left, data); 
        root->right = temp->right; 
    } 
    free(temp); 
    return root; 
} 

void preOrder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d ", root->data); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
  
int main() 
{ 
    struct node *root = create_node(89); 
    root->left = create_node(38); 
    root->right = create_node(100); 
    root->left->left = create_node(38); 
    root->left->left->left = create_node(24); 
    root->left->left->left->left = create_node(16);
    preOrder(root);
    printf("\n");
    root = find_node(root, 10); 
    int data = 24;
    root = delete_data(root, data);
    printf("\n");
    preOrder(root);
    root = add_node(root, 27);
    printf("\n");
    preOrder(root); 
    return 0; 
}
