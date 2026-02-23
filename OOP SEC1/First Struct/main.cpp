// Define a struct fruitType to store the following data about a fruit:
// Fruit name (string), color (string), fat (int), sugar (int), and carbohydrate (int).

// Assume the definition of Exercise 2.2. Declare a variable of type fruitType to store the following data:
// Fruit name—banana, color—yellow, fat—1, sugar—15, carbohydrate—22.

#include <iostream>
#include <string>

using namespace std;

struct fruitType {
    string fruitName;
    string color;
    int fat;
    int sugar;
    int carbohydrate;
};

int main() {
    fruitType fruitOne;

    fruitOne.fruitName = "Banana";
    fruitOne.color = "Yellow";
    fruitOne.fat = 1;
    fruitOne.sugar = 15;
    fruitOne.carbohydrate = 22;

    cout << "Fruit Name: " << fruitOne.fruitName << endl;
    cout << "Color: " << fruitOne.color << endl;
    cout << "Fat: " << fruitOne.fat << endl;
    cout << "Sugar: " << fruitOne.sugar << endl;
    cout << "Carbohydrate: " << fruitOne.carbohydrate << endl;

    return 0;
}
