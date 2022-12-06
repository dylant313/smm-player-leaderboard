#include "Leaderboard.cpp"

int main()
{
    // implement console app
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

        // Determines if program will just search players or sort them
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

            // Sort based on choice
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

            // Vector holds sorted players by what the user chose
            vector<pair<string, int>> players = board.mergeSort(choiceResult);

            // Display all users on current page
            int playerNumber;
            int pageNumber = 1;
            choice = 0;
            while (choice != 3)
            {
                cout << "Players with the most " << choiceResult << endl;
                playerNumber = (pageNumber - 1) * 10;
                for (int i = playerNumber; i < playerNumber + 10; i++)
                {
                    if (playerNumber < players.size())
                        cout << i << ". " << players.at(i).first << " - " << players.at(i).second << " " << choiceResult << endl;
                }
                cout << "Page " << pageNumber << "/" << players.size() / 10 << endl
                     << endl;

                // Allow users to select another page
                cout << "Select an option:\n1 - Next page\n2 - Jump to page number\n3 - Done\n"
                     << endl;
                cin >> choice;
                if (choice == 1)
                    pageNumber++;
                else if (choice == 2)
                {
                    // ensure selected page is valid
                    while (true)
                    {
                        cout << "Enter Page Number: " << endl;
                        cin >> pageNumber;
                        if (pageNumber <= players.size() / 10 && pageNumber > 0)
                        {
                            break;
                        }
                        cout << "Invalid page number. Please try again." << endl;
                    }
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