#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#ifndef CREATENAMEDPIPE_H
#define CREATENAMEDPIPE_H

void createNamedPipe(char *pipeName, int isReading) {
    if(isReading==1){
    int fd = open(pipeName, O_RDONLY);
    if (fd == -1) {
        printf("\nFailed to open the named pipe.\n");
        exit(1);
    }
    printf("\nFile openend successfully.\n");

    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        printf("Received message: %.*s", (int)bytesRead, buffer);
    }
    
    close(fd);
   
    unlink(pipeName);
    }
    else if(isReading==0){
        printf("\nIn MKFIFO WRITE SECRION\n");
        if (mkfifo(pipeName, 0777) == -1) {
       perror("Error creating named pipe");
        exit(1);
        }      
        printf("\nMyfifo is created successfully.\n");
        int fd = open(pipeName, O_WRONLY);
        if (fd == -1) {
            printf("\nFailed to open the named pipe.\n");
            exit(1);
        }
        printf("\nFile opened successfully.\n");
        char buffer[1024];
        ssize_t bytesRead;
        write(fd,"Hello from One End of the Pipe!!",sizeof("Hello from One End of the Pipe!!"));
        // Close the named pipe
        close(fd);
        // Remove the named pipe file
       unlink(pipeName);

    }
    printf("Named pipe '%s' created successfully for %s.\n", pipeName, isReading ? "reading" : "writing");
}


#endif