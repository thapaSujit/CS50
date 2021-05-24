#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    char* payload;
    struct node *next;
}
node;

node *hashtable[10];
int hash(char *name)
{
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        sum = sum + name[i];
    }
    return sum % 10;
    //ToDo Hash function
    //return integer;
}

bool search(char*to_search, node *hash_table[])
{
    node *temp = hash_table[hash(to_search)];
    while (temp != NULL)
    {
        if (strcmp(temp -> payload, to_search) == 0)
        {
            return true;
        }
        temp = temp -> next;
    }
    return false;

    //ToDo
    //return true or false;
}

void unload_ht(node *head)
{
    while (head != NULL)
    {
        node *temp = head -> next;
        free(head);
        head = temp;
    }
    //ToDo
}

int main(void)
{
    char *A[6] = {"Harth", "Max", "Sebastian", "Johannes", "Matzner", "Chris"};
    int i;
    for (i = 0; i < 10; i++)
    {
        hashtable[i] = NULL;
    }

    //ToDo Load the Hashtable
    for (int j = 0; j < 6; j++)
    {
        int hash_index = hash(A[j]);
        node *temp = malloc(sizeof(node));
        temp -> payload = A[j];
        if (hashtable[hash_index] == NULL)
        {
            temp -> next = NULL;
            hashtable[hash_index] = temp;
        }
        else
        {
            temp -> next = hashtable[hash_index];
            hashtable[hash_index] = temp;
        }
    }

    char *to_search[2] = {"Chris", "Tobias"};
    for (i = 0; i < 2; i++)
    {
        if(search(to_search[i], hashtable) == true)
        {
            printf("%s exists\n", to_search[i]);
        } else{
            printf("%s does not exist\n", to_search[i]);
        }
    }

    for (i = 0; i < 10; i++)
    {
        unload_ht(hashtable[i]);
    }
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    char* payload;
    struct node *next;
}
node;

node *hashtable[10];
int hash(char *name)
{
    int sum = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        sum = sum + name[i];
    }
    return sum % 10;
    //ToDo Hash function
    //return integer;
}

bool search(char*to_search, node *hash_table[])
{
    node *temp = hash_table[hash(to_search)];
    while (temp != NULL)
    {
        if (strcmp(temp -> payload, to_search) == 0)
        {
            return true;
        }
        temp = temp -> next;
    }
    return false;
    //ToDo
    //return true or false;
}

void unload_ht(node *head)
{
    while (head != NULL)
    {
        node *temp = head -> next;
        free(head);
        head = temp;
    }
    //ToDo
}

int main(void)
{
    char *A[6] = {"Harth", "Max", "Sebastian", "Johannes", "Matzner", "Chris"};
    int i;
    for (i = 0; i < 10; i++)
    {
        hashtable[i] = NULL;
    }
    //ToDo Load the Hashtable at the end
    for (int j = 0; j < 6; j++)
    {
        int hash_index = hash(A[j]);
        node * temp = NULL;
        node *newnode = malloc(sizeof(node));
        newnode -> payload = A[j];

        if (hashtable[hash_index] == NULL)
        {
            newnode -> next = NULL;
            hashtable[hash_index] = newnode;
        }
        else
        {
            temp = hashtable[hash_index];
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newnode;
        }
    }
    char *to_search[2] = {"Chris", "Tobias"};
    for (i = 0; i < 2; i++)
    {
        if(search(to_search[i], hashtable) == true)
        {
            printf("%s exists\n", to_search[i]);
        } else{
            printf("%s does not exist\n", to_search[i]);
        }
    }
    for (i = 0; i < 10; i++)
    {
        unload_ht(hashtable[i]);
    }
    return 0;
}

*/