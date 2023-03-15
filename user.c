#include "DBheader.h"

// void generateNewList()
// {
//     head = NULL;
// }

AdminUser_t *EnterUser(AdminUser_t **head, char name[], char password[])
{
    // setting up dynamic allocation
    AdminUser_t *newNode = (AdminUser_t *)malloc(sizeof(AdminUser_t));

    strcpy(newNode->name, name); // alloc the data dinamically here..
    strcpy(newNode->password, password);
    newNode->next = NULL; // consider next as the last of the list

    if (&(*head) == NULL) // inicio sendo declarado nulo fica igual ao valor do
                          // ponteiro no incicio que e nulo
    {
        *head = newNode; // ponteiro e anulado para nao limpar a memoria
    }
    else // esta caso ira fazer com que a posiçao de proximo(prox) retorne a
         // 0. Importante para o apontador nao anular os valores guardados
    {
        newNode->next = *head; // considerar prox, do atual como nulo
        *head = newNode;       // inicio de lista nulo
    }

    // Missing to file implementation.

    return newNode;

    // colocar função criar nova lista se for vazio??(ver codigo do trabalho do 1ºano, no replit)
}

/// @brief
/// @param head
/// @param name
/// @param password

void ConfirmLogIN(AdminUser_t *head, char name[], char password[])
{
    // dinamic allocation:experimental
    // AdminUser_t *temp = (AdminUser_t *)malloc(sizeof(AdminUser_t)); // setting up the allocation member pointer which will contain the data of the struct

    AdminUser_t *temp = head;

    if (strcmp(temp->name, name) == 0) // checking our respectfull user
    {
        if (strcmp(temp->password, password) == 0) // checking our respectfull password
        {
            printf("\nUser verification: 'experimental'\n");
            printf("\nWelcome dear User:as menber:%s,as local:%s", name, temp->name);
        }
        else
            printf("\nWrong Password");
    }
    else
        printf("\nWrong UserName");
}

void printList(AdminUser_t *head)
{
    AdminUser_t *temporary = head;
    if (head == NULL) // se lista for vazio
    {
        printf("\nNão Achou!!");
        return;
    }
    else
    {
        while (temporary != NULL) // enquanto não terminar a nossa lista..
        {
            printf("printing name: %s", temporary->name); // excrever por nome na consola
            printf("\n----------x------------\n");
            // getchar();
            temporary = temporary->next; // avança nodo seguinte
        }
    }
}

// insert data from linked list to a file

void serialize(AdminUser_t *head) // no need to create as **head since we are not changing
                                  // data from linked list, and we only need to serialize data to a file
{
    FILE *fp = fopen("list.txt", "w");
    if (fp == NULL)
    {
        printf("error opening file");
        // exit(1);
        return;
    }
    AdminUser_t *temp = head;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        fprintf(fp, "%s", temp->name);
    }
    fclose(fp);
}

void FreeMem(AdminUser_t **head)
{
    printf("\nFunção Liberar, a executar..");
    AdminUser_t *newNode = *head;
    AdminUser_t *temp;
    while (newNode != NULL)
    {
        // temp = newNode;
        temp = newNode->next;
        newNode = temp;
        free(newNode);
    }
}