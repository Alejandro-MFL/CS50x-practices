// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

void freeNodes(node *current);
int addNodes(node **origen, char *newWord);
// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26 + 1;

// Hash table. We make a 1D table of the 26 square to encode the first two letters of the word,
// "+1" is for when the word does not have a second letter
node *table[N];
unsigned int wordCount;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    for (node *n = table[index]; n != NULL; n = n->next)
    {
        if ((strcasecmp(n->word, word)) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    if (word == NULL || word[0] == '\0')
    {
        // return error
        return 677;
    }
    char c1 = word[0];
    char c2;
    if (word[1] == '\0')
    {
        return 676;
    }
    else if (word[1] == '\'')
    {
        c2 = word[2];
    }
    else
    {
        c2 = word[1];
    }
    unsigned int hash = (toupper(c1) - 'A') * 26 + (toupper(c2) - 'A');
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
// Open the file, copy each word, assign it an index and add it as a new node, when finished close
// the file
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        int index = hash(word);
        if (index > 676)
        {
            return false;
        }
        int CheckAdd = addNodes(&table[index], word);
        if (CheckAdd == 1)
        {
            return false;
        }
        else
        {
            wordCount++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            freeNodes(table[i]);
        }
    }
    return true;
}
// Separates the function of adding new nodes
int addNodes(node **origen, char *newWord)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    strcpy(n->word, newWord);
    n->next = *origen;
    *origen = n;
    return 0;
}
// Use a recursive function to remove all nodes from the last node in the list to the first node.
void freeNodes(node *current)
{
    if (current->next != NULL)
    {
        freeNodes(current->next);
    }
    free(current);
}
