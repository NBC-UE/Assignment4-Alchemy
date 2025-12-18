#pragma once
#include<unordered_map>
#include<string>

using namespace std;
class StockManager {
public:
    void initializeStock(const string& potionName);
    bool dispensePotion(const string& potionName);
    void returnPotion(const string& potionName);
    int getStock(const string& potionName);
private:
    const int MAX_STOCK = 3;
    unordered_map<string, int> potionStock;
};