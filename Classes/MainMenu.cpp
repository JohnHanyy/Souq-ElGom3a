#include "../Sources/MainMenu.h"
MainMenu::MainMenu() : current_user(nullptr)
{
    bool Inp;
    cout << endl
         << "\t"
         << "-- WELCOME TO SOUQ EL GOM3A -- "
         << "\t"
         << endl;
    cout << "[0] Login" << endl;
    cout << "[1] Register " << endl;
    cin >> Inp;
    if (!Inp)
        Login();
    else
        Register();
}
void MainMenu::Login()
{
    string Email, Password;
    cout << endl
         << "-- LOGIN -- "
         << endl;
    cout << endl
         << "Enter Your Email : ";
    cin >> Email;
    cout << endl
         << "Enter Your Password : ";
    cin >> Password;
    current_user = Users.Search(Email);
    if (!current_user && current_user->Get_password() == Password)
    {

        cout << " -- Hello, " << current_user->Get_Name();
        return Display_Market();
    }
    else
    {
        bool Inp;
        cout << endl
             << "Error! Invalid Email or Password!!!" << endl;
        cout << "[0] Create New Account " << endl;
        cout << "[1] Try Again! " << endl;
        cin >> Inp;
        if (Inp)
        {
            return Register();
        }
        else
        {
            return Login();
        }
    }
}
void MainMenu::Register()
{
    string Email, Password, name;
    int age, num;
    bool a;
    cout << endl
         << "-- Register -- "
         << endl;
    cout << "Enter Your Email : ";
    cin >> Email;
    cout << "Enter Your Password : ";
    cin >> Password;
    cout << "Enter Your Name : ";
    cin >> name;
    cout << "Enter Your Age : ";
    cin >> age;
    cout << "Enter Your Phone Number : ";
    cin >> num;
    cout << "Admin [0][1] : ";
    cin >> a;
    if (!Users.Search(Email))
    {
        current_user = Users.CreateUser(Email, Password, name, age, num, a);
        return Display_Market();
    }
    else
    {
        bool Inp;
        cout << endl
             << "Error! Email is used!!!" << endl;
        cout << "[0] Try Again! " << endl;
        cout << "[1] Login " << endl;
        cin >> Inp;
        if (Inp)
        {
            return Register();
        }
        else
        {
            return Login();
        }
    }
}
void MainMenu::Display_Market()
{
    int Inp;
    cout << endl
         << "-- SUPERMARKET --"
         << endl;
    supermarket.Display();
    if (current_user->IsAdmin())
    {
        cout << "[0] Add Product " << endl;
        cout << "[1] Buy " << endl;
        cin >> Inp;
        if (Inp == 0)
        {
            string name;
            int quantity;
            float price;
            cout << "Enter Prodcut Name : ";
            cin >> name;
            cout << "Enter Product Quantity : ";
            cin >> quantity;
            cout << "Enter Product Price : ";
            cin >> price;
            supermarket.CreateProduct(name, price, quantity);
            return Display_Market();
        }
    }
}