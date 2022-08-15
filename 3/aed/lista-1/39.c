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
    fgets(name, USERNAME_SIZE, file);

    fgets(dateLogin, 10, file);
    printf("Nome*: %s\n", name);
    printf("Data*: %s\n", dateLogin);

    while (fscanf(file, "%s", lines) == 1)
    {
        if (line % 4 == 0)
        {
            strcpy(name, lines);
            printf("Nome: %s\n", name);
        }
        else if (line % 4 == 1)
        {
            strcpy(dateLogin, lines);
            printf("Data: %s\n", dateLogin);
        }
        else if (line % 4 == 2)
        {
            strcpy(timeLogin, lines);
            printf("Hora Login: %s\n", timeLogin);
        }
        else if (line % 4 == 3)
        {
            strcpy(timeLogout, lines);
            printf("Nome: %s\n", name);
            printf("Hora Logout: %s\n", timeLogout);
            add(users, name, dateLogin, timeLogin, timeLogout);
            printf("================================\n");
        }
        line++;
    }
    fclose(file);
}

int main()
{
    USERS *users = createList();
    readFromFile(users, (char *)"C:\\Users\\callidus\\users.txt");
    printAll(*users);
    return 0;
}