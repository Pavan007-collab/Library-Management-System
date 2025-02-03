#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int available;
};

void displayBooks(struct Book books[], int count) {
    printf("\nBooks in Library:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s (Available: %d)\n", i + 1, books[i].title, books[i].author, books[i].available);
    }
}

int main() {
    struct Book books[10] = {
        {"C Programming", "Dennis Ritchie", 5},
        {"Data Structures", "Mark Allen Weiss", 3},
        {"Algorithms", "Robert Sedgewick", 2}
    };
    int choice, bookChoice;

    while (1) {
        printf("\n1. Display Books\n2. Check Out a Book\n3. Return a Book\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks(books, 3);
                break;
            case 2:
                printf("Enter book number to check out: ");
                scanf("%d", &bookChoice);
                if (books[bookChoice - 1].available > 0) {
                    books[bookChoice - 1].available--;
                    printf("You have successfully checked out the book!\n");
                } else {
                    printf("Sorry, this book is not available.\n");
                }
                break;
            case 3:
                printf("Enter book number to return: ");
                scanf("%d", &bookChoice);
                books[bookChoice - 1].available++;
                printf("You have successfully returned the book!\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
