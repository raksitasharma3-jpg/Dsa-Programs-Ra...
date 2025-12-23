#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
struct List {
    int list[MAX];
    int length;
};
struct List l;
int menu(void);
void create(void);
void insert(int, int);
void delet(int);
void find(int);
void display(void);
bool islistfull(void);
bool islistempty(void);
int menu(void) {
    int ch;
    printf("\n1. Create\n2. Insert\n3. Delete\n4. Count\n5. Find\n6. Display\n7. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}
void create(void) {
    int element;
    char choice;
    if (!islistempty()) {
        printf("List already exists. Creating again will erase old data.\n");
        l.length = 0;
    }
    do {
        if (islistfull()) {
            printf("List is full.\n");
            break;
        }
        printf("Enter element: ");
        scanf("%d", &element);
        l.list[l.length] = element;
        l.length++;
        printf("Add another element? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}
void insert(int element, int pos) {
    if (islistfull()) {
        printf("List is full.\n");
        return;
    }
    if (pos < 1 || pos > l.length + 1) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = l.length - 1; i >= pos - 1; i--) {
        l.list[i + 1] = l.list[i];
    }
    l.list[pos - 1] = element;
    l.length++;
    printf("Element inserted successfully.\n");
}
void delet(int pos) {
    if (islistempty()) {
        printf("List is empty.\n");
        return;
    }
    if (pos < 1 || pos > l.length) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos - 1; i < l.length - 1; i++) {
        l.list[i] = l.list[i + 1];
    }
    l.length--;
    printf("Element deleted successfully.\n");
}
void find(int element) {
    if (islistempty()) {
        printf("List is empty.\n");
        return;
    }
    for (int i = 0; i < l.length; i++) {
        if (l.list[i] == element) {
            printf("Element %d found at position %d.\n", element, i + 1);
            return;
        }
    }
    printf("Element not found.\n");
}
void display(void) {
    if (islistempty()) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements:\n");
    for (int i = 0; i < l.length; i++) {
        printf("%d ", l.list[i]);
    }
    printf("\n");
}
bool islistfull(void) {
    return l.length == MAX;
}
bool islistempty(void) {
    return l.length == 0;
}
int main(void) {
    int ch, element, pos;
    l.length = 0;
    while (1) {
        ch = menu();
        switch (ch) {
        case 1:
            create();
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &element);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert(element, pos);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            delet(pos);
            break;
        case 4:
            printf("Total elements: %d\n", l.length);
            break;
        case 5:
            printf("Enter element to find: ");
            scanf("%d", &element);
            find(element);
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}


