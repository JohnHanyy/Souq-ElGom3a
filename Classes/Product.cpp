#include "../Sources/Product.h"
#include <iostream>
#include <iomanip>

Product::Product(string n, float p, int q) : id(ind++), name(n), price(p), quantity(q){};

void Product::display()
{
    cout << left << setw(4) << id << left << setw(8)
         << name << left << setw(8)
         << price << left << setw(12)
         << quantity << endl;
}

int Product::GetterId() const
{
    return id;
}
string Product::GetterName() const
{
    return name;
}
float Product::GetterPrice() const
{
    return price;
}
int Product::GetterQuantity() const
{
    return quantity;
}
void Product::SetterQuantity(int n)
{
    quantity = n;
}
void Product::IncreaseQuantity(int n)
{
    quantity += n;
}