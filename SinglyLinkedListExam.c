#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} N;

N *head = NULL;
int count = 0;

N *create(int data) {
    N *n = malloc(sizeof(N));
    n->data = data;
    n->next = NULL;
    return n;
}

void insert() {
    int data, pos;
    printf("Enter data and position: ");
    scanf("%d %d", &data, &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position\n");
        return;
    }

    N *n = create(data);

    if (pos == 1) {
        n->next = head;
        head = n;
    } else {
        N *temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        n->next = temp->next;
        temp->next = n;
    }

    count++;
    printf("Inserted successfully\n");
}

/* DELETE */
void deleteNode() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid position\n");
        return;
    }

    N *temp = head;

    if (pos == 1) {
        head = head->next;
    } else {
        N *prev = NULL;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
    }

    free(temp);
    count--;
    printf("Deleted successfully\n");
}

/* DISPLAY */
void display() {
    N *temp = head;
    if (!temp) {
        printf("List is empty\n");
        return;
    }

    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Count 5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: deleteNode(); break;
            case 3: display(); break;
            case 4: printf("Count = %d\n", count); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
