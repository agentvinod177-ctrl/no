#include <stdio.h>

int main() {
    int incoming, outgoing, buck_size, n, store = 0;

    printf("Enter bucket size, outgoing rate, and number of packets: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    while (n > 0) {

        printf("Enter incoming packet: ");
        scanf("%d", &incoming);

        printf("Incoming = %d\n", incoming);

        if (incoming <= (buck_size - store)) {
            store = store + incoming;
            printf("Bucket now has %d out of %d\n", store, buck_size);
        } 
        else {
            int drop = incoming - (buck_size - store);
            printf("Dropped = %d\n", drop);
            printf("Bucket is full: %d out of %d\n", store, buck_size);
            store = buck_size;
        }

        store = store - outgoing;
        if (store < 0)
            store = 0;

        printf("After sending, bucket has %d left\n", store);

        n--;
    }
}
