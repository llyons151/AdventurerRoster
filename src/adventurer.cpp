#include "adventurer.h"

/*********************************************************************
Adventurer::Adventurer()
Purpose:
    Initializes the Adventurer object with default name, class, level, 
    and HP.
Parameters:
    -
Return Value:
    None
Notes:
    Default values are "Adventurer", Wizard class, level 1, and 6 HP
*********************************************************************/
Adventurer::Adventurer()
{
    szName = "Adventurer";
    szClass = "Wizard";
    iLevel = 1;
    iHP = 6;
}

/*********************************************************************
Adventurer::Adventurer(string szN, string szC, int iL, int iH)
Purpose:
    Initializes the Adventurer object with passed name, class, level, 
    and HP.
Parameters:
    I   string szN                  Name of the adventurer
    I   string szC                  What class they are playing
    I   int iL                      What level they are
    I   int iH                      How much HP they have
Return Value:
    None
Notes:
    Does not currently validate data
*********************************************************************/
Adventurer::Adventurer(std::string szN, std::string szC, int iL, int iH)
{
    szName = szN;
    szClass = szC;
    iLevel = iL;
    iHP = iH;
}

/*********************************************************************
string Adventurer::getName()
Purpose:
    Returns the name of the adventurer
Parameters:
    -
Return Value:
    A string containing the name
Notes:
    -
*********************************************************************/
std::string Adventurer::getName()
{
    return szName;
}

/*********************************************************************
void Adventurer::setName(string szN)
Purpose:
    Change the adventurer to a new name
Parameters:
    I   string szN              New name to give the adventurer
Return Value:
    -
Notes:
    -
*********************************************************************/
void Adventurer::setName(std::string szN)
{
    szName = szN;
}

/*********************************************************************
string Adventurer::getClass()
Purpose:
    Returns the class of the adventurer
Parameters:
    -
Return Value:
    A string containing the class
Notes:
    -
*********************************************************************/
std::string Adventurer::getClass()
{
    return szClass;
}

/*********************************************************************
void Adventurer::setClass(string szC)
Purpose:
    Change the adventurer to a new name
Parameters:
    I   string szC              New class to give adventurer
Return Value:
    -
Notes:
    -
*********************************************************************/
void Adventurer::setClass(std::string szC)
{
    szClass = szC;
}

/*********************************************************************
int Adventurer::getLevel()
Purpose:
    Returns the level of the adventurer
Parameters:
    -
Return Value:
    An int containing the level
Notes:
    -
*********************************************************************/
int Adventurer::getLevel()
{
    return iLevel;
}

/*********************************************************************
void Adventurer::setLevel(int iL)
Purpose:
    Change the adventurer to a new level
Parameters:
    I   int iL             New level to give adventurer
Return Value:
    -
Notes:
    -
*********************************************************************/
void Adventurer::setLevel(int iL)
{
    iLevel = iL;
}

/*********************************************************************
int Adventurer::getHP()
Purpose:
    Returns the hp of the adventurer
Parameters:
    -
Return Value:
    An int containing the hp
Notes:
    -
*********************************************************************/
int Adventurer::getHP()
{
    return iHP;
}

/*********************************************************************
void Adventurer::setHP(int iH)
Purpose:
    Change the adventurer to a new hp
Parameters:
    I   int iH             New hp to give adventurer
Return Value:
    -
Notes:
    -
*********************************************************************/
void Adventurer::setHP(int iH)
{
    iHP = iH;
}

/*********************************************************************
void Adventurer::displayAdventurer()
Purpose:
    Displays information regarding an adventurer
Parameters:
    -
Return Value:
    -
Notes:
    -
*********************************************************************/
void Adventurer::displayAdventurer()
{
    std::cout << "Adventurer's Information" << std::endl;
    std::cout << "Name : " << szName << std::endl;
    std::cout << "Class: " << szClass << std::endl;
    std::cout << "Level: " << iLevel << std::endl;
    std::cout << "HP   : " << iHP << std::endl;
    std::cout << std::endl;
}
