#ifndef PRODUCT_H
#define PRODUCT_H
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

public:
    Product(string, float, int);
    void display();

    int GetterId() const;
    string GetterName() const;
    float GetterPrice() const;
    int GetterQuantity() const;
    void SetterQuantity(int);
    void IncreaseQuantity(int);
};
#endif // PRODUCT_H