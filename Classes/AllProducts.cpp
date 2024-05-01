#include "../Sources/AllProducts.h"

Allproducts::Allproducts()
{
}

void Allproducts::Display()
{

    cout << left << setw(4) << "Id" << left << setw(8) << "Name" << left
         << setw(8) << "Cost" << left << setw(12)
         << "Quantity " << endl;
    for (const auto &iter : prods)
    {
        iter.second->display();
    }
}
void Allproducts::CreateProduct(string n, float p, int q)
{
    if (!prods[n])
    {
        Product *tmp = new Product(n, p, q);
        prods[n] = tmp;
    }
    else
    {
        cout << "ERROR! PRODUCT AVALIABLE ";
    }
};