//
// DeVon Rasch
// Structure Program : Weather Statistics
//
//

#include <iostream>
using namespace std;

struct monthsStats{
    double rainfall;
    double high_temp;
    double low_temp;
    double avg_temp;
};

int main()
{
    double Jan = 0, Feb = 0, Mar = 0, Apr = 0, May = 0, Jun = 0, Jul = 0,
            Aug = 0, Sept = 0, Oct = 0, Nov = 0, Dec = 0;

    const int SIZE = 12;
    int x, y;
    double totalRainfall =0, averageRainfall =0, totalAverageTemp =0, averageTemp =0;

    // Arrays for High and Low temps
    double lows[12], highs[12];
    double highest, lowest;


    // copy monthStats to all subscripts in months
    monthsStats months[SIZE] = {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept,
                                Oct, Nov, Dec};

    for ( x = 0; x < SIZE; ++x ) {
        cout << "Enter the RAINFALL amount for month #" << (x+1) << ": ";
        cin >> months[x].rainfall;

        // Input V alidation
        while (months[x].rainfall < 0){
            cout << "Cannot have negative RAINFALL for a certain month.\n";
            cout << "Enter the RAINFALL amount for month #" << (x+1) << ": ";
            cin >> months[x].rainfall;
        }

        // Running total for Rainfall
        totalRainfall += months[x].rainfall;

        cout << "\nEnter the HIGHEST TEMP for month #" << (x+1) << ": ";
        cin >> months[x].high_temp;

        // Input Validation
        while (months[x].high_temp < (-100) || months[x].high_temp > 140){
                cout << "\nYou have entered an impossible temperature.";
                cout << "\nEnter the HIGHEST TEMP for month #" << (x+1) << ": ";
                cin >> months[x].high_temp;
        }
        highs[x] = months[x].high_temp;

        cout << "\nEnter the LOWEST TEMP for month #" << (x+1) << ": ";
        cin >> months[x].low_temp;

        // Input Validation
        while (months[x].low_temp < (-100) || months[x].low_temp > 140){
            cout << "\nYou have entered an impossible temperature.";
            cout << "\nEnter the LOWEST TEMP for month #" << (x+1) << ": ";
            cin >> months[x].low_temp;
        }
        lows[x] = months[x].low_temp;

        months[x].avg_temp = (months[x].high_temp + months[x].low_temp)/2;
        // Running total for average temps
        totalAverageTemp += months[x].avg_temp;

        cout << endl;
    }

    // Total Rainfall for the year
    cout << "\n*****The total rainfall for the year was " << totalRainfall << " inches!";

    // Average Rainfall for the year
    averageRainfall = totalRainfall/SIZE;
    cout << "\n****The avergage monthly RAINFALL for the year is " << averageRainfall << " inches!";

    // Get the average of all the averages taken from the temperatures
    averageTemp = (totalAverageTemp/SIZE);
    cout << "\n***The average TEMPERATURE for the year is " << averageTemp << " degrees.";


    // Find the highest temp for the year
    highest = highs[0];
    for (x = 1; x < SIZE; x++) {
        if (highs[x] > highest)
            highest = highs[x];
            y = x;
    }
    cout << "\n**Month #" << x << " had the HIGHEST temperature which was " <<
         highest << " degrees!" << endl;



    // Find the lowest temp of the year
    lowest = lows[0];
    for (x = 1; x < SIZE; x++) {
        if (lows[x] < lowest)
            lowest = lows[x];
            y = x;
    }
    cout << "\n*Month #" << y << " had the LOWEST temperature which was " <<
         lowest << " degrees!" << endl;

    // to pause the screen for visual studio
    cin >> y;

    return 0;

}