#pragma once
#include <vector>
#include <string>

using namespace std;

// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
class PotionRecipe {
public:
    string potionName;
    vector<string> ingredients; // 단일 재료에서 재료 '목록'으로 변경

    PotionRecipe() :potionName("") {

    }

    // 생성자: 재료 목록을 받아 초기화하도록 수정
    PotionRecipe(const string& name, const vector<string>& ingredients)
        : potionName(name), ingredients(ingredients) {
    }

    bool IsValid() const {
        return potionName != "";
    }
};
