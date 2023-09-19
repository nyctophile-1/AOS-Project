#include "createfile.h"
#include "readfile.h"
#include "fileinfo.h"
#include "writefile.h"
#include "copyusingpipe.h"
#include "createnamedpipe.h"

int main(int argc, char* argv[]){

    if(argc < 2){
        printf("Usage: %s <option> [arguments]\n", argv[0]);
        printf("Options:\n");
        printf("  1. create <filename> <permissions>\n");
        printf("  2. read <filename> <bytesToRead> <offset>\n");
        printf("  3. write <filename> <data> <bytesToWrite> <offset>\n");
        printf("  4. stat <filename>\n");
        printf("  5. copy <srcFilename> <destFilename>\n");
        printf("  6. createpipe <pipeName> <read/write>\n");

        printf("\033[33mWrite <command --help> for documentation\033[0m\n");
        exit(1);
    }
     
    char* option= argv[1];
    if(argc>2){
    char* argv2 = argv[2];

    if(strcmp(argv2,"--help")==0){
        if(strcmp(option,"create")==0){
            printf("\n\033[33mint creat(const char *pathname, mode_t mode);\033[0m");
            printf("\nThe function call: creat(pathname,mode) is equivalent to the call: \n\033[33mopen(pathname, O_CREAT|O_WRONLY|O_TRUNC, mode);\033[0m\n");
            printf("\nIf successful, creat() returns a file descriptor for the open file. If unsuccessful, creat() returns -1.");
            printf("\nThus the file named by pathname is created, unless it already exists. The file is then opened for writing only, and is truncated to zero length.");
            printf("\nfilename: name of the file which you want to create");
            printf("\nmode: indicates permissions of the new file.");
            printf("\n\n\033[91mUsage: %s create <filename> <permissions>\033[0m\n\n", argv[0]);
            exit(1);
        }
        else if(strcmp(option,"read")==0){
            printf("\n\033[33msize_t read (int fd, void* buf, size_t cnt);\033[0m");
            printf("\nOn success, the number of bytes read is returned (zero indicates end of file), and the file position is advanced by this number. It is not an error if this number is smaller than the number of bytes requested; this may happen for example because fewer bytes are actually available right now (maybe because we were close to end-of-file, or because we are reading from a pipe, or from a terminal), or because read() was interrupted by a signal.\n");
            printf("\nfd    |  file descriptor of the file from which data is to be read.");
            printf("\nbuf   |  buffer to read data from");
            printf("\ncnt   |  length of the buffer\n");
            printf("\n\033[91mUsage: %s read <filename> <bytesToRead> <offset>\033[0m\n",argv[0]);
            exit(1);
        }
        else if(strcmp(option,"write")==0){
            printf("\n\033[33msize_t write (int fd, void* buf, size_t cnt);\033[0m");
            printf("\nReturns the number of bytes written on success.\n");
            printf("\nfd    |  file descriptor of the file from which data is to be read.");
            printf("\nbuf   |  buffer to read data from");
            printf("\ncnt   |  length of the buffer");
            printf("\n\033[91mUsage: %s write <filename> <data> <bytesToWrite> <offset>\033[0m\n", argv[0]);
            exit(1);
        }
        else if(strcmp(option,"stat")==0){
           printf("\n\033[33mint stat(const char *path, struct stat *buf);\033[0m");
           printf("\nIf successfully, 0 is returned and if there are any errors, -1 will be returned.");
           printf("\nHere, const char *path specifies the name of the file. If the path of file is a symbolic link then you need to specify the link instead of file name.");
           printf("\nIn the function we have a stat structure in which the data or information about the file is stored which uses a pointer named buf, which is passed in as a paramteter and filled in during the execution of the call and readable by the user after the call.");
           printf("\nThe stat structure which is defined in <sys/stat.h> header file contains the following fields:\n");
           printf("\n\033[33mst_dev         |It is the ID of device in which we have our file residing currently.");
           printf("\nst_rdev        |This field describes that a particular file represents a particular device.");
           printf("\nst_ino         |It is the inode number or the serial number of the file. As it is an index number so it should be unique for all files");
           printf("\nst_size        |st_size is the size of the file in bytes.");
           printf("\nst_atime       |It is the last time or the recent time at which the file was accessed.");
           printf("\nst_ctime       |It is the recent time at which the status or the permissions of the file was changed.");
           printf("\nst_mtime       |It is the recent time at which the file was modified.");
           printf("\nst_blksize     |This field gives the preferred block size for I/O file system which may vary from file to file.");
           printf("\nst_nlink       |This field tells the total number of hard links.");
           printf("\nst_uid         |This field indicates the user ID.");
           printf("\nst_gid         |This field indicates the group ID.\n");
        exit(1);
        }
        else if(strcmp(option,"copy")==0){
            printf("\n\033[33mMakes use of user defined function copyusingpipe(char* srsfile, char* destfile)\033[0m");
            printf("\nUses Parent child process to copy the contets from one file end to another.\n");
            //More Documentation in the code file submitted on Classroom.
        }
        else if(strcmp(option,"createpipe")==0){
            printf("\nCreates a named pipe for reading and writing.\n");
            //More Documentation in the code file submitted on Classroom.
        }
    }
}
    if(strcmp(option,"create")==0){
         printf("\nArgc %d",argc);
        if(argc!=4){
            printf("Usage: %s create <filename> <permissions>", argv[0]);
            exit(1);
        }
        else{
            printf("\nArgc %d",argc);
            char* filename = argv[2];
            mode_t permissions= atol(argv[3]);
            /*
            Using String to Long Function to convert this value to Long 
            long int strtol(const char *str, char **endptr, int base)
            str − This is the string containing the representation of an integral number.
            endptr − This is the reference to an object of type char*, whose value is set by the function to the next character in str after the numerical value.
            base − This is the base, which must be between 2 and 36 inclusive, or be the special value 0.
            */
            createFile(filename,permissions,0);
            printf("\n\033[1;31mFile %s Created Successfully!!\033[1;0m\n", filename);
        }
    }
    else if(strcmp(option,"read")==0){
        if(argc!=5){
            printf("\n\033[1;31mUsage: %s read <filename> <bytesToRead> <offset>\033[1;0m\n",argv[0]);
            printf("Write %s read --help for documentation\n",argv[0]);
            exit(1);
        }
        else{
            char *filename=argv[2];
            int bytesToRead=atoi(argv[3]);
            off_t offset=atoi(argv[4]);
            readFile(filename,bytesToRead,offset);
        }
    }
    else if (strcmp(option, "write") == 0) {
        if (argc != 6) {
            printf("Usage: %s write <filename> <data> <bytesToWrite> <offset>\n", argv[0]);
            exit(1);
        }
        char *filename = argv[2];
        char *data = argv[3];
        int bytesToWrite = atoi(argv[4]);
        off_t offset = atoi(argv[5]);
        writeFile(filename, data, bytesToWrite, offset);
    }
    else if(strcmp(option,"stat")==0){
        if(argc!=3){
            printf("Usage: %s stat <filename>", argv[0]);
            exit(1);
        }
        char *filename = argv[2];
        displayFileInfo(filename);
    }
    else if (strcmp(option, "copy") == 0) {
        if (argc != 4) {
            printf("Usage: %s copy <srcFilename> <destFilename>\n", argv[0]);
            exit(1);
        }
        char *srcFilename = argv[2];
        char *destFilename = argv[3];
        copyFileUsingPipe(srcFilename, destFilename);
    }
    else if (strcmp(option, "createpipe") == 0) {
        if (argc != 4) {
            printf("Usage: %s createpipe <pipeName> <read/write>\n", argv[0]);
            exit(1);
        }
        char *pipeName = argv[2];
        int isReading = strcmp(argv[3], "read") == 0;
        createNamedPipe(pipeName, isReading);
    } else {
        printf("Invalid option: %s\n", option);
        exit(1);
    }

}
