#include "../Sources/AllProducts.h"

Allproducts::Allproducts()
{
    Catrgories.push_back("Food");
    Catrgories.push_back("Electronics");
    Catrgories.push_back("Books");
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
void Allproducts::CreateProduct(string n, float p, int q, string t)
{
    if (!prods[n])
    {
        Product *tmp = new Product(n, p, q, t);
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

void Allproducts::save()
{
    ofstream save;
    save.open("allproduct.dat");
    unordered_map<string, Product *>::iterator itr = prods.begin();
    for (int i = 0; i < prods.size(); i++)
    {
        save << itr->second->GetterName() << '\t' << itr->second->GetterPrice() << '\t' << itr->second->GetterQuantity();
        if (i < prods.size() - 1)
            itr++;
        {
            save << endl;
        }
    }
    save.close();
}
void Allproducts::load()
{
    string tempname;
    float tempprice;
    int tempquantity;
    string tempcat;
    ifstream load;
    load.open("allproduct.dat");
    while (load >> tempname)
    {
        load >> tempprice;
        load >> tempquantity;
        load >> tempcat;
        CreateProduct(tempname, tempprice, tempquantity, tempcat);
    }
    load.close();
}

Product *Allproducts::GetProduct(string name)
{
    return prods[name];
}

void Allproducts::DisplayCategory(string n)
{
    unordered_map<string, Product *>::iterator itr = prods.begin();
    for (int i = 0; i < prods.size(); i++)
    {
        if (itr->second->Get_category() == n)
        {
            itr->second->display();
        }
        itr++;
    }
}

void Allproducts::DisplayAllCats()
{
    for (int i = 0; i < Catrgories.size(); i++)
    {
        cout << Catrgories[i] << endl;
    }
}

void Allproducts::Addcategory(string cat)
{
    Catrgories.push_back(cat);
}

bool Allproducts::findcategory(string n)
{
    for (int i = 0; i < Catrgories.size(); i++)
    {
        if (Catrgories[i] == n)
        {
            return 1;
        }
    }
    return 0;
}