#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <direct.h>

// Function prototypes
void read();
void write();
void clear();
void help();
void dt();
void exits();
void startscreen();
void rm();
void ls();
void whoami();
void pwd();
void mkdir();
void dir();
void touch();
void cd();
void cp();
void echo();
void sleep_func();
void head();
void tail();
void less();
void nano();
void uname();
void hostname();
void find();
void w();
void ps();
void cat();

int main() {
    char a[100];

    printf("Nuzhat's Terminal\n\n");

    dt();
    printf("Welcome To Nuzhat's Terminal\n");
    printf("Type \"help\" for more things!\n\n");

    while (1) {
        printf(">>> ");
        fflush(stdin);
        scanf("%s", a);

        if (strcmp(a, "read") == 0) {
            read();
        } else if (strcmp(a, "write") == 0) {
            write();
        } else if (strcmp(a, "clr") == 0) {
            clear();
        } else if (strcmp(a, "help") == 0) {
            help();
        } else if (strcmp(a, "dt") == 0) {
            dt();
        } else if (strcmp(a, "stscr") == 0) {
            startscreen();
        } else if (strcmp(a, "rm") == 0) {
            rm();
        } else if (strcmp(a, "ls") == 0) {
            ls();
        } else if (strcmp(a, "whoami") == 0) {
            whoami();
        } else if (strcmp(a, "pwd") == 0) {
            pwd();
        } else if (strcmp(a, "mkdir") == 0) {
            mkdir();
        } else if (strcmp(a, "dir") == 0) {
            dir();
        } else if (strcmp(a, "touch") == 0) {
            touch();
        } else if (strcmp(a, "cd") == 0) {
            cd();
        } else if (strcmp(a, "cp") == 0) {
            cp();
        } else if (strcmp(a, "echo") == 0) {
            echo();
        } else if (strcmp(a, "sleep") == 0) {
            sleep_func();
        } else if (strcmp(a, "head") == 0) {
            head();
        } else if (strcmp(a, "tail") == 0) {
            tail();
        } else if (strcmp(a, "less") == 0) {
            less();
        } else if (strcmp(a, "nano") == 0) {
            nano();
        } else if (strcmp(a, "uname") == 0) {
            uname();
        } else if (strcmp(a, "hostname") == 0) {
            hostname();
        } else if (strcmp(a, "find") == 0) {
            find();
        } else if (strcmp(a, "w") == 0) {
            w();
        } else if (strcmp(a, "ps") == 0) {
            ps();
        } else if (strcmp(a, "cat") == 0) {
            cat();
        } else if (strcmp(a, "exit") == 0) {
            exits();
        } else {
            printf("Enter only stated things in help\n");
        }
    }

    return 0;
}

// Function implementations
void read() {
    char filename[100];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void write() {
    char filename[100];
    char content[500];
    FILE *file;

    printf("Enter the name of the file to write to (it will be created if it doesn't exist): ");
    scanf("%s", filename);

    getchar(); // Clear the newline character left in the input buffer
    printf("Enter the content to write into the file:\n");
    fgets(content, sizeof(content), stdin);

    // Open the file in write mode
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open or create the file.\n");
        return;
    }

    // Write content to the file
    fprintf(file, "%s", content);
    fclose(file);

    printf("Content successfully written to the file '%s'.\n", filename);
}

void clear() {
    system("cls || clear");
}

void dt() {
    time_t tt = time(NULL);
    printf("%s", ctime(&tt));
}

void startscreen() {
    clear();
    printf("Nuzhat Terminal\n\n");
    dt();
    printf("Welcome To Nuzhat Terminal\n");
    printf("Type \"help\" for more things!\n\n");
}

void rm() {
    char filename[100];
    printf("Enter a file name to remove: ");
    scanf("%s", filename);

    if (remove(filename) == 0) {
        printf("Successfully removed the file '%s'.\n", filename);
    } else {
        printf("Error: Could not remove the file. Ensure it exists.\n");
    }
}

void ls() {
    system("dir || ls");
}

void whoami() {
    system("whoami");
}

void pwd() {
    system("pwd");
}

void mkdir() {
    char dirname[100];
    printf("Enter directory name to create: ");
    scanf("%s", dirname);
    char command[150];
    sprintf(command, "mkdir %s", dirname);
    system(command);
}

void dir() {
    ls();
}

void touch() {
    char filename[100];
    printf("Enter file name to create: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    if (file) {
        fclose(file);
        printf("File '%s' created successfully.\n", filename);
    } else {
        printf("Error: Could not create the file.\n");
    }
}

void cd() {
    char path[100];
    printf("Enter the path to change directory: ");
    scanf("%s", path);
    if (chdir(path) == 0) {
        printf("Changed to directory '%s'.\n", path);
    } else {
        printf("Error: Could not change directory.\n");
    }
}

void cp() {
    printf("This command is not implemented yet.\n");
}

void echo() {
    char text[500];
    printf("Enter text to echo: ");
    getchar(); // Clear the newline character
    fgets(text, sizeof(text), stdin);
    printf("%s", text);
}

void sleep_func() {
    int seconds;
    printf("Enter time in seconds to sleep: ");
    scanf("%d", &seconds);
    char command[50];
    sprintf(command, "sleep %d", seconds);
    system(command);
}

void head() {
    printf("This command is not implemented yet.\n");
}

void tail() {
    printf("This command is not implemented yet.\n");
}

void less() {
    printf("This command is not implemented yet.\n");
}

void nano() {
    printf("This command is not implemented yet.\n");
}

void uname() {
    system("uname -a");
}

void hostname() {
    system("hostname");
}

void find() {
    printf("This command is not implemented yet.\n");
}

void w() {
    system("w");
}

void ps() {
    system("ps");
}

void cat() {
    printf("This command is not implemented yet.\n");
}

void help() {
    printf("\nYou can enter the following commands:\n\n");
    printf("read    >>> To read a file\n");
    printf("write   >>> To write to a file\n");
    printf("rm      >>> To remove a file\n");
    printf("clr     >>> To clear the screen\n");
    printf("dt      >>> To show date and time\n");
    printf("stscr   >>> To show start screen\n");
    printf("ls      >>> To list files\n");
    printf("whoami  >>> To display current user\n");
    printf("pwd     >>> To print working directory\n");
    printf("mkdir   >>> To create a directory\n");
    printf("dir     >>> To list files (alias for ls)\n");
    printf("touch   >>> To create an empty file\n");
    printf("cd      >>> To change directory\n");
    printf("echo    >>> To echo text\n");
    printf("sleep   >>> To sleep for a specified time\n");
    printf("uname   >>> To display system information\n");
    printf("hostname>>> To display the hostname\n");
    printf("exit    >>> To exit the terminal\n");
}

void exits() {
    exit(0);
}

