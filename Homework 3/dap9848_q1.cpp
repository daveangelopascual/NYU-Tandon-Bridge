#include <iostream>
using namespace std;


int main() {

    float firstItem, secondItem, taxRate, basePrice, discountPrice, totalPrice;
    char clubCard;

    //User Specified Inputs
    cout << "Enter price of first item: ";
    cin >> firstItem;
    cout << "Enter price of second item: ";
    cin >> secondItem;
    cout << "Does customer have a club card? (Y/N) ";
    cin >> clubCard;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;

    //Summation of the two items prior to discount.
    basePrice = firstItem + secondItem;

    //Checks to see which item is lower priced.
    if (firstItem < secondItem)
        firstItem *= 0.50;
    else  
        secondItem *= 0.50;

    //Summation of the two items after discount.
    discountPrice = firstItem + secondItem;

    //Applying 10% discount if user is a memember.
    if ( clubCard == 'Y' || clubCard == 'y')
        discountPrice *= 0.9;
    
    //Calculation of price with tax.
    totalPrice = discountPrice * (1 + (taxRate / 100.0));

    //Displays outputs to user.
    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << discountPrice << endl;
    cout << "Total price: " << totalPrice <<endl;

    return 0;
}
