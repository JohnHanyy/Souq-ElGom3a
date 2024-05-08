#include "../Sources/Cart.h"

Cart::Cart()
{
    total = 0;
}
void Cart::CalculateTotal()
{
    for (const auto &iter : prods)
    {
        total += iter.second->GetterPrice() * iter.second->GetterQuantity();
    }
}
void Cart::Display()
{
    cout << left << setw(4) << "Id" << left << setw(8) << "Name" << left
         << setw(8) << "Cost" << left << setw(12)
         << "Quantity " << endl;
    for (const auto &iter : prods)
    {
        iter.second->display();
    }
    cout << "Total : " << total << "$";
}
void Cart::AddProduct(Product *a, int q)
{
    if (!prods[a->GetterName()])
    {
        a->IncreaseQuantity(-q);
        Product *tmp = new Product(a->GetterName(), a->GetterPrice(), q);
        prods[a->GetterName()] = tmp;
    }
    else
    {
        prods[a->GetterName()]->IncreaseQuantity(q);
    }
    return CalculateTotal();
};
void Cart::RemoveProduct(string n)
{
    delete prods[n];
    prods.erase(n);
    return CalculateTotal();
}
