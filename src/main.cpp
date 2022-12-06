#include "Leaderboard.cpp"

int main()
{
    Leaderboard board;

    // Prints out the main menu
    while (true)
    {

        cout << "Welcome to the Super Mario Maker Player database!" << endl;
        cout << "-------------------------------------------------\n\n";

        // Takes in the choice of the user
        int choice;
        cout << "Select an option:\n1 - Sort players\n2 - Search for a player\n3 - Exit" << endl
             << endl;
        cin >> choice;

        // Determines if program will search players or sort them
        if (choice == 1)
        {
            while (true)
            {
                cout << "Sort by which category?" << endl;
                cout << "1 - Number of plays\n2 - Number of clears" << endl;
                cout << "3 - Number of likes given\n4 - Number of world records\n"
                     << endl;

                cin >> choice;
                if (choice > 4 || choice < 1)
                {
                    cout << "Unrecognized command. Try again\n"
                         << endl;
                }
                else
                {
                    break;
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

            // Ensure both sorted vectors have the same output
            vector<pair<string, int>> players1 = board.mergeSort(choiceResult);
            vector<pair<string, int>> players2 = board.radixSort(choiceResult);
            if (players1 != players2)
            {
                throw runtime_error("Sort outputs are not equal");
            }

            // Display all users on current page
            int playerNumber;
            int pageNumber = 1;
            while (true)
            {
                cout << "Players with the most " << choiceResult << endl;
                playerNumber = (pageNumber - 1) * 10;
                for (int i = playerNumber; i < playerNumber + 10; i++)
                {
                    if (playerNumber < players1.size())
                        cout << i + 1 << ". " << players1.at(i).first << " - " << players1.at(i).second << " " << choiceResult << endl;
                }
                cout << "Page " << pageNumber << "/" << players1.size() / 10 << endl
                     << endl;

                // Options to select another page based on current page
                cout << "Select an option:" << endl;
                if (pageNumber != players1.size() / 10)
                {
                    cout << "1 - Next page" << endl;
                }
                if (pageNumber != 1)
                {
                    cout << "2 - Previous page" << endl;
                }
                cout << "3 - Jump to page number\n4 - Done\n"
                     << endl;

                cin >> choice;
                if (choice == 1 && pageNumber != players1.size() / 10)
                    pageNumber++;
                else if (choice == 2 && pageNumber != 1)
                    pageNumber--;
                else if (choice == 3)
                {
                    // ensure selected page is valid
                    while (true)
                    {
                        cout << "Enter Page Number: " << endl;
                        cin >> pageNumber;
                        if (pageNumber <= players1.size() / 10 && pageNumber > 0)
                        {
                            break;
                        }
                        cout << "Invalid page number. Please try again." << endl;
                    }
                }
                else if (choice == 4)
                {
                    break;
                }
                else
                {
                    cout << "Unrecognized command. Try again\n"
                         << endl;
                }
            }
        }
        else if (choice == 2)
        {
            string playerName;
            choice = 0;
            while (choice != 2)
            {
                cout << "Enter a player name:\n";
                cin >> playerName;

                // if player is present, display their stats
                unordered_map<string, int> player = board.search(playerName);
                if (!player.empty())
                {
                    cout << "\nDisplaying stats for " << playerName << ":\n";
                    cout << "World records held - " << player["records"] << endl;
                    cout << "Courses played - " << player["plays"] << endl;
                    cout << "Courses cleared - " << player["clears"] << endl;
                    cout << "Courses liked - " << player["likes"] << endl
                         << endl;
                }
                else
                {
                    cout << "\nPlayer not found.\n"
                         << endl;
                }
                while (true)
                {
                    cout << "Select an option:\n1 - Search another player\n2 - Exit" << endl;
                    cin >> choice;
                    if (choice > 2 || choice < 1)
                    {
                        cout << "Unrecognized command. Try again\n"
                             << endl;
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
            cout << "Unrecognized command. Try again\n"
                 << endl;
        }
    }

    return 0;
}