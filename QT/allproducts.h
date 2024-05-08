#ifndef ALLPRODUCTS_H
#define ALLPRODUCTS_H
#include "Product.h"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <unordered_map>

using namespace std;

class Allproducts
{
private:
    unordered_map<string, Product *> prods;

public:
    Allproducts();
    void CreateProduct(string, float, int);
    void DeleteProduct(string);
    bool Search(string);
    void Refill(string, int);
    void Display();
    void save();
    void load();
};

#endif // ALLPRODUCTS_H
