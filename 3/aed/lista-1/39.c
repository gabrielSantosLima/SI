#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10
#define USERNAME_SIZE 200

typedef struct USER
{
    char name[USERNAME_SIZE];
    char dateLogin[10];
    char timeLogin[5];
    char timeLogout[5];
} USER;

typedef struct USERS
{
    int length;
    USER users[MAX_SIZE];
} USERS;

USERS *createList()
{
    USERS *newUsers = (USERS *)malloc(sizeof(USERS));
    newUsers->length = 0;
    return newUsers;
}

USER *createUser(char *name, char *dateLogin, char *timeLogin, char *timeLogout)
{
    USER *newUser = (USER *)malloc(sizeof(USER));
    strcpy(newUser->name, name);
    strcpy(newUser->dateLogin, dateLogin);
    strcpy(newUser->timeLogin, timeLogin);
    strcpy(newUser->timeLogout, timeLogout);
    return newUser;
}

void add(USERS *users, char *name, char *dateLogin, char *timeLogin, char *timeLogout)
{
    USER *newUser = createUser(name, dateLogin, timeLogin, timeLogout);
    if (users->length != MAX_SIZE)
    {
        users->users[users->length] = *newUser;
        users->length++;
        return;
    }
    printf("Lista Cheia");
}

void printAll(USERS users)
{
    printf("\n========== LISTA ==========\n");
    if (users.length == 0)
    {
        printf("Lista Vazia");
        return;
    }
    int currentIndex = 0;
    for (currentIndex = 0; currentIndex < users.length; currentIndex++)
    {
        printf("Nome: %s\n", users.users[currentIndex].name);
        printf("Data do Login: %s\n", users.users[currentIndex].dateLogin);
        printf("Hora do Login: %s\n", users.users[currentIndex].timeLogin);
        printf("Hora do Logout: %s\n", users.users[currentIndex].timeLogout);
        printf("=============================\n");
    }
}

void readFromFile(USERS *users, char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir arquivo.");
        return;
    }
    char content;
    while (content != EOF)
    {
        char name[USERNAME_SIZE] = "";
        char dateLogin[10] = "";
        char timeLogin[5] = "";
        char timeLogout[5] = "";

        while (content != '\n')
        {
            strncat(name, &content, 1);
            content = fgetc(file);
        }
        content = fgetc(file);
        while (content != '\n')
        {
            strncat(dateLogin, &content, 1);
            content = fgetc(file);
        }
        content = fgetc(file);
        while (content != '\n')
        {
            strncat(timeLogin, &content, 1);
            content = fgetc(file);
        }
        content = fgetc(file);
        printf("%c", content);
        while (content != '\n')
        {
            strncat(timeLogout, &content, 1);
            content = fgetc(file);
        }
        content = fgetc(file);
        add(users, name, dateLogin, timeLogin, timeLogout);
    }
    fclose(file);
}

int main()
{
    USERS *users = createList();
    readFromFile(users, "C:\\Users\\Gabriel\\users.txt");
    printAll(*users);
    return 0;
}