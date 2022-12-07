#include "Leaderboard.cpp"

int main()
{
    Leaderboard board;

    // Prints out the main menu
    while (true)
    {

        cout << "\nWelcome to the Super Mario Maker Player leaderboards!" << endl;
        cout << "-----------------------------------------------------" << endl;

        // Takes in the choice of the user
        int choice;
        cout << "\nSelect an option:\n1 - Sort players\n2 - Search for a player\n3 - Exit" << endl;
        cin >> choice;

        // Determines if program will search players or sort them
        if (choice == 1)
        {
            while (true)
            {
                cout << "\nSort by which category?" << endl;
                cout << "1 - Number of plays\n2 - Number of clears" << endl;
                cout << "3 - Number of likes given\n4 - Number of world records" << endl;

                cin >> choice;
                if (choice > 4 || choice < 1)
                {
                    cout << "Unrecognized command. Please try again." << endl;
                }
                else
                {
                    break;
                    cout << endl;
                }
            }

            // Sort based on user's choice
            string choiceResult;
            switch (choice)
            {
            case 1:
                choiceResult = "plays";
                break;
            case 2:
                choiceResult = "clears";
                break;
            case 3:
                choiceResult = "likes";
                break;
            case 4:
                choiceResult = "records";
                break;
            }

            // Compare both sorts
            vector<pair<string, int>> players1 = board.mergeSort(choiceResult);
            vector<pair<string, int>> players2 = board.radixSort(choiceResult);

            // Display all users on current page
            int playerNumber;
            int pageNumber = 1;
            bool mergeSort = true;
            while (true)
            {
                // Display either merge or radix results
                playerNumber = (pageNumber - 1) * 10;
                cout << "\nPlayers with the most " << choiceResult;
                if (mergeSort)
                {
                    cout << " based on merge sort" << endl;
                    for (int i = playerNumber; i < playerNumber + 10; i++)
                    {
                        if (i < players1.size())
                        {
                            cout << i + 1 << ". " << players1.at(i).first << " - " << players1.at(i).second << " " << choiceResult << endl;
                        }
                    }
                }
                else
                {
                    cout << " based on radix sort" << endl;
                    for (int i = playerNumber; i < playerNumber + 10; i++)
                    {
                        if (i < players2.size())
                        {
                            cout << i + 1 << ". " << players2.at(i).first << " - " << players2.at(i).second << " " << choiceResult << endl;
                        }
                    }
                }
                cout << "Page " << pageNumber << "/" << (players1.size() / 10) + 1 << endl
                     << endl;

                // Display appropriate options based on current page
                cout << "Select an option:" << endl;
                if (pageNumber != (players1.size() / 10) + 1)
                {
                    cout << "1 - Next page" << endl;
                }
                if (pageNumber != 1)
                {
                    cout << "2 - Previous page" << endl;
                }
                cout << "3 - Jump to page number\n4 - Switch sorting algorithms\n5 - Done" << endl;

                // Choose another page, switch sort results, or exit
                cin >> choice;
                if (choice == 1 && pageNumber != (players1.size() / 10) + 1)
                {
                    pageNumber++;
                }
                else if (choice == 2 && pageNumber != 1)
                {
                    pageNumber--;
                }
                else if (choice == 3)
                {
                    // ensure selected page is valid
                    while (true)
                    {
                        cout << "\nEnter Page Number: " << endl;
                        cin >> pageNumber;
                        if (pageNumber <= (players1.size() / 10) + 1 && pageNumber > 0)
                        {
                            break;
                        }
                        cout << "Invalid page number. Please try again." << endl;
                    }
                }
                else if (choice == 4)
                {
                    mergeSort = !mergeSort;
                }
                else if (choice == 5)
                {
                    break;
                }
                else
                {
                    cout << "Unrecognized command. Please try again." << endl;
                }
            }
        }
        else if (choice == 2)
        {
            string playerName;
            choice = 0;
            while (choice != 2)
            {
                cout << "\nEnter a player name:" << endl;
                cin >> playerName;

                // if player is present, display their stats
                unordered_map<string, int> player = board.search(playerName);
                if (!player.empty())
                {
                    cout << "\nDisplaying stats for " << playerName << ":\n";
                    cout << "World records held - " << player["records"] << endl;
                    cout << "Courses played - " << player["plays"] << endl;
                    cout << "Courses cleared - " << player["clears"] << endl;
                    cout << "Courses liked - " << player["likes"] << endl;
                }
                else
                {
                    cout << "\nPlayer not found." << endl;
                }
                while (true)
                {
                    // Choose to search again or exit
                    cout << "\nSelect an option:\n1 - Search another player\n2 - Exit" << endl;
                    cin >> choice;
                    if (choice > 2 || choice < 1)
                    {
                        cout << "Unrecognized command. Please try again." << endl;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Unrecognized command. Please try again." << endl;
        }
    }

    return 0;
}