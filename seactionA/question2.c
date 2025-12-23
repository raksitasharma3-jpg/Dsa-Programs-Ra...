#include <stdio.h>
#include <stdlib.h>
struct Node {
    int e;
    struct Node *next;
};
typedef struct Node *List;
typedef struct Node *Position;
void Insert(int x, List l, Position p) {
    Position TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("Memory out of space\n");
        return;
    }
    TmpCell->e = x;
    TmpCell->next = p->next;
    p->next = TmpCell;
}
int isLast(Position p) {
    return (p->next == NULL);
}
Position FindPrevious(int x, List l) {
    Position p = l;
    while (p->next != NULL && p->next->e != x)
        p = p->next;
    return p;
}
void Delete(int x, List l) {
    Position p, TmpCell;
    p = FindPrevious(x, l);
    if (!isLast(p)) {
        TmpCell = p->next;
        p->next = TmpCell->next;
        free(TmpCell);
    } else {
        printf("Element does not exist\n");
    }
}
void Display(List l) {
    Position p = l->next;
    printf("List: ");
    while (p != NULL) {
        printf("%d -> ", p->e);
        p = p->next;
    }
    printf("NULL\n");
}
void Merge(List l, List l1) {
    int n, x;
    Position p;
    printf("Enter number of elements in second list: ");
    scanf("%d", &n);
    p = l1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        Insert(x, l1, p);
        p = p->next;
    }
    p = l;
    while (p->next != NULL)
        p = p->next;

    p->next = l1->next;
}
int main() {
    int x, pos, ch;
    List l, l1;
    Position p;
    l = (List)malloc(sizeof(struct Node));
    if (l == NULL) return 0;
    l->next = NULL;
    do {
        printf("\n1.Insert 2.Delete 3.Merge 4.Display 5.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            printf("Enter position: ");
            scanf("%d", &pos);
            p = l;
            for (int i = 1; i < pos && p->next != NULL; i++)
                p = p->next;
            Insert(x, l, p);
            break;
        case 2:
            printf("Enter element to delete: ");
            scanf("%d", &x);
            Delete(x, l);
            break;
        case 3:
            l1 = (List)malloc(sizeof(struct Node));
            if (l1 == NULL) break;
            l1->next = NULL;
            Merge(l, l1);
            break;

        case 4:
            Display(l);
            break;
        }
    } while (ch != 5);
    return 0;
}	
