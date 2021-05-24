#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char A[9][11] = {"Paris", "Erlangen", "Nuernberg", "Bamberg", "Montenegro", "Muenchen", "Bayreuth", "Ingolstadt", "Ansbach"};

#define N 27
#define size 9
#define LENGTH 45

typedef struct node
{
    bool is_city;
    struct node *children[N];
}
node;

node *root;

int count = 0;

unsigned int counting(node *temp)
{
    //ToDo
    if (temp -> is_city == true)
    {
        count ++;
    }
    for (int i = 0; i < N; i++)
    {
        if (temp -> children[i] != NULL)
        {
            counting(temp -> children [i]);
        }
    }
    return count;
}

bool check(const char *word)
{
    //ToDo
    node *current = root;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        int index = toupper(word[i]) - 'a';
        if (word[i] != '\0')
        {
            if (current -> children[index] == NULL)
            {
                return false;
            }
            current = current -> children[index];
        }
    }
    if (current -> is_city == true)
    {
        return true;
    }
    return false;
}

void unload(node *temp)
{
    //ToDo
    for(int i = 0; i < N; i++)
    {
        if (temp -> children[i] != NULL)
        {
            unload(temp -> children[i]);
        }
    }
    free(temp);
}

int main(void)
{
    //char *cities = "Test.txt";
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root->is_city = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }
    //printf("1st");

    FILE *file = fopen("cities.txt", "r");
    //printf("2nd");
    if (file == NULL)
    {
        //printf("sjkdn");
        unload(root);
       // printf("aaaaaa");
        return false;
    }
    //printf("before load");
    char word[LENGTH + 1];

    //ToDo
    // scanning the file cities.text looking for string until end of file is reachedand saving it      //to a buffer called word
    while(fscanf(file, "%s", word) != EOF)
    {
        //saving the length of word for iteration at later stages
        int length = strlen(word);
        //create a new node and point to the same place as root
        node *current = root;
        //iterate through the buffer word
        for (int i = 0; i < length; i++)
        {
            // saving index whi is (word[i]) -'a'
            int index = toupper(word[i]) -'A';
            // if the children[index] of the current node is null, creating a new node and call it             //temp. access the children[index] of current and pont it to temp. Later make sure                 //that current point toward the temp
            if (current -> children[index] == NULL)
            {
                node *temp = malloc(sizeof(node));
                if (temp == NULL)
                {
                    return 1;
                }
                current -> children[index] = temp;
                current = temp;
            }
            else
            {
                current = current -> children[index];
            }
        }
        // at the end of file access the is_city of current and set it to true
        current -> is_city = true;
        //count ++;
    }
    //printf("after load");

    node *temp = root;
    printf("Cities in Trie: %i\n", counting(temp));
    for (int i = 0; i < size; i++)
    {
        if (check(A[i]) == false)
        {
            printf("%s is not in Trie\n", A[i]);
        }
    }
    temp = root;
    unload(temp);
    fclose(file);
    return 0;
}
