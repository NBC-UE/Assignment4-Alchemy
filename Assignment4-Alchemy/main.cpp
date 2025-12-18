#include <iostream>
#include <vector>
#include <string>
#include "PotionRecipe.h"
#include "AlchemyWorkshop.h"
#include <unordered_map>>

using namespace std;

int main() {
    AlchemyWorkshop myWorkshop;
    unordered_map<string, int> potions;

    while (true) {
        cout << "\n\n";
        cout << "⚗️ 연금술 공방 관리 시스템" << endl;
        cout << "1. 레시피 추가" << endl;
        cout << "2. 현재 재고가 있는 모든 레시피 출력" << endl;
        cout << "3. 물약 이름 검색 가져오기" << endl;
        cout << "4. 물약 레시피 검색 가져오기" << endl;
        cout << "5. 물약 반환" << endl;
        cout << "6. 소유한 물약 정보" << endl;
        cout << "7. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            string name;
            cout << "물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            // 여러 재료를 입력받기 위한 로직
            vector<string> ingredients_input;
            string ingredient;
            cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << endl;

            while (true) {
                cout << "재료 입력: ";
                getline(cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
                cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << endl;
            }
            else {
                cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2) {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3) {
            cout << "찾을 물약 이름을 알려주세요.: ";
            string name;
            cin >> name;
            const PotionRecipe potionRecipe =  myWorkshop.searchRecipeByName(name);
            if (potionRecipe.IsValid() == false) {
                cout << "재고가 없거나 찾을 물약이 없습니다.\n";
            }
            else {
                cout << "찾은 물약 이름: " << potionRecipe.potionName << "\n";
                potions[potionRecipe.potionName]++;
            }
        }
        else if (choice == 4) {
            cout << "재료: ";
            string recipeName;
            cin >> recipeName;
            vector<PotionRecipe> recipes = myWorkshop.searchRecipeByIngredient(&recipeName);
            if (recipes.empty()) {
                cout << "재고가 없거나 찾을 물약이 없습니다.\n";
            }
            else {
                for (const auto& recipe : recipes) {
                    cout << "찾은 물약 이름: " << recipe.potionName << "\n";
                    potions[recipe.potionName]++;
                }
            }
        }
        else if (choice == 5) {
            cout << "반환할 물약 이름을 말해주세요: ";
            string s;
            cin >> s;

            bool isSuccess = myWorkshop.ReturnPotion(s);
            if (isSuccess) {
                cout << "물약을 반환합니다.\n";
            }
            else {
                cout << "반환할 물약이 없거나 재고가 이미 꽉찼습니다.\n";
            }
        }
        else if (choice == 6) {
            cout << "=== 보유한 물약 수량 ===\n";
            cout << "소유한 모든 물약을 보여줍니다.\n";
            for (const auto& p : potions) {
                const string& name = p.first;
                const int stock = p.second;

                cout << "이름: " << name << ", 수량: " << stock << "\n";
            }
            cout << "========\n";
        }
        else if (choice == 7) {
            cout << "=== 현재 공방 재고 출력 ===\n";

        }
        else if (choice == 7) {
            cout << "공방 문을 닫습니다..." << endl;
            break;
        }
        else {
            cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}