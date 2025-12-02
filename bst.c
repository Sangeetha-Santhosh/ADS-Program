#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create(int value)
{
    struct node *newN = (struct node *) malloc(sizeof(struct node));
    newN->data = value;
    newN->left = newN->right = NULL;
    return newN;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return create(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct node *findMin(struct node *root)
{
    while (root && root->left != NULL)
        root = root->left;

    return root;
}

struct node *delete(struct node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = delete(root->left, value);

    else if (value > root->data)
        root->right = delete(root->right, value);

    else {
        // Case 1: No left child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        // Case 2: No right child
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(struct node *root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n");
        printf("4. Inorder Traversal\n5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("%d inserted\n", value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = delete(root, value);
            printf("%d deleted\n", value);
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("%d found\n", value);
            else
                printf("%d not found\n", value);
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
