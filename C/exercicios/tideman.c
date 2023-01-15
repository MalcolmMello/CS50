#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for(int k = 0; k < candidate_count; k++)
    {
        for(int l = k + 1; l < candidate_count; l++)
        {
            preferences[ranks[k]][ranks[l]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    while(pair_count < MAX * (MAX - 1) / 2)
    {
        for(int m = 0; m < candidate_count; m++)
        {
            for(int n = 0; n < candidate_count; n++)
            {
                if(preferences[m][n] > preferences[n][m])
                {
                    pairs[pair_count].winner = m;
                    pairs[pair_count].loser = n;
                    pair_count++;
                }
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int highest;

    int handle_winner;
    int handle_loser;
    int highest_index;

    for(int o = 0; o < pair_count; o++)
    {
        if(o == 0)
        {
            highest = pairs[0].winner - pairs[0].loser;
            highest_index = 0;
        }

        for(int p = o + 1; p < pair_count; p++)
        {
            int difference = pairs[p].winner - pairs[p].loser;

            if(difference > highest)
            {
                highest = difference;
                highest_index = p;
                handle_winner = pairs[p].winner;
                handle_loser = pairs[p].loser;
            }
        }


        pairs[highest_index] = pairs[o];

        pairs[o].winner = handle_winner;
        pairs[o].loser = handle_loser;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for(int q = 0; q < pair_count; q++)
    {
        if(q + 1 == pair_count)
        {
            int true_lenght = 0;

            for(int r = 0; r < candidate_count; r++)
            {
                if(locked[pairs[q].loser][r] == true)
                {
                    true_lenght++;
                }
            }

            if(true_lenght + 1 == candidate_count - 1)
            {
                locked[pairs[q].loser][pairs[q].winner] = true;
                locked[pairs[q].winner][pairs[q].loser] = false;
            }
        }
        else
        {
            locked[pairs[q].winner][pairs[q].loser] = true;
            locked[pairs[q].loser][pairs[q].winner] = false;
        }

    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    for(int s = 0; s < candidate_count; s++)
    {
        int candidate_wons = 0;

        for(int t = 0; t < candidate_count; t++)
        {
            if(locked[s][t] == true)
            {
                candidate_wons++;
            }
        }

        if(candidate_wons == candidate_count - 1)
        {
            printf("The winner is %s\n", candidates[s]);
            return;
        }
    }
    return;
}