#include <stdio.h>
#include <stdbool.h>

void display(int size, int frame[]) {
    for (int i = 0; i < size; i++) {
        if (frame[i] == -1)
            printf("_ ");
        else
            printf("%d ", frame[i]);
    }
    printf("\n");
}

bool contains(int n, int frame[], int size) {
    for (int i = 0; i < size; i++) {
        if (frame[i] == n)
            return true;
    }
    return false;
}

int check_least_recently_used(int arr[], int idx, int size, int frame[]) {
    int least_recent = idx;
    int index = -1;

    for (int i = 0; i < size; i++) {
        int j = idx - 1;
        while (j >= 0) {
            if (arr[j] == frame[i]) {
                if (j < least_recent) {
                    least_recent = j;
                    index = i;
                }
                break;
            }
            j--;
        }

        // If the page is not used before, return its index immediately.
        if (j < 0) {
            return i;
        }
    }
    return index;
}

int main() {
    printf("Enter number of pages: ");
    int n = 0;
    int hit = 0;
    int fault = 0;
    scanf("%d", &n);
    int arr[n];
    printf("Enter pages: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int size = 0;
    printf("Enter page frame size: ");
    scanf("%d", &size);

    int frame[size];
    for (int i = 0; i < size; i++) {
        frame[i] = -1; // Initialize the frame with invalid values.
    }

    printf("\nSimulation:\n");
    for (int i = 0; i < n; i++) {
        if (contains(arr[i], frame, size)) {
            display(size, frame);
            printf("Hit\n");
            hit++;
        } else {
            int idx = -1;

            // Find an empty slot in the frame.
            for (int j = 0; j < size; j++) {
                if (frame[j] == -1) {
                    idx = j;
                    break;
                }
            }

            // If no empty slot is found, use LRU policy to find replacement index.
            if (idx == -1) {
                idx = check_least_recently_used(arr, i, size, frame);
            }

            // Replace the page.
            frame[idx] = arr[i];
            display(size, frame);
            printf("Fault\n");
            fault++;
        }
    }

    printf("\nTotal Hits = %d\n", hit);
    printf("Total Faults = %d\n", fault);

    return 0;
}
