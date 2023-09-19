#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#ifndef READFILE_H
#define READFILE_H

void readFile(char* filename,int bytesToRead,off_t offset){
    int file=open(filename,O_RDONLY);
    if(file==-1){
        printf("\033[1;31mError reading from %s!\033[1;0m\n",filename);
        exit(1);
    }
    else{
        char *buffer = malloc(bytesToRead);
        /*
        A malloc is used to allocate a specified size of memory block at the run time of a program. 
        It means it creates a dynamic memory allocation at the run time when the user/programmer does 
        not know the amount of memory space is needed in the program.
        */
        lseek(file, offset, SEEK_SET);
        /*
        lseek() system call repositions the read/write file offset i.e., 
        it changes the positions of the read/write pointer within the file. 
        In every file any read or write operations happen at the position pointed to by the pointer.
        lseek() system call helps us to manage the position of this pointer within a file.
        */
        ssize_t bytesRead = read(file, buffer, bytesToRead);
        if (bytesRead == -1) {
        printf("\033[1;31mError reading from %s!\033[1;0m\n",filename);
        exit(1);
        }
        printf("Read %zd bytes from file '%s':\n", bytesRead, filename);
        printf("%.*s\n", (int)bytesRead, buffer);
        free(buffer);
        close(file);
    }
}

#endif  // MYHEADER_H

// Header contents go here