#include <stdio.h>
#include <string.h>

struct Book {
    long int number;
    char name[100];
    char author[100];
    char genre[30];
    float price;
};

struct Order {
    int orderNumber;
    char name[100];
    char address[1000];
    int orderCount;
    struct Book books[100];
    float totalPrice;
};

void sortOrdersByTotalPrice(struct Order orders[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (orders[j].totalPrice < orders[j + 1].totalPrice) {
                struct Order temp = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);
    getchar();

    struct Order orders[n];

    for (int i = 0; i < n; i++) {
        struct Order order;

        order.orderNumber = i + 1;

        scanf("%d", &order.orderCount);
        getchar();

        fgets(order.name, sizeof(order.name), stdin);
        order.name[strcspn(order.name, "\n")] = '\0';

        fgets(order.address, sizeof(order.address), stdin);
        order.address[strcspn(order.address, "\n")] = '\0';

        struct Book book;

        for (int j = 0; j < order.orderCount; j++) {
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

            order.books[j] = book;
        }

        scanf("%f", &order.totalPrice);
        getchar();

        orders[i] = order;
    }

    sortOrdersByTotalPrice(orders, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", orders[i].orderNumber);
    }

    return 0;
}
