#include "../Sources/MainMenu.h"
MainMenu::MainMenu() : current_user(nullptr)
{
    Users.load();
    supermarket.load();
    HomePage();
}

MainMenu::~MainMenu()
{
    Users.save();
    supermarket.save();
}

void MainMenu::HomePage()
{
    int inp;
    current_user = nullptr;
    cout << endl
         << "\t"
         << "-- WELCOME TO SOUQ EL GOM3A -- "
         << "\t"
         << endl;

    cout << "[1] Login" << endl;
    cout << "[2] Register " << endl;
    cout << "[0] Exit " << endl;
    cout << "[-1] About " << endl;

    cin >> inp;
    if (inp == 1)
        Login();
    else if (inp == 2)
        Register();
    else if (inp == -1)
    {
        cout << endl
             << "This Work is done by : \n \tAnas Sabry \n \tJohn Hany \n \tMoaz Eldamery \n \tYoussef Hawash"
             << endl;
        return HomePage();
    }
    else
        return;
}
void MainMenu::Login()
{
    // Used Variables
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
    if (!current_user)
    {
        bool inp;
        cout << endl
             << "Error! Invalid Email or Password!!!" << endl;
        cout << "[0] Create New Account " << endl;
        cout << "[1] Try Again! " << endl;
        cin >> inp;
        if (inp)
        {
            return Login();
        }
        else
        {
            return Register();
        }
    }
    else if (current_user->Get_password() == Password)
    {
        return NavPage();
    }
}
void MainMenu::Register()
{
    // Used Variables
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
    cout << "Admin [0] [1] : ";
    cin >> a;
    if (!Users.Search(Email))
    {
        Users.CreateUser(Email, Password, name, age, num, a);
        cout << "Successful Creation !!" << endl;
        return Login();
    }
    else
    {
        bool inp;
        cout << endl
             << "Error! Email is used!!!" << endl;
        cout << "[0] Try Again! " << endl;
        cout << "[1] Login " << endl;
        cin >> inp;
        if (inp)
        {
            return Register();
        }
        else
        {
            return Login();
        }
    }
}
void MainMenu::NavPage()
{
    int inp;
    cout << " -- Hello, " << current_user->Get_Name() << "-- " << endl;
    if (!current_user->IsAdmin())
    {
        cout << "[1] SuperMarket" << endl;
        cout << "[2] Cart " << endl;
        cout << "[3] Wallet " << endl;
        cout << "[4] User Info " << endl;
        cout << "[0] Logout " << endl;

        cin >> inp;
        if (inp == 1)
            return MarketPage();
        else if (inp == 2)
            return CartPage();
        else if (inp == 3)
        {
            return WalletsPage();
        }
        else if (inp == 4)
            return UserPage();
        else
            return HomePage();
    }
    else
    {
        cout << "[1] SuperMarket" << endl;
        cout << "[2] User Info " << endl;
        cout << "[0] Logout " << endl;
        cin >> inp;
        if (inp == 1)
            return MarketPage();
        else if (inp == 2)
            return UserPage();

        else
            return HomePage();
    }
}
void MainMenu::MarketPage()
{
    int inp;
    cout << endl
         << "-- SUPERMARKET --"
         << endl;
    supermarket.Display();
    cout << endl;
    if (current_user->IsAdmin())
    {
        cout << "[1] Add Product " << endl;
        cout << "[2] Refill A Product " << endl;
        cout << "[3] Delete Product " << endl;
        cout << "[4] Search for a Product " << endl;
        cout << "[0] Return To MainMenu " << endl;

        cin >> inp;
        if (inp == 1)
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
            return MarketPage();
        }
        else if (inp == 2)
        {
            string name;
            int quantity;
            cout << "Enter Prodcut Name : ";
            cin >> name;
            cout << "Enter Product Refilled Quantity : ";
            cin >> quantity;
            supermarket.Refill(name, quantity);
            return MarketPage();
        }
        else if (inp == 3)
        {
            string name;
            cout << "Enter Prodcut Name : ";
            cin >> name;
            supermarket.DeleteProduct(name);
            return MarketPage();
        }
        else if (inp == 4)
        {
            string name;
            cout << "Search: ";
            cin >> name;
            cout << " -- SEARCH RESULTS -- " << endl;
            if (!supermarket.Search(name))
            {
                cout << " \t Nothing Found !!" << endl;
            }
            cout << endl;
            return MarketPage();
        }
        else
        {
            return NavPage();
        }
    }
    else
    {
        cout << "[1] Buy a Product " << endl;
        cout << "[2] Search for a Product " << endl;
        cout << "[0] Return To MainMenu " << endl;

        cin >> inp;
        if (inp == 1)
        {
            string name;
            int quantity;
            cout << "Enter Prodcut Name : ";
            cin >> name;
            cout << "Enter Product Quantity : ";
            cin >> quantity;
            if (quantity > supermarket.GetProduct(name)->GetterQuantity())
            {
                cout << "Error !!!" << endl;
                return MarketPage();
            }
            current_user->GetCart()->AddProduct(supermarket.GetProduct(name), quantity);
            cout << "Successful Added!!" << endl;
            return MarketPage();
        }
        else if (inp == 2)
        {
            string name;
            cout << "Search: ";
            cin >> name;
            cout << " -- SEARCH RESULTS -- " << endl;
            if (!supermarket.Search(name))
            {
                cout << " \t Nothing Found !!" << endl;
            }
            cout << endl;
            return MarketPage();
        }
        else
        {
            return NavPage();
        }
    }
}
void MainMenu::UserPage()
{
    int inp;
    cout << "Email: " << current_user->Get_Email() << endl;
    cout << "Password: " << current_user->Get_password() << endl;
    cout << "Username: " << current_user->Get_Name() << endl;
    cout << "Age: " << current_user->Get_Age() << endl;
    cout << "Phone Number: " << current_user->Get_Phone_Num() << endl;
    cout << "Admin: " << current_user->IsAdmin() << endl;
    cout << endl
         << "[0] Return To NavPage" << endl;
    cin >> inp;
    if (inp == 0)
    {
        return NavPage();
    }
    else
    {
        return UserPage();
    }
}

