#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} N;

/* ---------- CREATE TREE ---------- */
N* insert() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    N *new = (N*)malloc(sizeof(N));
    new->data = x;

    printf("Enter left child of %d\n", x);
    new->left = insert();

    printf("Enter right child of %d\n", x);
    new->right = insert();

    return new;
}

/* ---------- DELETE NODE ---------- */
N* delnode(N *root, int x) {
    if (!root) return NULL;

    // Case: single node
    if (!root->left && !root->right) {
        if (root->data == x) {
            free(root);
            return NULL;
        }
        return root;
    }

    N *queue[100];
    int front = 0, rear = 0;

    N *temp;
    N *key = NULL;
    N *deep = NULL;
    N *parent = NULL;

    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];

        if (temp->data == x)
            key = temp;

        if (temp->left) {
            parent = temp;
            queue[rear++] = temp->left;
        }

        if (temp->right) {
            parent = temp;
            queue[rear++] = temp->right;
        }
    }

    deep = temp;  // last node = deepest

    if (!key) {
        printf("Node not found\n");
        return root;
    }

    // Replace target node data
    key->data = deep->data;

    // Remove deepest node
    if (parent->right == deep) {
        free(parent->right);
        parent->right = NULL;
    } else {
        free(parent->left);
        parent->left = NULL;
    }

    return root;
}

/* ---------- TRAVERSALS ---------- */
void inorder(N *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(N *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(N *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* ---------- FREE TREE ---------- */
void freetree(N *root) {
    if (!root) return;
    freetree(root->left);
    freetree(root->right);
    free(root);
}

/* ---------- MAIN ---------- */
int main() {
    N *root = NULL;
    int choice, val;

    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Create Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                freetree(root);
                root = insert();
                break;

            case 2:
                if (!root) printf("Tree empty\n");
                else { printf("Inorder: "); inorder(root); printf("\n"); }
                break;

            case 3:
                if (!root) printf("Tree empty\n");
                else { printf("Preorder: "); preorder(root); printf("\n"); }
                break;

            case 4:
                if (!root) printf("Tree empty\n");
                else { printf("Postorder: "); postorder(root); printf("\n"); }
                break;

            case 5:
                if (!root) printf("Tree empty\n");
                else {
                    printf("Enter value to delete: ");
                    scanf("%d", &val);
                    root = delnode(root, val);
                }
                break;

            case 6:
                freetree(root);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

