#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int count = 0;

void producer() {
    int item;

    for (int i = 0; i < 10; i++) {

        // If buffer is full
        if (count == BUFFER_SIZE) {
            printf("Buffer FULL! Producer waiting...\n");
        }

        else {
            item = rand() % 100;

            buffer[in] = item;
            printf("Producer produced: %d at index %d\n", item, in);

            in = (in + 1) % BUFFER_SIZE;
            count++;
        }

        sleep(1);
    }
}

void consumer() {
    int item;

    for (int i = 0; i < 10; i++) {

        // If buffer is empty
        if (count == 0) {
            printf("Buffer EMPTY! Consumer waiting...\n");
        }

        else {
            item = buffer[out];
            printf("Consumer consumed: %d from index %d\n", item, out);

            out = (out + 1) % BUFFER_SIZE;
            count--;
        }

        sleep(2);
    }
}

int main() {
    printf("Producer Consumer Problem (Without Threads)\n\n");

    producer();
    consumer();

    return 0;
}
