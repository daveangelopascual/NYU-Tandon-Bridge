#include <iostream> 
#include <string>
using namespace std;


int main() {

    float weight, height, bmi;
    string weightStatus;

    //User Specified Inputs
    cout << "Please enter a weight in pounds: ";
    cin >> weight;
    cout << "Please enter a weight in inches: ";
    cin >> height;

    //Conversions
    weight *= 0.453592;
    height *= 0.0254;


    //BMI Calculation
    bmi = weight / (height * height);

    //Determining weight status
    if (bmi < 18.5)
        weightStatus = "Underweight";

    else if (bmi >= 18.5 && bmi < 25)
        weightStatus = "Normal";

    else if (bmi >= 25 && bmi < 30)
        weightStatus = "Overweight";
        
    else
        weightStatus = "Obese";
    
    //Displays output
    cout << "The weight status is: " << weightStatus << endl;

    return 0;
}
