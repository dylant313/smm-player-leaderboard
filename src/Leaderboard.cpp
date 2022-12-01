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

// given choice of attribute, return sorted vector of name/attribute pairs
vector<pair<string, int>> Leaderboard::mergeSort(string option)
{
}

// given choice of attribute, return sorted vector of name/attribute pairs
vector<pair<string, int>> Leaderboard::radixSort(string option)
{
}

// search using unordered map, return map representing player
unordered_map<string, int> Leaderboard::search(string name)
{
}