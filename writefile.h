#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#ifndef WRITEFILE_H
#define WRITEFILE_H

void writeFile(char *filename, char *data, int bytesToWrite, off_t offset) {
    int file = open(filename, O_WRONLY|O_CREAT);
    if (file == -1) {
        printf("Error opening file for writing");
        exit(1);
    }

    int pntr=lseek(file, offset, SEEK_SET);
    printf("\nPointer pos %d",pntr);
    ssize_t bytesWritten = write(file, data, bytesToWrite);
    if (bytesWritten == -1) {
        printf("Error writing to file");
        exit(1);
    }
    printf("Written %zd bytes to file '%s'.\n", bytesWritten, filename);
    close(file);
}


#endif  // MYHEADER_H
