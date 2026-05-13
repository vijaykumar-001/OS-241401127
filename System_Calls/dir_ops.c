#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *de;  // Pointer for directory entry

    // opendir() returns a pointer of DIR type. 
    DIR *dr = opendir(".");

    if (dr == NULL) {
        printf("Could not open current directory\n");
        return 0;
    }

    printf("Listing contents of current directory:\n");
    // readdir() returns a pointer to the next directory entry
    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }

    closedir(dr);    
    return 0;
}
