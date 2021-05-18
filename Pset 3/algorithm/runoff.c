#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
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
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
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

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    //iterating over each candidate and if candidates[i].name = name of the candodate, then recording the preferences of each voter. if the name is found, then
    //updating the preferences and returning true. However if the name is not not found, we will not update the preferences and will reurn false.

    //initilly declaring a boolean variable found to false and if the name is found then assigning true to the variable found nd returning 0.
    bool found = false;
    for (int i = 0; i < candidate_count; i++)
    {
        {
            if (strcmp(candidates[i].name, name) == 0)
            {
                preferences[voter][rank] = i;
                found  = true;
            }
        }
    }
    return found;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //using nested loops at first iterating over voter_count at outer loop and candidate count at inner loop. Using if condition, if candidate is not eliminated
    // we will update the vote count


    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // declarig the variable jth_preference_voter_i which stores the jth preference for voter i
            int jth_preference_voter_i = preferences[i][j];
            if (!candidates[jth_preference_voter_i].eliminated)
            {
                candidates[jth_preference_voter_i].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    //looking over candidates and if candidates[i].votes > majourity, then returning true and printing the name of the winner. else returning false

    //declaring two variables => majourity which stores the majourity of votes required to win the election which is = voter_count / 2, another variable is
    //string which stores the name of the cndidates
    int majourity = voter_count / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        string winner = candidates[i].name;
        if (candidates[i].votes > majourity)
        {
            printf("%s\n", winner);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    //looking over candidates and declaring mimimum_votes variable. if candidates is not eliminated and candidates[i].votes < miinimum_votes, then updating
    //the minimum votes equal to candidates[i].votes.
    int minimum_votes = 100;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < minimum_votes)
        {
            minimum_votes = candidates[i].votes;
        }
    }

    //If after iterating over candidates, still minimum votes = 100, then returning 0, else returning minimum votes.
    if (minimum_votes == 100)
    {
        return 0;
    }
    else
    {
        return minimum_votes;
    }
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    //Iterating over cndidates and if candidate is not eliminated and the votes of candidate[i] != min, then returning false, else returnng true meaning the are
    //several candidates who has the same number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // iterating over the candidate count and if the votes count of ith candidate is less than or equal to min, returning true meaning that candidate is eliinated
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i]. votes <= min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
