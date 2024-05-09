#pragma once
#include <string>
using namespace std;
// enum Category
// {
//     food = 0,        // =0
//     Electronics = 1, // =1
//     books = 2,       // =2
//     others = 3       // =3
// };
class Product
{
private:
    int id;
    string name;
    float price;
    int quantity;
    static int ind;

    string Cat;

public:
    Product(string, float, int, string);
    void display();

    int GetterId() const;
    string Get_category();
    string GetterName() const;
    float GetterPrice() const;
    int GetterQuantity() const;
    void SetterQuantity(int);
    void IncreaseQuantity(int);
};
int Product::ind = 0;