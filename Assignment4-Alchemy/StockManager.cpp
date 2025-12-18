#include "StockManager.h"

void StockManager::initializeStock(const string& potionName)
{
    potionStock[potionName] = MAX_STOCK;
}

bool StockManager::dispensePotion(const string& potionName)
{
    bool isDispense = potionStock[potionName] > 0 ? true : false;

    if (isDispense) {
        potionStock[potionName]--;
    }

    return isDispense;
}

void StockManager::returnPotion(const string& potionName)
{
    potionStock[potionName]++;
}

int StockManager::getStock(const string& potionName)
{
    return potionStock[potionName];
}
