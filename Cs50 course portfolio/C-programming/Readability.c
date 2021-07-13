#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void) 
{
    string text = get_string("Text: ");
    printf("%s\n", text);
    
    int lettersCount = 0; //this is the letters count
    int wordsCount = 1; // this is the words count
    int sentencesCount = 0; // this is the sentences count
    
    for (int i = 0; i < strlen(text); i++) //counts for each
    {    
        
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            lettersCount++;
        }
        else if (text[i] == ' ')
        {
            wordsCount++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencesCount++; //this part executes the statement
        }
    }
    
    float grade = round(0.0588 * (100 * (float) lettersCount / (float) wordsCount) - 0.296 * (100 * (float) sentencesCount /
                        (float) wordsCount) - 15.8);
    if (grade < 1)

    {
        printf("Before Grade 1\n"); // this parts takes the intput value
    } 
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }    
    else
    {
        printf("Grade %.f\n", grade);
    }
}
