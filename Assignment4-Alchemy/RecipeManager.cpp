#include<iostream>
#include "PotionRecipe.h"
#include "RecipeManager.h"

using namespace std;

PotionRecipe* RecipeManager::addRecipe(const string& name, const vector<string>& ingredients) {
    PotionRecipe recipe = PotionRecipe(name, ingredients);
    recipes.push_back(recipe);

    return &recipes.back();
}

PotionRecipe* RecipeManager::findRecipeByName(const string& name)
{
    for (PotionRecipe& potionRecipe : recipes) {
        if (potionRecipe.potionName == name) {
            return &potionRecipe;
        }
    }

    return nullptr;
}

vector<PotionRecipe> RecipeManager::findRecipesByIngredient(const string& ingredient)
{
    vector<PotionRecipe> resultRecipe;

    for (const PotionRecipe& potionRecipe : recipes) {
        for (const string& s : potionRecipe.ingredients) {
            if (s == ingredient) {
                resultRecipe.emplace_back(potionRecipe);
                break;
            }
        }
    }

    return resultRecipe;
}

const vector<PotionRecipe>& RecipeManager::getAllrecipes()
{
    return recipes;
}
