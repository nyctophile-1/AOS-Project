#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#ifndef FILEINFO_H
#define FILEINFO_H

void displayFileInfo(char *filename){
    struct stat fileInfo;
    if (stat(filename, &fileInfo) == -1) {
        perror("Error getting file information");
        exit(1);
    }
    printf("File information for '%s':\n", filename);
    printf("Owner: \t\t\t%d\n", fileInfo.st_uid);
    printf("Permissions: \t\t%o\n", fileInfo.st_mode & 0777);
    printf("Inode: \t\t\t%ld\n", fileInfo.st_ino);//lu
    printf("User Id: \t\t%i\n",fileInfo.st_uid);
    printf("Access time: \t\t%s\n", ctime(&fileInfo.st_atime));
    printf("Modified time: \t\t%s\n", ctime(&fileInfo.st_mtime));
    printf("Status change time: \t%s\n", ctime(&fileInfo.st_ctime));
}

#endif