
// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include <cs50.h>

#include "dictionary.h"

typedef struct node //This part defines struct for a node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int SIZE = 65536; 

node *table[SIZE];
bool check(const char *word)
{
    int index = hash(word);
    node *cursor = table[index];
    
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp-> word, word) == 0)
        {
            return true;
        }
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hashvalue = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashvalue += tolower(word[i]);
        
        hashvalue = (hashvalue * tolower(word[i])) % SIZE;
    }
    return hashvalue;
}

int counter = 0; //

bool load(const char *dictionary) //This part is commanded to load the dictionary file into memory
{

    // this part is commanded to open the dictionary file.
    FILE *file = fopen(dictionary, "r"); //This part is commanded to open the dictionary filestyle50 dictionary.c
    if (file == NULL)
    {
        fprintf(stderr, "There has been an error");
        
        return false;
    }

    char wordlist[LENGTH + 1]; //This part is commanded to scan the word from the dictionary file.
    
    while (fscanf(file, "%s", wordlist) != EOF)
    {
        counter++;
        node *newNode = malloc(sizeof(node));
        
        if (newNode == NULL)
        {
            return 1;
        }
        strcpy(newNode->word, wordlist);
        
        newNode->next = NULL;
        
        int index = hash(wordlist);
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }
    fclose(file);
    return true;
}


unsigned int size(void)
{
    return counter;
}
bool unload(void) //This part is commanded to unload the dictionary file from the memory file
{
    node *temp = NULL;
    
    node *cursor = NULL;
    for (int i = 0; i < SIZE; i++)
    {
        cursor = table[i];
        
        while (cursor != NULL)
        {
            temp = cursor;
            
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
