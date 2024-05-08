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
        cout << "ERROR! PRODUCT Already AVALIABLE ";
    }
};
void Allproducts::DeleteProduct(string n)
{
    delete prods[n];
    prods.erase(n);
}
void Allproducts::Refill(string n, int q)
{
    if (prods[n])
    {
        prods[n]->IncreaseQuantity(q);
    }
    else
    {
        cout << "ERROR! PRODUCT Not Found ";
    }
};
Product *Allproducts::GetProduct(string name)
{
    return prods[name];
}
bool Allproducts::Search(string n)
{
    bool res = 0;

    // Search for every char
    for (const auto &iter : prods)
    {
        int i = 0;
        while (i < n.length())
        {
            if (iter.first[i] == n[i])
            {
                if (i == n.length() - 1)
                {
                    iter.second->display();
                    res = 1;
                }
            }
            else
            {
                break;
            }
            i++;
        }
    }
    return res;
}
