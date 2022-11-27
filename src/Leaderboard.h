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
    unordered_map<string, vector<string>> unsortedPlayers;

public:
    Leaderboard();
    vector<vector<string>> mergeSort(int option);
    vector<vector<string>> radixSort(int option);
    vector<string> search(string name);
};
