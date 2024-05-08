#ifndef CART_H
#define CART_H
#include "Product.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <unordered_map>

using namespace std;

class Cart
{
private:
    float total;
    unordered_map<string, Product *> prods;

public:
    Cart();
    void AddProduct(Product *, int);
    void RemoveProduct(string);
    void CalculateTotal();

    void Display();
};

#endif // CART_H
