#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 9 //This part defines the the maximum number of candidates in the election
#define MAX_VOTERS 100 // This part defines the maximum number of voters in the election


int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    bool eliminated;
    int votes;
}
//All candidates in the election are programmed to have a name, status for elimination, and a vote count.

candidate;
candidate candidates[MAX_CANDIDATES];

/////////////////////////////////////

int candidate_count;
int voter_count;

void eliminate(int min);
bool is_tie(int min);

void tabulate(void);
bool vote(int voter, int rank, string name);

bool print_winner(void);
int find_min(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];

        candidates[i].eliminated = false;
        
        candidates[i].votes = 0;
        
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            if (!vote(i, j, name))
                // This is programmed to record the vote if it's valid, and stop recording when it is invalid.
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    while (true) //This part helps with keeping the runoff functioning correctly until the winner is displayed.
    {
        bool won = print_winner();
        tabulate(); //This calculates the number of votes for the candidates that are remaining.
        
        if (won)
        {
            break;
        }
        
        int min = find_min(); //This will eliminate all the candidates who have lost or have been placed in last during the election.
        
        bool tie = is_tie(min); //If all candidates are in a tie during the election, all of them will win.

        if (tie) 
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);
        //This is used to eliminate the candidates with a minimum vote in the election.

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}
//////////////////////////////////

bool vote(int voter, int rank, string name)
// This part is used select a certain preference if the vote is a valid one. 

{


    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }

    }
    return false;
}
//////////////////////////////

void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }

    }

    return;
}
///////////////////////////////

bool print_winner(void)



{
    float winningcount = (voter_count / 2);
    

    for (int i = 0; i < candidate_count;  i++)
    
    
    {
        if (candidates[i].votes > winningcount)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}
//////////////////////////

int find_min(void)
{
    int min;
    for (int i = 0; i < candidate_count; i++)
    {
        if ((candidates[i].eliminated == false) && candidates[i].votes < min)
        
        {
            min = candidates[i].votes;
        }
    }
// This is used to return the number of minimum votes for the candidates that are remaining.

    return min;
}
bool is_tie(int min)


{
    int counter = 0;
    int notelm = 0;
    bool istie;
    
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            notelm++;
        }
        if (min == candidates[i].votes)
        {
            counter++;
        }
        if (counter == notelm)
        {
            istie = true;
        } 
        else 
        {
            istie = false;
        }

    }
    return istie;
}

////////////////////////////

//This part helps with eliminating the candidates with the lowest votes.
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++) 
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
