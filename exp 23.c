#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES 3
typedef struct {
    char name[20];
    char files[MAX_FILES][20];
    int fileCount;
} User;
typedef struct {
    User users[MAX_USERS];
    int userCount;
} DirectorySystem;
void createUser(DirectorySystem* directorySystem, const char* name) {
    if (directorySystem->userCount >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    User newUser;
    strcpy(newUser.name, name);
    newUser.fileCount = 0;
    directorySystem->users[directorySystem->userCount] = newUser;
    directorySystem->userCount++;
    printf("User '%s' created.\n", name);
}
void createFile(DirectorySystem* directorySystem, const char* username, const char* filename) {
    int userIndex = -1;
    for (int i = 0; i < directorySystem->userCount; i++) {
        if (strcmp(directorySystem->users[i].name, username) == 0) {
            userIndex = i;
            break;
        }
    }
    if (userIndex == -1) {
        printf("User '%s' does not exist.\n", username);
        return;
    }
    User* user = &directorySystem->users[userIndex];
    if (user->fileCount >= MAX_FILES) {
        printf("Maximum number of files reached for user '%s'.\n", username);
        return;
    }
    strcpy(user->files[user->fileCount], filename);
    user->fileCount++;
    printf("File '%s' created in user '%s' directory.\n", filename, username);
}
int main() {
    DirectorySystem directorySystem;
    directorySystem.userCount = 0;
    createUser(&directorySystem, "user1");
    createUser(&directorySystem, "user2");
    createUser(&directorySystem, "user3");
    createFile(&directorySystem, "user1", "file1.txt");
    createFile(&directorySystem, "user1", "file2.txt");
    createFile(&directorySystem, "user1", "file3.txt");
    createFile(&directorySystem, "user2", "file4.txt");
    createFile(&directorySystem, "user2", "file5.txt");
    createFile(&directorySystem, "user3", "file6.txt");
    createFile(&directorySystem, "user3", "file7.txt");
    return 0;
}
