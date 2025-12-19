#include "AlchemyWorkshop.h"
#include "StockManager.h"
#include "RecipeManager.h"

AlchemyWorkshop::AlchemyWorkshop() 
    :recipeManager(new RecipeManager()),
    stockManager(new StockManager())
{
}

void AlchemyWorkshop::addRecipe(const string& name, const vector<string>& ingredients) {
    recipeManager->addRecipe(name, ingredients);
    stockManager->initializeStock(name);
}

PotionRecipe AlchemyWorkshop::searchRecipeByName(const string& name)
{
    bool isDispense = stockManager->dispensePotion(name);
    if (isDispense == true) {
        return *recipeManager->findRecipeByName(name);
    }

    return PotionRecipe();

}

vector<PotionRecipe> AlchemyWorkshop::searchRecipeByIngredient(const string* ingredient)
{
    vector<PotionRecipe> recipes = recipeManager->findRecipesByIngredient(*ingredient);
    vector<PotionRecipe> results;
    for (const PotionRecipe& recipe : recipes) {
        PotionRecipe potionRecipe = searchRecipeByName(recipe.potionName);

        if (potionRecipe.IsValid()) {
            results.emplace_back(potionRecipe);
        }
    }
    return results;
}

bool AlchemyWorkshop::ReturnPotion(const string& name)
{
    PotionRecipe* recipe = recipeManager->findRecipeByName(name);
    if (recipe->IsValid()) {
        int stock = stockManager->getStock(name);
        if (stock >= 3) {
            return false;

        }

        stockManager->returnPotion(name);
        return true;
    }

    return false;
}

void AlchemyWorkshop::displayAllRecipes() const
{
    const vector<PotionRecipe>& recipes = recipeManager->getAllrecipes();
    if (recipes.empty()) {
        cout << "아직 등록된 레시피가 없습니다." << endl;
        return;
    }

    int cnt = 0;
    cout << "\n--- [ 전체 레시피 목록 ] ---" << endl;
    for (size_t i = 0; i < recipes.size(); ++i) {
        cnt++;
        const string& name = recipes[i].potionName;
        int stock = stockManager->getStock(name);
        if (stock <= 0) {
            continue;
        }
        cout << "- 물약 이름: " << recipes[i].potionName << ", 재고: " << stock << endl;
        cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
            cout << recipes[i].ingredients[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < recipes[i].ingredients.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    cout << "---------------------------\n";

    if (cnt <= 0) {
        cout << "아직 재고가 없습니다.\n" << endl;
        return;
    }
}
