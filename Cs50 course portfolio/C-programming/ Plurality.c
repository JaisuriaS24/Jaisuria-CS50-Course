#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 // This part defines the maximum number of candidates

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX]; //This code represents the array of all the candidates

int candidate_count; //This part defines the number of candidates in the election. 

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candiates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++) //This part creates a loop over the voters in the election. 
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n"); //This part helps with checking for an invalid vote. 
        }
    }


    print_winner(); //This part represents the result of the election - it will show the winner.
}

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return 1;
        }    
    }
    
    return false;
}

void print_winner(void)
{
    int maxVote = 0;
    
    for (int k = 0; k < candidate_count; k++) //this part helps with finding the highest number of votes in the election.
    {
        if (maxVote < candidates[k].votes)
        {
            maxVote = candidates[k].votes;
        }
    }
    
    for (int k = 0; k < candidate_count; k++) 
        //This part will print the all the candiates who won or recieved more votes in the election.
    
    {
        if (candidates[k].votes == maxVote)
        
        {
            printf("%s\n", candidates[k].name);
        }
    }
}
