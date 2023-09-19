#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#ifndef COPYUSINGPIPE_H
#define COPYUSINGPIPE_H

void copyFileUsingPipe(char *srcFilename, char *destFilename) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        printf("Error creating pipe");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == -1) {
        printf("Error creating child process");
        exit(1);
    }

    if (pid == 0) {  // Child process (reading from pipe)
        close(pipefd[1]);  // Close unused write end
        int destFile = open(destFilename, O_WRONLY | O_CREAT, 0666);
        if (destFile == -1) {
            printf("Error opening destination file");
            exit(1);
        }

        char buffer[1024];
        ssize_t bytesRead;
        while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            write(destFile, buffer, bytesRead);
        }

        close(pipefd[0]);
        close(destFile);

        printf("Content copied from '%s' to '%s' using an unnamed pipe.\n", srcFilename, destFilename);
    } else {  // Parent process (writing to pipe)
        close(pipefd[0]);  // Close unused read end
        int srcFile = open(srcFilename, O_RDONLY);
        if (srcFile == -1) {
            perror("Error opening source file");
            exit(1);
        }

        char buffer[1024];
        ssize_t bytesRead;
        while ((bytesRead = read(srcFile, buffer, sizeof(buffer))) > 0) {
            write(pipefd[1], buffer, bytesRead);
        }

        close(srcFile);
        close(pipefd[1]);
    }
}


#endif