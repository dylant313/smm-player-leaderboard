#include "Leaderboard.h"

// import data into map
Leaderboard::Leaderboard()
{
    string line;
    cout << "Importing data... (0/4)" << endl;

    // read in plays for all players
    ifstream file1("../data/plays.csv");
    getline(file1, line);
    while (getline(file1, line, '\t'))
    {
        getline(file1, line, '\t');
        getline(file1, line);
        unsortedPlayers[line]["plays"]++;
    }
    cout << "Importing data... (1/4)" << endl;

    // read in clears for all players
    ifstream file2("../data/clears.csv");
    getline(file2, line);
    while (getline(file2, line, '\t'))
    {
        getline(file2, line, '\t');
        getline(file2, line);
        unsortedPlayers[line]["clears"]++;
    }
    cout << "Importing data... (2/4)" << endl;

    // read in likes for all players
    ifstream file3("../data/likes.csv");
    getline(file3, line);
    while (getline(file3, line, '\t'))
    {
        getline(file3, line, '\t');
        getline(file3, line);
        unsortedPlayers[line]["likes"]++;
    }
    cout << "Importing data... (3/4)" << endl;

    // read in records for all players
    ifstream file4("../data/records.csv");
    getline(file4, line);
    while (getline(file4, line, '\t'))
    {
        getline(file4, line, '\t');
        getline(file4, line, '\t');
        unsortedPlayers[line]["records"]++;
        getline(file4, line);
    }
    cout << "Importing data... (4/4)" << endl;
    cout << "Data imported successfully!" << endl;
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