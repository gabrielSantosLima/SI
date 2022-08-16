#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10
#define FIELD_SIZE 40

typedef struct USER
{
    char name[FIELD_SIZE];
    char dateLogin[FIELD_SIZE];
    char timeLogin[FIELD_SIZE];
    char timeLogout[FIELD_SIZE];
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

USER createUser(char name[], char dateLogin[], char timeLogin[], char timeLogout[])
{
    USER newUser;
    strcpy(newUser.name, name);
    strcpy(newUser.dateLogin, dateLogin);
    strcpy(newUser.timeLogin, timeLogin);
    strcpy(newUser.timeLogout, timeLogout);
    return newUser;
}

void add(USERS *users, char name[], char dateLogin[], char timeLogin[], char timeLogout[])
{
    USER newUser = createUser(name, dateLogin, timeLogin, timeLogout);
    if (users->length != MAX_SIZE)
    {
        users->users[users->length] = newUser;
        users->length++;
        return;
    }
    printf("Lista Cheia");
}

void printAll(USERS users)
{
    printf("========== LISTA ==========\n");
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
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    char *lines;
    char name[FIELD_SIZE];
    char dateLogin[FIELD_SIZE];
    char timeLogin[FIELD_SIZE];
    char timeLogout[FIELD_SIZE];

    while (lines != NULL)
    {
        lines = fgets(name, sizeof(name), file);
        if (lines == NULL)
            break;
        lines = fgets(dateLogin, sizeof(dateLogin), file);
        lines = fgets(timeLogin, sizeof(timeLogin), file);
        lines = fgets(timeLogout, sizeof(timeLogout), file);
        strtok(name, "\n");
        strtok(dateLogin, "\n");
        strtok(timeLogin, "\n");
        strtok(timeLogout, "\n");
        add(users, name, dateLogin, timeLogin, timeLogout);
    }
    fclose(file);
}

int main()
{
    USERS *users = createList();
    readFromFile(users, (char *)"C:\\Users\\Gabriel\\users.txt");
    printAll(*users);
    return 0;
}