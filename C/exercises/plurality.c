#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    string name;
    int votes;
}
candidates;

bool vote(string name, int argc, candidates competitors[]);
void print_winner(candidates competitors[], int argc);

int main(int argc, string argv[])
{
    candidates competitors[argc - 1];

    if(argc >= 2)
    {
        for(int i = 1; i < argc; i++)
        {
            competitors[i - 1].name = argv[i];
            competitors[i - 1].votes = 0;
        }

        int numberOfVotos = get_int("Number of votos: ");

        for(int j = 0; j < numberOfVotos; j++)
        {
            string whoYouWannaVote = get_string("Vote: ");
            bool findCandidate = vote(whoYouWannaVote, argc, competitors);
        }

        print_winner(competitors, argc);

        return 0;
    }
    else
    {
        return 1;
    }
}

bool vote(string name, int argc, candidates competitors[])
{
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(competitors[i - 1].name, name) == 0)
        {
            competitors[i - 1].votes++;
            return true;
        }
    }
    printf("Candidate doesn't exist");
    return false;
}

void print_winner(candidates competitors[], int argc)
{
    int biggestVote = 0;

    for(int i = 1; i < argc; i++)
    {
        if(competitors[i - 1].votes > biggestVote)
        {
            biggestVote = competitors[i - 1].votes;
        }
    }
    
    for(int j = 1; j < argc; j++)
    {
        if(competitors[j - 1].votes == biggestVote)
        {
            printf("Winner: %s\n", competitors[j - 1].name);
        }
    }
}