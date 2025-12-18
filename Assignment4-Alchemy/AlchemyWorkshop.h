#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "PotionRecipe.h"

using namespace std;

class RecipeManager;
class StockManager;

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
private:
    RecipeManager* recipeManager;
    StockManager* stockManager;

public:
    AlchemyWorkshop();

    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const string& name, const vector<string>& ingredients);

    PotionRecipe searchRecipeByName(const string& name);

    vector<PotionRecipe> searchRecipeByIngredient(const string* ingredient);

    bool ReturnPotion(const string& name);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;
};