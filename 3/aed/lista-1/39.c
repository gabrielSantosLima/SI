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

void copyLine(char *destine, char *source, int size)
{
    int length = strlen(source);
    int index;
    for (index = 0; index < length; index++)
    {
        *(destine + index) = *(source + index);
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
    char lines[200];
    char name[USERNAME_SIZE];
    char dateLogin[10];
    char timeLogin[5];
    char timeLogout[5];

    int line = 0;
    while (fscanf(file, "%s", lines) == 1)
    {
        printf("Current Index: %d\n", line);
        if (line % 4 == 0)
        {
            copyLine(name, lines, USERNAME_SIZE);
            printf("Nome: %s\n", name);
        }
        else if (line % 4 == 1)
        {
            copyLine(dateLogin, lines, 10);
            printf("Data: %s\n", dateLogin);
        }
        else if (line % 4 == 2)
        {
            copyLine(timeLogin, lines, 5);
            printf("Hora Login: %s\n", timeLogin);
        }
        else if (line % 4 == 3)
        {
            copyLine(timeLogout, lines, 5);
            printf("Hora Logout: %s\n", timeLogout);
            printf("================================\n");
            // memset(name, 0, sizeof(name));
            // memset(dateLogin, 0, sizeof(dateLogin));
            // memset(timeLogin, 0, sizeof(timeLogin));
            // memset(timeLogout, 0, sizeof(timeLogout));
            // add(users, name, dateLogin, timeLogin, timeLogout);
        }
        line++;
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