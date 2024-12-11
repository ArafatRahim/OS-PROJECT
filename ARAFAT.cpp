#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <direct.h>
#include <unistd.h>

// Function prototypes
void readFile();
void writeFile();
void clearScreen();
void showHelp();
void showDateTime();
void showStartScreen();
void removeFile();
void listFiles();
void whoami();
void printWorkingDirectory();
void createDir();
void listDir();
void createFile();
void changeDir();
void copyFile();
void echoText();
void sleepFunc();
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
void exitTerminal();

int main() {
    char command[100];
    char input[500];
    printf("\nWelcome to Provat's Terminal\n\n\n");
    //printf("Provat's Terminal\n\n");
    printf("WELCOME, TODAY IS \n\n");
    showDateTime();

    printf("\n\nType \"help\" for more commands!\n\n");

    while (1) {
        printf(">>> ");
        fflush(stdin);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';  // Remove trailing newline

        if (strcmp(command, "read") == 0) {
            readFile();
        } else if (strcmp(command, "write") == 0) {
            writeFile();
        } else if (strcmp(command, "clr") == 0) {
            clearScreen();
        } else if (strcmp(command, "help") == 0) {
            showHelp();
        } else if (strcmp(command, "dt") == 0) {
            showDateTime();
        } else if (strcmp(command, "stscr") == 0) {
            showStartScreen();
        } else if (strcmp(command, "rm") == 0) {
            removeFile();
        } else if (strcmp(command, "ls") == 0) {
            listFiles();
        } else if (strcmp(command, "whoami") == 0) {
            whoami();
        } else if (strcmp(command, "pwd") == 0) {
            printWorkingDirectory();
        } else if (strcmp(command, "mkdir") == 0) {
            createDir();
        } else if (strcmp(command, "dir") == 0) {
            listDir();
        } else if (strcmp(command, "touch") == 0) {
            createFile();
        } else if (strcmp(command, "cd") == 0) {
            changeDir();
        } else if (strcmp(command, "cp") == 0) {
            copyFile();
        } else if (strcmp(command, "echo") == 0) {
            echoText();
        } else if (strcmp(command, "sleep") == 0) {
            sleepFunc();
        } else if (strcmp(command, "head") == 0) {
            head();
        } else if (strcmp(command, "tail") == 0) {
            tail();
        } else if (strcmp(command, "less") == 0) {
            less();
        } else if (strcmp(command, "nano") == 0) {
            nano();
        } else if (strcmp(command, "uname") == 0) {
            uname();
        } else if (strcmp(command, "hostname") == 0) {
            hostname();
        } else if (strcmp(command, "find") == 0) {
            find();
        } else if (strcmp(command, "w") == 0) {
            w();
        } else if (strcmp(command, "ps") == 0) {
            ps();
        } else if (strcmp(command, "cat") == 0) {
            cat();
        } else if (strcmp(command, "exit") == 0) {
            exitTerminal();
        } else {
            printf("Unknown command. Type \"help\" for a list of commands.\n");
        }
    }

    return 0;
}

// Function implementations
void readFile() {
    char filename[100];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void writeFile() {
    char filename[100];
    char content[500];
    printf("Enter the name of the file to write to: ");
    scanf("%s", filename);
    getchar();  // Clear the newline character left in the input buffer
    printf("Enter the content to write into the file:\n");
    fgets(content, sizeof(content), stdin);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open or create the file '%s'.\n", filename);
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("Content successfully written to '%s'.\n", filename);
}

void clearScreen() {
    system("cls || clear");
}

void showDateTime() {
    time_t tt = time(NULL);
    printf("%s", ctime(&tt));
}

void showStartScreen() {
    clearScreen();
    printf("Provat's Terminal\n\n");
    showDateTime();
    printf("Welcome to Provat's Terminal\n");
    printf("Type \"help\" for more commands!\n\n");
}

void removeFile() {
    char filename[100];
    printf("Enter a file name to remove: ");
    scanf("%s", filename);
    if (remove(filename) == 0) {
        printf("Successfully removed the file '%s'.\n", filename);
    } else {
        printf("Error: Could not remove the file. Ensure it exists.\n");
    }
}

void listFiles() {
    system("dir || ls");
}

void whoami() {
    system("whoami");
}

void printWorkingDirectory() {
    system("pwd");
}

void createDir() {
    char dirname[100];
    printf("Enter directory name to create: ");
    scanf("%s", dirname);
    char command[150];
    sprintf(command, "mkdir %s", dirname);
    system(command);
}

void listDir() {
    listFiles();
}

void createFile() {
    char filename[100];
    printf("Enter file name to create: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    if (file) {
        fclose(file);
        printf("File '%s' created successfully.\n", filename);
    } else {
        printf("Error: Could not create the file '%s'.\n", filename);
    }
}

void changeDir() {
    char path[100];
    printf("Enter the path to change directory: ");
    scanf("%s", path);
    if (chdir(path) == 0) {
        printf("Changed to directory '%s'.\n", path);
    } else {
        printf("Error: Could not change directory to '%s'.\n", path);
    }
}

void copyFile() {
    printf("This command is not implemented yet.\n");
}

void echoText() {
    char text[500];
    getchar();  // Clear the newline character left by the previous input
    printf("Enter text to echo: ");
    fgets(text, sizeof(text), stdin);
    printf("%s", text);
}

void sleepFunc() {
    int seconds;
    printf("Enter time in seconds to sleep: ");
    scanf("%d", &seconds);
    sleep(seconds);
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

void showHelp() {
    printf("\nAvailable commands:\n\n");
    printf("read      >>> To read a file\n");
    printf("write     >>> To write to a file\n");
    printf("rm        >>> To remove a file\n");
    printf("clr       >>> To clear the screen\n");
    printf("dt        >>> To show date and time\n");
    printf("stscr     >>> To show start screen\n");
    printf("ls        >>> To list files\n");
    printf("whoami    >>> To display current user\n");
    printf("pwd       >>> To print the working directory\n");
    printf("mkdir     >>> To create a directory\n");
    printf("dir       >>> To list files (alias for ls)\n");
    printf("touch     >>> To create an empty file\n");
    printf("cd        >>> To change directory\n");
    printf("echo      >>> To echo text\n");
    printf("sleep     >>> To sleep for a specified time\n");
    printf("uname     >>> To display system information\n");
    printf("hostname  >>> To display the hostname\n");
    printf("exit      >>> To exit the terminal\n");
}

void exitTerminal() {
    printf("Exiting the terminal...\n");
    exit(0);
}
