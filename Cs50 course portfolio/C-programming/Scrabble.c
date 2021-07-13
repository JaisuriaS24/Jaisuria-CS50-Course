#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // This calculates the Score for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner as a result
    if (score1 > score2)
    {
        printf("Player 1 wins\n"); //for Player 1 
    }    
    else if (score2 > score1)   
    {
        printf("Player 2 wins\n"); //for Player 2
    }    
    else
    {
        printf("Tie\n"); //if both answers are similar, it will result in a "TIE"
    }    
}
int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum_points = 0;
    for (int i = 0, x = strlen(word); i < x; i++) //
    {
        if (isupper(word[i]))
        {
            sum_points += POINTS[word[i] - 65]; //65 is translated as "A"
        }
        else if (islower(word[i]))
        {
            sum_points += POINTS[word[i] - 97]; //97 is translated as "a"
        }
    }
    return sum_points;
    
}
