#include <stdio.h>
#include <string.h>

struct Book {
    long int number;
    char name[100];
    char author[100];
    char genre[30];
    float price;
};

int main() {
    int n;

    scanf("%d", &n);
    getchar();

    struct Book books[n];
    struct Book book;

    for (int i = 0; i < n; i++) {
        scanf("%ld", &book.number);
        getchar();
        fgets(book.name, sizeof(book.name), stdin);
        book.name[strcspn(book.name, "\n")] = '\0';
        fgets(book.author, sizeof(book.author), stdin);
        book.author[strcspn(book.author, "\n")] = '\0';
        fgets(book.genre, sizeof(book.genre), stdin);
        book.genre[strcspn(book.genre, "\n")] = '\0';
        scanf("%f", &book.price);
        getchar(); 
        books[i] = book;
    }

    char inputGenre[30];
    fgets(inputGenre, sizeof(inputGenre), stdin);
    inputGenre[strcspn(inputGenre, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (!strcmp(books[i].genre, inputGenre)) {
            printf("%s\n", books[i].name);
        }
    }

    return 0;
}