void MainMenu::CartPage()
{
    int inp;
    cout << "\n-- CART --\n";
    current_user->GetCart()->Display();
    cout << endl
         << "[1] To remove a Product" << endl
         << "[2] Checkout" << endl
         << "[0] return" << endl;
    cin >> inp;
    if (inp == 1)
    {
        string name;
        cout << "Enter Name:" << endl;
        cin >> name;
        current_user->GetCart()->RemoveProduct(name);
    }
    else if (inp == 2)
    {
        string name;
        cout << "Which Wallet" << endl;
        cin >> name;

        if (current_user->Get_wallet(name))
        {
            if (current_user->Pay(name))
            {
                cout << "Pay successful" << endl;
                return NavPage();
            }
            else
            {
                cout << "Can not find that Wallet Try again" << endl;
                return CartPage();
            }
        }
        else
        {
            cout << "wallet not found" << endl;
            return CartPage();
        }
    }
    else
    {
        return NavPage();
    }
}

void MainMenu::WalletsPage()
{
    int choose;
    cout << "Your Wallets" << endl;
    current_user->Cards_Display();
    cout << "[1] To add a new card" << endl
         << "[2] To remove a card" << endl
         << "[3] return" << endl;
    cin >> choose;
    if (choose == 1)
    {
        string name;
        float balance;
        int cvv, cardnum;
        cout << "Enter Card Name: ";
        cin >> name;
        cout << "Enter Card Balance: ";
        cin >> balance;
        cout << "Enter CVV: ";
        cin >> cvv;
        cout << "Enter Card Number: ";
        cin >> cardnum;
        current_user->Add_Credit_card(name, balance, cvv, cardnum);
        cout << "Card added" << endl;
        return WalletsPage();
    }
    if (choose == 2)
    {
        string cardname;
        cout << "Enter the card name" << endl;
        cin >> cardname;
        if (current_user->Delete_Wallet(cardname))
        {
            cout << "Card deleted successfully" << endl;
            return WalletsPage();
        }
        else
        {
            cout << "card not found" << endl;
            return WalletsPage();
        }
    }
    else if (choose == 3)
    {
        return NavPage();
    }
}