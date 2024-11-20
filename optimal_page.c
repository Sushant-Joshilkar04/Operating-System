#include <stdio.h>
#include <stdbool.h>

void display(int frame[], int size) {
    for (int i = 0; i < size; i++) 
        printf(" %d ", frame[i]);
    printf("\n");
}

bool contains(int frame[], int size, int ele) {
    for (int i = 0; i < size; i++) 
        if (frame[i] == ele) 
            return true;
    return false;
}

int farthest(int pages[], int n, int page, int idx) {
    for (int i = idx; i < n; i++) {
        if (pages[i] == page) 
            return i; // Return the first occurrence after idx
    }
    return n; // Return n if not found in the future
}

int main() {
    int n;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter pages: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &pages[i]);

    int size;
    printf("Enter page frame size: ");
    scanf("%d", &size);
    int frame[size];

    for (int i = 0; i < size; i++) 
        frame[i] = -1;

    int hit = 0, fault = 0;

   for (int i = 0; i < n; i++) {
        if (!contains(frame, size, pages[i])) {

            int replaceIdx = -1;

           
            for (int j = 0; j < size; j++) {
                if (frame[j] == -1) {
                    replaceIdx = j;
                    break;
                }
            }

            if (replaceIdx == -1) {
                int farthestIdx = -1, maxDist = -1;
                for (int j = 0; j < size; j++) {
                    int dist = farthest(pages, n, frame[j], i + 1);
                    if (dist > maxDist) {
                        maxDist = dist;
                        farthestIdx = j;
                    }
                }
                replaceIdx = farthestIdx;
            }


            frame[replaceIdx] = pages[i];
            fault++;
            display(frame, size);
            printf("Fault\n");
        } else {

            hit++;
            display(frame, size);
            printf("Hit\n");
        }
    }
    printf("Hit: %d Fault: %d Pages: %d\n", hit, fault, n);
    return 0;
}

