//DeVon Rasch
//Search problem for charging and ID#

#include <iostream>
using namespace std;

int linearSearch(int array[], int arraySize, int value ){
    int index = 0;
    int position = -1;
    bool found = false;

    while(index < arraySize && !found){
        if (array[index] == value){
            position = index;
            found = true;
        }
        index++;
    }
    return position;
}



int main() {
    //set up the array----------------------------------------------------
    int array[18] = {5658845, 8080152,
                     1005231, 4520125,
                     4562555, 6545231,
                     7895122, 5552012,
                     3852085, 8777541,
                     5050552, 7576651,
                     8451277, 7825877,
                     7881200, 1302850,
                     1250255, 4581002};

    int x, foundIndexLS; //Give variable for value and found value-------

    cout << "Enter the ID number you want to charge: ";
    cin >> x;
    foundIndexLS = linearSearch(array, 18, x);//function call to variable

    //validation to make sure the ID was found, if not try again---------
    while(foundIndexLS == -1){
        cout << "The ID you entered is not found in the system.";
        cout << "Please enter the ID number you want to charge: ";
        cin >> x;
        foundIndexLS = linearSearch(array, 18, x);
    }
    cout << "ID# " << x << " number was found!";// Tell user ID # was found.
    return 0;
}