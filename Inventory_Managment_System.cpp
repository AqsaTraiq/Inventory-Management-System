#include <iostream>
#include <fstream>

using namespace std;
static int s_id = 1000;
static int c_id = 1000;
static int p_id = 1000;
class IMS
{
private:
    string name;
    char gender;
    int quantity;

public:
    // CONSTRUCTR AND DESTRUCTOR
    IMS()
    {
        name = " ";
        gender = ' ';
        quantity = 0;
    }
    // SETTER AND GETTER
    void setName()
    {
        cout << "\nEnter your name : ";
        cin >> name;
    }
    void setGender()
    {
        cout << "\nEnter your gander :";
        cin >> gender;
    }
    void setQuantity()
    {
        cout << "\nQuantity : ";
        cin >> quantity;
    }
    string getName()
    {
        return name;
    }
    int getQuantity()
    {
        return quantity;
    }
    char getGender()
    {
        return gender;
    }
    // MEMEBR FUNCTIONS
    void insert(int c)
    {
        if (c == 1)
        {
            // getting input from the user
            setName();
            setGender();
            s_id++;

            // writing to the file
            ofstream myfile("shopkeeper.txt", ios::app);
            myfile << s_id << " " << getName() << " " << getGender() << endl;

            myfile.close();
        }
        else if (c == 2)
        {
            // getting input from the user
            setName();
            setQuantity();
            p_id++;
            // writing to the file
            ofstream myfile("product.txt", ios::app);
            myfile << p_id << " " << getName() << " " << getQuantity() << endl;
            myfile.close();
        }
        else if (c == 3)
        {
            // getteing input from the user
            setName();
            setGender();
            c_id++;
            // writing to the file
            ofstream myfile("customer.txt", ios::app);
            myfile << c_id << " " << getName() << " " << getGender() << endl;
            myfile.close();
        }
    }
    void search(int c)
    {
        string n;
        int id, ID;
        char g;
        bool found = false;
        int q;
        if (c == 1)
        {
            cout << "\nEnter the id of the shopkeeper : ";
            cin >> ID;
            ifstream obj("shopkeeper.txt");
            obj >> id >> n >> g;
            while (true)
            {

                if (id == ID)
                {
                    cout << "\nEntered data is available inside the file .";

                    //  return;
                    found = true;
                }
                if (obj.eof())
                    break;
                obj >> id >> n >> g;
            }
            obj.close();
            if (!found)
            {
                cout << "\nEntered data is not available inside the file ";
            }
        }
        else if (c == 2)
        {
            cout << "\nEnter the ID  of the product you wanna search : ";
            cin >> ID;
            ifstream obj("product.txt");
            obj >> id >> n >> q;
            while (true)
            {

                if (ID == id)
                {
                    cout << "\nEntered data is availe inside ... ";
                    found = true;
                }
                if (obj.eof())
                    break;
                obj >> id >> n >> q;
            }
            obj.close();
            if (!found)
            {
                cout << "\nEnter data isn't available... ";
            }
        }
        else if (c == 3)
        {
            cout << "\nEnter the ID of the customer to search : ";
            cin >> ID;
            ifstream obj("customer.txt");
            obj >> id >> n >> g;
            while (true)
            {

                if (ID == id)
                {
                    cout << "\nEntered data is available in the file ...";
                    break;
                    found = true;
                }
                if (obj.eof())
                    break;
                obj >> id >> n >> g;
            }
            obj.close();
            if (!found)
            {
                cout << "\nEntered data is not available... ";
            }
        }
    }
    void view(int c)
    {
        int id, q;
        string n;
        char g;
        if (c == 1)
        {
            ifstream obj("shopkeeper.txt");
            while (true)
            {
                obj >> id >> n >> g;
                if (obj.eof())
                    break;
                cout << id << "\t" << n << "\t" << g << endl;
            }
        }
        else if (c == 2)
        {
            ifstream obj("product.txt");
            while (true)
            {
                obj >> id >> n >> q;
                if (obj.eof())
                    break;
                cout << id << "\t" << n << "\t" << q << endl;
            }
            obj.close();
        }
        else if (c == 3)
        {
            ifstream obj("customer.txt");
            while (true)
            {
                obj >> id >> n >> g;
                if (obj.eof())
                    break;
                cout << id << "\t" << n << "\t" << g << endl;
            }
            obj.close();
        }
    }
    void update(int c)
    {
        if (c == 1)
        {

            fstream newfile, oldfile;
            int snum, id;
            string name;
            char gender;

            cout << "\nEnter the serial number you wanna update : ";
            cin >> snum;

            oldfile.open("shopkeeper.txt", ios::in);
            if (!oldfile)
            {
                cout << "\nError!openeing file... " << endl;
            }
            newfile.open("edited.txt", ios::out | ios::app);
            oldfile >> id >> name >> gender;
            while (!oldfile.eof())
            {
                if (snum != id)
                    newfile << id << " " << name << " " << gender << endl;
                if (snum == id)
                {
                    cout << "\nEnter the new name : ";
                    cin >> name;
                    cout << "\nEnter the new gender: ";
                    cin >> gender;

                    newfile << id << " " << name << " " << gender << endl;
                }

                oldfile >> id >> name >> gender;
            }
            oldfile.close();
            newfile.close();
            remove("shopkeeper.txt");
            rename("edited.txt", "shopkeeper.txt");
        }
        else if (c == 2)
        {

            fstream newfile, oldfile;
            int snum, id;
            string name;

            int q;

            cout << "\nEnter the serial number you wanna update : ";
            cin >> snum;

            oldfile.open("product.txt", ios::in);
            if (!oldfile)
            {
                cout << "\nError!openeing file... " << endl;
            }
            newfile.open("edited.txt", ios::out | ios::app);
            oldfile >> id >> name >> q;
            while (!oldfile.eof())
            {
                if (snum != id)
                    newfile << id << " " << name << " " << q << endl;
                if (snum == id)
                {
                    cout << "\nEnter the new name : ";
                    cin >> name;
                    cout << "\nEnter the new quantity: ";
                    cin >> q;

                    newfile << id << " " << name << " " << q << endl;
                }

                oldfile >> id >> name >> q;
            }
            oldfile.close();
            newfile.close();
            remove("product.txt");
            rename("edited.txt", "product.txt");
        }
        else if (c == 3)
        {

            fstream newfile, oldfile;
            int snum, id;
            string name;
            char gender;

            cout << "\nEnter the serial number you wanna update : ";
            cin >> snum;

            oldfile.open("customer.txt", ios::in);
            if (!oldfile)
            {
                cout << "\nError!openeing file... " << endl;
            }
            newfile.open("edited.txt", ios::out | ios::app);
            oldfile >> id >> name >> gender;
            while (!oldfile.eof())
            {
                if (snum != id)
                    newfile << id << " " << name << " " << gender << endl;
                if (snum == id)
                {
                    cout << "\nEnter the new name : ";
                    cin >> name;
                    cout << "\nEnter the new gender: ";
                    cin >> gender;

                    newfile << id << " " << name << " " << gender << endl;
                }

                oldfile >> id >> name >> gender;
            }
            oldfile.close();
            newfile.close();
            remove("customer.txt");
            rename("edited.txt", "customer.txt");
        }
    }
    void del(int c)
    {
        if (c == 1)
        {
            fstream newfile, oldfile;
            int snum, id;
            string name;
            char gender;

            cout << "\nEnter the serial number you wanna delete : ";
            cin >> snum;

            oldfile.open("shopkeeper.txt", ios::in);
            if (!oldfile)
            {
                cout << "\nError!openeing file... " << endl;
            }
            newfile.open("edited.txt", ios::out | ios::app);
            oldfile >> id >> name >> gender;
            while (!oldfile.eof())
            {
                if (snum != id)
                {
                    newfile << id << " " << name << " " << gender << endl;
                }

                oldfile >> id >> name >> gender;
            }
            oldfile.close();
            newfile.close();
            remove("shopkeeper.txt");
            rename("edited.txt", "shopkeeper.txt");
        }
        else if (c == 2)
        {

            fstream newfile, oldfile;
            int snum, id;
            string name;
            int q;

            cout << "\nEnter the serial number you wanna delete : ";
            cin >> snum;

            oldfile.open("product.txt", ios::in);
            if (!oldfile)
            {
                cout << "\nError!openeing file... " << endl;
            }
            newfile.open("edited.txt", ios::out | ios::app);
            oldfile >> id >> name >> q;
            while (!oldfile.eof())
            {
                if (snum != id)
                {
                    newfile << id << " " << name << " " << q << endl;
                }

                oldfile >> id >> name >> q;
            }
            oldfile.close();
            newfile.close();
            remove("product.txt");
            rename("edited.txt", "product.txt");
        }
        else if (c == 3)
        {
            fstream newfile, oldfile;
            int snum, id;
            string name;
            char g;
            cout << "\nEnter the serial number you wanna delete : ";
            cin >> snum;

            oldfile.open("product.txt", ios::in);
            if (!oldfile)
            {
                cout << "\nError!openeing file... " << endl;
            }
            newfile.open("edited.txt", ios::out | ios::app);
            oldfile >> id >> name >> g;
            while (!oldfile.eof())
            {
                if (snum != id)
                {
                    newfile << id << " " << name << " " << g << endl;
                }

                oldfile >> id >> name >> g;
            }
            oldfile.close();
            newfile.close();
            remove("product.txt");
            rename("edited.txt", "product.txt");
        }
    }
};
int main()
{
    int choice, field = 1;
    IMS obj;
    do
    {
        cout << "\n-------------------------------------------\n";
        cout << "\nTo which field do you wanna perform action : ";
        cout << "\n0) None ";
        cout << "\n1) Shopkeerper . ";
        cout << "\n2) Product .";
        cout << "\n3) Customer . ";
        cout << "\n-------------------------------------------\n";
        cout << endl;
        cin >> field;
        if (field == 1)
        {
            choice = 1;
            while (choice != 0)
            {
                cout << "\n\nWhat action do you wanna perform ";
                cout << "\n0) EXIT .";
                cout << "\n1)Add new shopkepper ";
                cout << "\n2)View shopkeper detaiils ";
                cout << "\n3)Search a shopkepper details ";
                cout << "\n4)Edit a hopkeper details ";
                cout << "\n5)Delete a shopkper details";
                cout << endl;
                cin >> choice;
                switch (choice)
                {
                case 0:
                    break;
                case 1:
                    obj.insert(field);
                    break;
                case 2:
                    obj.view(field);
                    break;
                case 3:
                    obj.search(field);
                    break;
                case 4:
                    obj.update(field);
                    break;
                case 5:
                    obj.del(field);
                    break;
                default:
                    break;
                }
            }
        }
        else if (field == 2)
        {
            choice = 1;
            while (choice != 0)
            {
                cout << "\n\nWhat action do you wanna perform ";
                cout << "\n0) EXIT .";
                cout << "\n1)Add new product  ";
                cout << "\n2)View produxt  detaiils ";
                cout << "\n3)Search a product details ";
                cout << "\n4)Edit a product  details ";
                cout << "\n5)Delete a product  details";
                cout << endl;
                cin >> choice;
                switch (choice)
                {
                case 0:
                    break;
                case 1:
                    obj.insert(field);
                    break;
                case 2:
                    obj.view(field);
                    break;
                case 3:
                    obj.search(field);
                    break;
                case 4:
                    obj.update(field);
                    break;
                case 5:
                    obj.del(field);
                    break;
                default:
                    break;
                }
            }
        }
        else if (field == 3)
        {
            choice = 1;
            while (choice != 0)
            {
                cout << "\n\nWhat action do you wanna perform ";
                cout << "\n0) EXIT .";
                cout << "\n1)Add new customer  ";
                cout << "\n2)View customer  detaiils ";
                cout << "\n3)Search a customer  details ";
                cout << "\n4)Edit a customer  details ";
                cout << "\n5)Delete a customer  details";
                cout << endl;
                cin >> choice;
                switch (choice)
                {
                case 0:
                    break;
                case 1:
                    obj.insert(field);
                    break;
                case 2:
                    obj.view(field);
                    break;
                case 3:
                    obj.search(field);
                    break;
                case 4:
                    obj.update(field);
                    break;
                case 5:
                    obj.del(field);
                    break;
                default:
                    break;
                }
            }
        }

    } while (field != 0);
    exit(0);
    return 0;
}