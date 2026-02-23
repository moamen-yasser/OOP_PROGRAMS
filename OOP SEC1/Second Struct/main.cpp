// Assume the definition of Exercise 2.2
// a. Write a C++ function, getFruitInput, to read and store data into a variable of fruitType.
// b. Write a C++ function, printFruitInfo, to output data stored into a variable of fruitType.
//    Use appropriate labels to identify each component.

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

void getFruitInput(fruitType& fruit) {
    cout << "Enter fruit name: ";
    getline(cin, fruit.fruitName);

    cout << "Enter color: ";
    getline(cin, fruit.color);

    cout << "Enter fat: ";
    cin >> fruit.fat;

    cout << "Enter sugar: ";
    cin >> fruit.sugar;

    cout << "Enter carbohydrate: ";
    cin >> fruit.carbohydrate;

    cin.ignore();
}

void printFruitInfo(const fruitType& fruit) {
    cout << "\n--- Fruit Information ---\n";
    cout << "Name: " << fruit.fruitName << endl;
    cout << "Color: " << fruit.color << endl;
    cout << "Fat: " << fruit.fat << endl;
    cout << "Sugar: " << fruit.sugar << endl;
    cout << "Carbohydrate: " << fruit.carbohydrate << endl;
}

int main() {
    fruitType myFruit;

    getFruitInput(myFruit);
    printFruitInfo(myFruit);

    return 0;
}

