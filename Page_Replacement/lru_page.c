#include <stdio.h>

int main() {
    int n, frames;

    printf("Enter number of pages in reference string: \n");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the reference string: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: \n");
    scanf("%d", &frames);

    int frame[frames], time[frames];
    
    // Initialize
    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    int pageFaults = 0, pageHits = 0, counter = 0;

    for(int i = 0; i < n; i++) {
        int found = 0;

        // Check for Hit
        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                pageHits++;
                counter++;
                time[j] = counter;  // update recent use
                break;
            }
        }

        // Page Fault
        if(!found) {
            int lruIndex = 0;

            // Find least recently used
            for(int j = 1; j < frames; j++) {
                if(time[j] < time[lruIndex]) {
                    lruIndex = j;
                }
            }

            counter++;
            frame[lruIndex] = pages[i];
            time[lruIndex] = counter;
            pageFaults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);

    return 0;
}
