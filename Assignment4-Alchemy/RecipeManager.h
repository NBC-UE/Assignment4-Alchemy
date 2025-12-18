#pragma once
#include<vector>
#include<string>

class PotionRecipe;

using namespace std;

class RecipeManager {
public:
    PotionRecipe* addRecipe(const string& name, const vector<string>& ingredients);
    PotionRecipe* findRecipeByName(const string& name);
    vector<PotionRecipe> findRecipesByIngredient(const string& ingredient);
    const vector<PotionRecipe>& getAllrecipes();
private:
    vector<PotionRecipe> recipes;
};