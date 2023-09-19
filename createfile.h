#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#ifndef CREATEFILE_H
#define CREATEFILE_H

// Header contents go here
void createFile(char* filename, mode_t permissions, int flag){
    if(flag==0){
        int check = creat(filename,permissions);
        if(check==-1){
            /*
            In C, you can use escape sequences to change the color of the text. 
            The basic format of the escape sequence for printing text in color is \033[1;<color code>m,
            where \033 is the escape character and [1;<color code>m is the code for setting the text color.
            */
            printf("\033[1;31mError creating a file!\033[1;0m\n");
            exit(1);
        }
    }
}
#endif  // MYHEADER_H
