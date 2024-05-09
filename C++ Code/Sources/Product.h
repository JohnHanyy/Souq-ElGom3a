#pragma once
#include <string>
using namespace std;
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