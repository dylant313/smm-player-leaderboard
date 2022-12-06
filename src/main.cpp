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
        cout << "Select an option:\n1 - Sort players\n2 - Search for a player\n3 - Exit" << endl
             << endl;

        // Takes in the choice of the user
        int choice;
        cin >> choice;

        // Determines if program will just search players or sort them
        if (choice == 1)
        {
            // Sorting
            cout << "Sort by which category?" << endl;
            cout << "1 - Number of plays\n2 - Number of clears" << endl;
            cout << "3 - Number of likes given\n4 - Number of world records\n"
                 << endl;

            cin >> choice;
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

            cout << "Merge Sort: completed in "
                 << " ms" << endl;
            cout << "Radix Sort: completed in "
                 << " ms" << endl;
            cout << endl;

            cout << "Players with the most " << choiceResult << endl;
            int playerNumber;
            int pageNumber = 1;
            while (choice != 3)
            {
                playerNumber = (pageNumber - 1) * 10;
                for (int i = playerNumber; i < playerNumber + 10; i++)
                {
                    if (playerNumber < players.size())
                        cout << playerNumber << ". " << players.at(i).first << " - " << players.at(i).second << " " << choiceResult << endl;
                }

                cout << pageNumber << "/" << players.size() / 10 << endl
                     << endl;

                cout << "Select an option:\n1 - Next page\n2 - Jump to page number\n3 - Done\n"
                     << endl;

                cin >> choice;
                if (choice == 1)
                    pageNumber++;
                else if (choice == 2)
                {
                    cout << "Enter Page Number: " << endl;
                    cin >> pageNumber;
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
                cout << "Displaying stats for " << playerName << ":\n";
                cout << "World records held - " << player["records"] << endl;
                cout << "Courses played - " << player["plays"] << endl;
                cout << "Courses cleared - " << player["clears"] << endl;
                cout << "Courses liked - " << player["likes"] << endl
                     << endl;

                cout << "Select an option:\n1 - Search another player\n2 - Exit" << endl;
                cin >> choice;
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}