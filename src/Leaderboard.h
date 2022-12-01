#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

class Leaderboard
{
private:
    // each player is represented by a string (name) and map of values (clears, likes, etc)
    unordered_map<string, unordered_map<string, int>> unsortedPlayers;

public:
    Leaderboard();
    vector<pair<string, int>> mergeSort(string option);
    vector<pair<string, int>> radixSort(string option);
    unordered_map<string, int> search(string name);
};
