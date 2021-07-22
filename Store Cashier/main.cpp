#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

    string barcode[11] = {"120001","120002","120003","120004","120005","120006","120007","120008","120009","1200010"};
    string item [11] = {"Milk", "Bread", "Chocolate", "Towel", "Toothpaste", "Soap","Pen","Biscuits","Lamp","Battery"};
    double price [11] = {10.50,5.50,8.00,12.10,6.75,5.20,2.00,4.45,20.50,10.00};
    string inputBarcode;
    double total;
    double cash;
    /*
    Above I have put all my variables so that when I can use them in any area of the code below, it would not have
    a error saying that the variable was not declared. This is because the variables are all declared and read by the program first.
    */
//=================================================================================================================
/*
Below I have my first function. This function will be used for the barcode search.
I have made it so that the program starts looking from the first barcode (i=0) until i is less then the size of the array,
which holds my barcodes. I have then made it so that when a match is found the system will cout the items name and price.
in this function I have also made it so that every time that has a match will be added together to form a total price.
*/
int barcodeSearch(string array[], int size, string searchValue)
{

        for (int i = 0; i < size; i++)
        {
            if (searchValue == array[i])

                {
                cout << "The item is:'" << item[i] << "'" << endl;
                cout << "The price is:'$" << price[i] << "'" << endl;
                total = total + price[i];
                return i;
                }
        }

        return -1;
}
//====================================================================================================================
int main()
{
    string NextCustomer;

    do
    {
                string intro;
                intro = "-----------------------------------------------------\n*  WELCOME TO HERTS SUPERMARKET CHECKOUT SYSTEM     *\n* Scan the barcode or mannually type the barcode ID *\n-----------------------------------------------------";
                cout << intro << endl;

                do
                {
                    cout << "Barcode (Type 'f' to finish): ";
                    cin >> inputBarcode;
                    int result = barcodeSearch(barcode, 11, inputBarcode);    //in this section you are able to see that I have made a do while statement which allows the user

                    if (result >= 0 || inputBarcode == "f")                  //to enter barcodes and if they entered a invalid barcode then they will be presented with the error message.
                    {                                                       // this will happen until the user inputs the letter f, which then stops the loop and goes onto the next part.

                    }
                    else
                    {
                       cout << "[!] THE BARCODE '" << inputBarcode << "' WAS NOT FOUND, PLEASE TRY AGAIN. [!]" << endl;
                    }

                }while (inputBarcode != "f");
            //===================================================================================================================

                    cout << "=====================================================" << endl;

                    if (inputBarcode == "f")
                    {
                        cout << "The total price is: $" << total << endl;
                        cout << "Please enter cash amount: " << endl;
                        cin >> cash;
                    }
/*
In this section of the code I have made the loop for when the user does input f.
what happens is when f is pressed the program will stop the previous loop and cout the total price of the items
and ask for the amount of money the customer will be paying with. I have used cin to input information from the user.
*/

                do{
                   if(cash == total || cash > total)
                            {
                                cout << "change: $" << cash - total << endl;
                                cout << "*Thank you for your purchase*" << endl;
                            }

/*
In this section I have made it so that if the cash inputed by the user is equal too or more then the total price of the items,
the system should cout and calculate the change for the user. then to cout a little thank you for the purchase.
I have also made this a loop so that while the user inputs a value less then the total price then it should give a error message.
*/
                      else
                        {

                            cout << "[!] Insufficient funds [!]" << endl;
                            cout << "Please enter total cash amount: " << endl;
                            cin >> cash;
                        }
                }while(cash < total);
                if(cash > total)
                            {
                                cout << "change: $" << cash - total << endl;
                                cout << "*Thank you for your purchase*" << endl;
                            }





                //===================================================================================================================

                    cout << "=====================================================" << endl;
                    cout << "Would you like a receipt?" << endl;
                    cout << "Press y or n: " << endl;
                    string receiptOption;
                    cin >> receiptOption;
/*
In this last section I have made a receipt for the customer if they wish to have one.
they may chose yes or no if they want a receipt or not. On my receipt the user will be able to see the time and date of the purchase,
how much money was given and how much change they got back.
*/

                    if(receiptOption == "y" || receiptOption == "Y")
                    {
                        cout << "_____________________________________________________" << endl;
                        time_t now = time(0);
                        char* dt = ctime(&now);
                        string address;
                        address = "X Y Z supermarket\nLondon\nSW5 2AB\nUK";
                        string number;
                        number = "+44-0732139312";

                        cout << "Customer Receipt" << endl;
                        cout << "----------------" << endl;
                        cout << dt << endl;
                        cout << "The 'X Z Y' london store" << endl;
                        cout << "" << endl;
                        cout << "Card or Cash: " << "Cash" << endl;
                        cout << "\nTotal amount paid:.....$" << cash << endl;
                        cout << "\nChange received:.....$" << cash - total << endl;
                        cout << "\nServed by: " << "Deluar H U" << endl;
                        cout << "\nThank you for shopping at 'X Y Z' London branch." << endl;
                        cout << "\nHope you enjoy the rest of your day :)" << endl;
                        cout << "_____________________________________________________" << endl;
                    }
                    cout << "Next customer: " << endl;
                    cout << "press 'y' or 'n'" << endl;
                    cin >> NextCustomer;
                    if(NextCustomer == "n" || NextCustomer == "N")
                    {
                        cout << ":.THE END.:" << endl;
                    }
/*
The last section asks the user if they want to serve the next customer or not.
if they press yes then the whole main will loop as I put it into a do while loop.
however if they say no then the program will output a end message and the program will close.
*/

            }while(NextCustomer == "y" || NextCustomer == "Y");


}

