#include "adventurer.h"


/*********************************************************************
void displayMenu(string szMenuName, string szChoicesArr[], int iChoices)
Purpose:
    Function to display the menu choices of a provided menu
Parameters:
    I   string szMenuName       Title of the displayed menu
    I   string szChoicesArr     Menu choices to be displayed
    I   int iChoices            Number of menu choices    
Return Value:
    -
Notes:
    Menu options are displayed starting at 1
    The last menu option should always be displayed as -1
*********************************************************************/
void displayMenu(std::string szMenuName, std::string szChoicesArr[], int iChoices)
{
    std::cout << "displayMenu not implemented yet" << std::endl; 
}

/*********************************************************************
void addAdventurer(Adventurer*& roster, int& iSize, int& iCapacity)
Purpose:
    Add an adventurer to the dynamic roster
Parameters:
    I/O Adventurer*& roster     Dynamic roster of adventurers
    I/O int& iSize              Current number of adventurers
    I/O int& iCapacity          Roster capacity    
Return Value:
    -
Notes:
    The function adds 10 to the capacity once it has been reached.
*********************************************************************/
void addAdventurer(Adventurer*& roster, int& iSize, int& iCapacity)
{
    std::cout << "addAdventurer not implemented yet" << std::endl; 
}

/*********************************************************************
void viewAdventurers(Adventurer* roster, int iSize)
Purpose:
    Display all adventurers in a roster.
Parameters:
    I   Adventurer* roster     Dynamic roster of adventurers
    I   int iSize              Current number of adventurers
Return Value:
    -
Notes:
    This function should call the displayAdventurer function. 
*********************************************************************/
void viewAdventurers(Adventurer* roster, int iSize)
{
    std::cout << "viewAdventurers not implemented yet" << std::endl; 
}

/*********************************************************************
void selectionSortByHP(Adventurer* roster, int iSize)
Purpose:
    Sorts the roster by hp using selection sort
Parameters:
    I/O Adventurer* roster     Dynamic roster of adventurers
    I   int iSize              Current number of adventurers
Return Value:
    -
Notes:
    This function CANNOT use pre-made sorting libraries
	Sort in descending order
*********************************************************************/
void selectionSortByHP(Adventurer* roster, int iSize)
{
    std::cout << "selectionSortByHP not implemented yet" << std::endl; 
}

/*********************************************************************
void insertionSortByLevel(Adventurer* roster, int iSize)
Purpose:
    Sorts the roster by level using insertion sort
Parameters:
    I/O Adventurer* roster     Dynamic roster of adventurers
    I   int iSize              Current number of adventurers
Return Value:
    -
Notes:
    This function CANNOT use pre-made sorting libraries
	Sort in ascending order
*********************************************************************/
void insertionSortByLevel(Adventurer* roster, int iSize)
{
    std::cout << "insertionSortByLevel not implemented yet" << std::endl; 
}

/*********************************************************************
int linearSearchByName(Adventurer* roster, int iSize, const string& szTargetName)
Purpose:
    Searches roster by name using a linear search
Parameters:
    I   Adventurer* roster              Dynamic roster of adventurers
    I   int iSize                       Current number of adventurers
    I   const string& szTargetName      Name of adventurer to find
Return Value:
    First index of adventurer with target name. Otherwise, -1.
Notes:
    This function CANNOT use pre-made searching libraries.
*********************************************************************/
int linearSearchByName(Adventurer* roster, int iSize, const std::string& szTargetName)
{
    std::cout << "linearSearchByName not implemented yet" << std::endl; 
    return -1;
}

/*********************************************************************
int binarySearchByHP(Adventurer* roster, int iSize, int iTargetHP)
Purpose:
    Sorts the roster by hp using insertion sort
Parameters:
    I   Adventurer* roster              Dynamic roster of adventurers
    I   int iSize                       Current number of adventurers
    I   int iTargetHP                	Level of adventurer to find
Return Value:
    First index of adventurer with target level. Otherwise, -1.
Notes:
    This function CANNOT use pre-made searching libraries.
*********************************************************************/
int binarySearchByHP(Adventurer* roster, int iSize, int iTargetHP)
{
    std::cout << "binarySearchByHP not implemented yet" << std::endl;
    return -1;
}

// Extra credit (You must document yourself)
void insertionSortByLevelWithStats(Adventurer* roster, int iSize, int& iComparisons, int& iSwaps)
{
	std::cout << "Not implemented" << std::endl;
}
