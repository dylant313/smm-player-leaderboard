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
    cout << "Data imported successfully!" << endl
         << endl;
}

// calculate rankings using provided weights
void Leaderboard::calculateRankings(double playMult, double clearMult, double likeMult, double recordMult)
{
    for (auto &player : unsortedPlayers)
    {
        player.second["ranking"] = (player.second["plays"] * playMult) + (player.second["clears"] * clearMult) + (player.second["likes"] * likeMult) + (player.second["records"] * recordMult);
    }
}

// given choice of attribute, return sorted vector of name/attribute pairs
vector<pair<string, int>> Leaderboard::mergeSort(string option)
{
    vector<pair<string, int>> players;
    auto start = chrono::high_resolution_clock::now();

    for (auto &it : unsortedPlayers)
    {
        players.push_back(make_pair(it.first, it.second[option]));
    }

    int left = 0;
    int right = players.size() - 1;
    mergeSortHelper(players, left, right);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Merge Sort: completed in " << duration.count() << " ms" << endl;

    return players;
}

void Leaderboard::mergeSortHelper(vector<pair<string, int>> &temp, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortHelper(temp, left, mid);
        mergeSortHelper(temp, mid + 1, right);

        mergeHelper(temp, left, mid, right);
    }
}

void Leaderboard::mergeHelper(vector<pair<string, int>> &temp, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<string, int>> leftArray;
    vector<pair<string, int>> rightArray;

    for (int i = 0; i < n1; i++)
    {
        leftArray.push_back(temp.at(left + i));
    }

    for (int j = 0; j < n2; j++)
    {
        rightArray.push_back(temp.at(mid + 1 + j));
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftArray.at(i).second >= rightArray.at(j).second)
        {
            temp.at(k) = leftArray.at(i);
            i++;
        }
        else
        {
            temp.at(k) = rightArray.at(j);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        temp.at(k) = leftArray.at(i);
        i++;
        k++;
    }

    while (j < n2)
    {
        temp.at(k) = rightArray.at(j);
        j++;
        k++;
    }
}

// given choice of attribute, return sorted vector of name/attribute pairs
vector<pair<string, int>> Leaderboard::radixSort(string option)
{
    vector<pair<string, int>> players;

    for (auto &it : unsortedPlayers)
    {
        players.push_back(make_pair(it.first, it.second[option]));
    }

    return players;
}

// search using unordered map, return map representing player
unordered_map<string, int> Leaderboard::search(string name)
{
    if (unsortedPlayers.count(name) != 0)
    {
        return unsortedPlayers[name];
    }
    unordered_map<string, int> emptyMap;
    return emptyMap;
}
