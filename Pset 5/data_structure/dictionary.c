// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1]; //--> this is for hash table so we dnt need to decclare in check function as it involved hash table word
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//declaring word and hash_index
int total_word = 0;
int hash_index;

// Returns true if word is in dictionary else false --> // case insensitive
bool check(const char *word)
{
    //Hash the word to obtain the hash value
    hash_index = hash(word);

    //access linked list at that index in the hash table -->node *traverse = table[hash_index];
    //traverse lnked list looking for a word (strcasecmp)
    //-> start with curser set to first item in the linked list-->keep moving curser until you get NULL, checking each node for the word
    for (node *traverse = table[hash_index];  traverse != NULL; traverse = traverse -> next)  //can be done like this -->   //node *traverse = table[hash_index]; ->//while (traverse != NULL)// -> traverse = traverse->next;
    {
        if (strcasecmp(traverse -> word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
// using http://www.cse.yorku.ca/~oz/hash.html as a reference for a new hash function (this algorithm (k=33) was first reported by dan bernstein many
//years ago in comp.lang.c. another version of this algorithm (now favored by bernstein) uses xor: hash(i) = hash(i - 1) * 33 ^ str[i]; the magic of
//number 33 (why it works better than many other constants, prime or not) has never been adequately explained.)
    //unsigned long
    //hash(unsigned char *str)
    //{
      //  unsigned long hash = 5381;
        //int c;
        //while (c = *str++)
          //  hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        //return hash;
    //}
    //hash << 5 means the hash is moved left (in terms of binary) by 5 bits
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    node *list = NULL; // list is a pointer a node like a pointer to a int

    //Open  dictionary file --> use fopen --> remember to check of return value is null
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1]; //-->word is a buffer here whicha data buffer (or just buffer) is a region of a physical memory storage used to temporarily store data while it is being moved from one place to another.--? this is for dictionary not declared in global variable. used in when opening files or working with files

    //int total_word = 0;
    //read strings from file one at atime-->fscanf(file, "s", word) -->repeat this process agin and again nd again ==>fscanof willreturn EOF once it reaches the end of file
    //defining the variable word
    while (fscanf(dictionary_file, "%s", word) != EOF)
    {

        //create a new nord for each word-->use malloc-->remember to check if return value is null-->copy word into node using strcpy
        node *new_node = malloc(sizeof(node)); //// gives enough memory for the node and store that memory address in a variable called new_node
        if (new_node == NULL)//safety check if anything go wrong return 1
        {
            return false;
        }
        strcpy(new_node -> word, word);

        //Hash word to obtain a hash value
        hash_index = hash(word);

        //insert node into hash table at that location--> recall that hash table is an array of linked list->be sure to set pointers in correct orders
        //selecting the new_node and setting its next pointer to be the first element in the link list then resetting first element in the link to be the new_node just created
        new_node -> next = table[hash_index];
        table[hash_index] = new_node;
        total_word++;


    }
    fclose(dictionary_file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return total_word;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // inerating over the buckets
    for (int i = 0; i < N; i++)
    {
        //setting currser to the ith element in the hash table
        node *head = table[i];
        node *curser = head;

        //if curser is not null, free
        while (curser != NULL)
        {
            node *temp = curser;
            curser = curser -> next;
            free(temp);
            temp = curser;
        }
    }
    return true;
}
