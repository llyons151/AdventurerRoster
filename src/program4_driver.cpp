#include "adventurer.h"
#include "string"


/*********************************************************************
File name: program4_driver.cpp
Author: Dr. Patrick
Date: 9/25/2025

Purpose:
    Simulate DnD adventurer management.
Command Parameters:
    -
Input:
    Various menu options
Results:
    Manages a roster of adventurers for a DM
Notes:
    -
*********************************************************************/
int main()
{
    int iCapacity = 2;
    int iNumAdventurers = 0;

    std::string szDefaultMenuiChoicesArr[8] = 
	{
        "Add an adventurer",
        "View all adventurers",
        "Sort adventurers by level",
        "Sort adventurers by hit points",
        "Search for an adventurer by name",
        "Search for an adventurer by level",
        "Sort by level with statistics (Extra Credit)",
        "Exit"
    };

    // Dynamically allocate array for adventurers
    Adventurer* roster = new Adventurer[iCapacity]; 

    int iChoice;

    do 
    {
        displayMenu("\nMain Menu", szDefaultMenuiChoicesArr, 8);
        std::cout << "\nEnter choice: ";
        std::cin >> iChoice;

        switch (iChoice) 
        {
            case 1:
            {
                addAdventurer(roster, iNumAdventurers, iCapacity); 
                break;
            } 
            case 2: 
            {
                viewAdventurers(roster, iNumAdventurers); 
                break;
            }
            case 3: 
            {
                insertionSortByLevel(roster, iNumAdventurers); 
                viewAdventurers(roster, iNumAdventurers); 
                break;
            }
            case 4: 
            {
                selectionSortByHP(roster, iNumAdventurers); 
                viewAdventurers(roster, iNumAdventurers); 
                break;
            }
            case 5: 
            {
                std::string szSearchName;
                std::cout << "Enter adventurer's name: ";
                std::cin.ignore(); // Clear the newline character
                getline(std::cin, szSearchName);
                int iIndex = linearSearchByName(roster, iNumAdventurers, szSearchName);
                if (iIndex != -1)
                    roster[iIndex].displayAdventurer();
                else
                    std::cout << "Adventurer not found." << std::endl;
                break;
            }
            case 6: 
            {
                int iSearchLevel;
                std::cout << "Enter adventurer's HP: ";
                std::cin >> iSearchLevel;
                int iIndex = binarySearchByHP(roster, iNumAdventurers, iSearchLevel);
                if (iIndex != -1)
                    roster[iIndex].displayAdventurer();
                else
                    std::cout << "Adventurer not found." << std::endl;
                break;
            }
            case 7:
            {
                int iComparisons = 0;
                int iSwaps = 0;
                insertionSortByLevelWithStats(roster, iNumAdventurers, iComparisons, iSwaps);
                std::cout << "Sorting complete!" << std::endl;
                std::cout << "Comparisons: " << iComparisons << std::endl;
                std::cout << "Swaps: " << iSwaps << std::endl;
                viewAdventurers(roster, iNumAdventurers);
                break;
            }
            case -1: 
            {
                std::cout << "Exiting the program." << std::endl; 
                break;
            }
            default: 
            {
                std::cout << "Invalid iChoice. Try again." << std::endl;
            }
        }

    } while (iChoice != -1);

    // Free the dynamically allocated memory
    delete[] roster;
}
