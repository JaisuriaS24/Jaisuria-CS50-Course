
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    if (argc != 2) //this part checks whether the given integer is valid.
        // It also checks if it has only 2 arguments.
    
    {
        printf("Usage: ./caesar k");
        
        return 1;
    }
    
    for (int x = 0; x < strlen(argv[1]); x++)
    {
        if (isalpha(argv[1][x]))
        {
            printf("Usage: ./caesar key\n");
           
            return 1;
        }
    }
    
    int x = atoi(argv[1]) % 26; // the atoi value is used here because it helps with changing the string value to an integer in argv
    
    string plaintext = get_string("plaintext: "); //selects the plaintext
    
    printf("ciphertext: "); //prints out ciphertext
    
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }
        
        int ascii_offset = isupper(plaintext[i]) ? 65 : 97;
        
        int pi = plaintext[i] - ascii_offset;
        
        int ci = (pi + x) % 26;
        
        printf("%c", ci + ascii_offset);
    }
    
    printf("\n");
    return 0;
}