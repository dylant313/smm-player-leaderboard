#include "Leaderboard.h"

// import data into map
Leaderboard::Leaderboard()
{
    string line;

    // read in likes for all players
    ifstream file1("../data/likes.csv");
    getline(file1, line);
    while (getline(file1, line, '\t'))
    {
        getline(file1, line, '\t');
        getline(file1, line);
        unsortedPlayers[line]["likes"]++;
    }

    // read in clears for all players
    ifstream file2("../data/clears.csv");
    getline(file2, line);
    while (getline(file2, line, '\t'))
    {
        getline(file2, line, '\t');
        getline(file2, line);
        unsortedPlayers[line]["clears"]++;
    }
}

// return sorted vector
vector<unordered_map<string, int>> Leaderboard::mergeSort(int option)
{
}

// return sorted vector
vector<unordered_map<string, int>> Leaderboard::radixSort(int option)
{
}

// search using unordered map, return map representing player
unordered_map<string, int> Leaderboard::search(string name)
{
}