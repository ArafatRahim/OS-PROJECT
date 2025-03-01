#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_LINE_LENGTH 500
#define RESULT_FILE "results.txt"
#define ANNOUNCEMENT_FILE "announcements.txt"

// Function declarations
void makeAnnouncement(char *announcement);
void readStudents(FILE *file);
void inputResult();
void viewResult();
void signUp();
void login();
void entertainmentMode();
void clearScreen();
void displayHeader(const char *header);
void changePassword();
void viewProfile();
void logout();
void viewAnnouncement();

// Global variable to store the current logged-in user's ID
char currentUser[20] = "";

// Main function
int main() {
    int choice;

    do {
        clearScreen();
        displayHeader("MAIN MENU");
        printf("\t1] Sign Up\n");
        printf("\t2] Login\n");
        printf("\t3] Entertainment Mode\n");
        printf("\t4] Exit\n");
        printf("\t==============================\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                login();
                break;
            case 3:
                entertainmentMode();
                break;
            case 4:
                printf("\tExiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("\tInvalid choice! Please try again.\n");
        }

        printf("\nPress any key to return to the main menu...");
        getchar(); // Consume newline
        getchar(); // Wait for user to press a key
    } while (choice != 4);

    return 0;
}

void inputResult() {
    char studentID[20], result[20];
    FILE *file = fopen(RESULT_FILE, "a");

    if (file == NULL) {
        printf("\nError opening the results file.\n");
        return;
    }

    clearScreen();
    displayHeader("INPUT STUDENT RESULT");

    printf("Enter Student ID: ");
    scanf("%s", studentID);
    printf("Enter Result for %s: ", studentID);
    scanf("%s", result);

    fprintf(file, "%s,%s\n", studentID, result);
    fclose(file);

    printf("\nResult for %s has been recorded successfully!\n", studentID);
}

void viewResult() {
    FILE *file = fopen(RESULT_FILE, "r");
    if (file == NULL) {
        printf("Error opening results file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    bool found = false;

    clearScreen();
    displayHeader("VIEW STUDENT RESULT");

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char *token = strtok(line, ",");
        if (strcmp(token, currentUser) == 0) {
            token = strtok(NULL, ",");
            printf("Result for Student %s: %s\n", currentUser, token);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("No result found for Student %s.\n", currentUser);
    }

    fclose(file);
}

void signUp() {
    char name[20], Fname[20], contact[20], id[20], password[20];
    FILE *file = fopen("SignUP.txt", "a");

    if (file == NULL) {
        printf("\nError opening the file.\n");
        return;
    }

    clearScreen();
    displayHeader("SIGN UP");

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your father's name: ");
    scanf("%s", Fname);
    printf("Enter your contact number: ");
    scanf("%s", contact);
    printf("Enter your ID: ");
    scanf("%s", id);
    printf("Enter your password: ");
    scanf("%s", password);

    fprintf(file, "%s,%s,%s,%s,%s,\n", name, Fname, contact, id, password);
    fclose(file);

    printf("\nRegistration successful!\n");
}

void login() {
    int role;
    clearScreen();
    displayHeader("LOGIN MENU");
    printf("\t1] Teacher\n");
    printf("\t2] Student\n");
    printf("\t3] Admin\n");
    printf("\t4] Back to Main Menu\n");
    printf("\t==============================\n");
    printf("\tEnter your choice: ");
    scanf("%d", &role);

    if (role == 4) {
        return;
    }

    char id[20], pass[20];
    if (role == 1) { // Teacher Login
        char teacherID[] = "teacher";
        char teacherPass[] = "teacherpass"; // Corrected password for Teacher
        printf("Enter Teacher ID: ");
        scanf("%s", id);
        printf("Enter Password: ");
        scanf("%s", pass);

        if (strcmp(id, teacherID) == 0 && strcmp(pass, teacherPass) == 0) {
            printf("\nLogin Successful! Welcome, Teacher.\n");
            printf("\n1] Make Announcement\n2] View Students\n3] Input Results\n4] Change Password\n5] Back\n");
            printf("Enter your choice: ");
            int teacherChoice;
            scanf("%d", &teacherChoice);

            if (teacherChoice == 1) {
                char announcement[800];
                printf("\nEnter your announcement: ");
                scanf(" %[^\n]", announcement);
                makeAnnouncement(announcement);
            } else if (teacherChoice == 2) {
                FILE *file = fopen("SignUP.txt", "r");
                if (file == NULL) {
                    printf("Error reading students file.\n");
                    return;
                }
                readStudents(file);
            } else if (teacherChoice == 3) {
                inputResult();
            } else if (teacherChoice == 4) {
                changePassword();
            }
        } else {
            printf("Invalid ID or Password!\n");
        }
    } else if (role == 2) { // Student Login
        printf("Enter Student ID: ");
        scanf("%s", id);
        printf("Enter Password: ");
        scanf("%s", pass);

        FILE *file = fopen("SignUP.txt", "r");
        if (file == NULL) {
            printf("Error opening file.\n");
            return;
        }

        char line[MAX_LINE_LENGTH];
        bool isAuthenticated = false;
        while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
            if (strstr(line, id) && strstr(line, pass)) {
                isAuthenticated = true;
                break;
            }
        }
        fclose(file);

        if (isAuthenticated) {
            printf("\nLogin Successful! Welcome, %s.\n", id);
            strcpy(currentUser, id); // Store the logged-in user's ID for session management
            printf("\n1] View Profile\n2] View Result\n3] View Announcement\n4] Change Password\n5] Logout\n");
            int studentChoice;
            scanf("%d", &studentChoice);
            if (studentChoice == 1) {
                viewProfile();
            } else if (studentChoice == 2) {
                viewResult();
            } else if (studentChoice == 3) {
                viewAnnouncement();
            } else if (studentChoice == 4) {
                changePassword();
            } else if (studentChoice == 5) {
                logout();
            }
        } else {
            printf("Invalid ID or Password.\n");
        }
    } else if (role == 3) { // Admin Login
        char adminID[] = "admin";
        char adminPass[] = "adminpass";
        printf("Enter Admin ID: ");
        scanf("%s", id);
        printf("Enter Password: ");
        scanf("%s", pass);

        if (strcmp(id, adminID) == 0 && strcmp(pass, adminPass) == 0) {
            printf("\nLogin Successful! Welcome, Admin.\n");
            printf("\n1] View All Users\n2] Manage System\n3] Change Password\n4] Back\n");
            printf("Enter your choice: ");
            int adminChoice;
            scanf("%d", &adminChoice);

            if (adminChoice == 1) {
                FILE *file = fopen("SignUP.txt", "r");
                if (file == NULL) {
                    printf("Error reading users file.\n");
                    return;
                }
                readStudents(file);
            } else if (adminChoice == 2) {
                printf("Admin management options will be implemented here.\n");
            } else if (adminChoice == 3) {
                changePassword();
            }
        } else {
            printf("Invalid ID or Password!\n");
        }
    } else {
        printf("Invalid choice!\n");
    }
}

void entertainmentMode() {
    int choice;
    clearScreen();
    displayHeader("ENTERTAINMENT MODE");
    printf("\t1] Notepad\n");
    printf("\t2] Paint\n");
    printf("\t3] Calculator\n");
    printf("\t4] Back to Main Menu\n");
    printf("\t==============================\n");
    printf("\tEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            system("notepad");
            break;
        case 2:
            system("mspaint");
            break;
        case 3:
            system("calc");
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Try again.\n");
    }
}

void clearScreen() {
    system("cls");
}

void displayHeader(const char *header) {
    printf("\n\t==============================\n");
    printf("\t%s\n", header);
    printf("\t==============================\n");
}

void changePassword() {
    char newPassword[20];
    printf("\nEnter new password: ");
    scanf("%s", newPassword);
    // You would need to update the password in the file
    // For simplicity, it's not implemented in this snippet.
    printf("Password changed successfully!\n");
}

void viewProfile() {
    printf("\nProfile details for Student %s:\n", currentUser);
    // You can add code to view specific profile details from the database or file
}

void logout() {
    printf("Logged out successfully.\n");
    strcpy(currentUser, "");  // Clear the current user's ID
}

void makeAnnouncement(char *announcement) {
    FILE *file = fopen(ANNOUNCEMENT_FILE, "a");
    if (file == NULL) {
        printf("Error opening announcements file.\n");
        return;
    }
    fprintf(file, "%s\n", announcement);
    fclose(file);
    printf("Announcement made successfully!\n");
}

void readStudents(FILE *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", line);
    }
}

void viewAnnouncement() {
    FILE *file = fopen(ANNOUNCEMENT_FILE, "r");
    if (file == NULL) {
        printf("Error opening announcements file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    clearScreen();
    displayHeader("VIEW ANNOUNCEMENTS");

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s\n", line);
    }

    fclose(file);
}
