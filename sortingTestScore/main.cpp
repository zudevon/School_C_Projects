//
//
//NAME : DeVon Rasch   DATE : 4/8/17
//
//--------------------------------------------------//
//  Pointer program to find average of test scores  //
//          of all students, and drop lowest        //
//--------------------------------------------------//

#include <iostream>
#include <iomanip>
using namespace std;

//FUNCTION PROTOTYPES---------------------------------//
void sortArray(int testArray[], int num, int count);  //
int getAverage(int array[], int size);                //
void dropLowest( int array[], int size );             //
//----------------------------------------------------//



int main (){
    // N is equal to 1000 so that the array size can be whatever
    // it needs to be
    const int  n = 1000;
    int students, size, ArrayScore[n];
    int *arrayptr = ArrayScore;

    //Asking the user for how many students it needs to enter scores for.
    cout << "\nEnter the number of students you want to calculate the average for : ";
    cin >> students;

    //INPUT VALIDATION for # of Students
    while (students<=0){
        cout << "\nThe Number of Students can't be smaller than zero" << endl;
        cout << "\nEnter the number of students you want to calculate the average for : ";
        cin >> students;
    }


    // This FOR loop is for each grade for each Student
    for (int count = 1; count <= students; count++){
        cout << "\nFor student #" <<(count ) << ", enter how many test scores this student has : ";
        cin >> size;

        for (int y = 0; y < size; y ++)
        {
            //Iteration for every score the student has.
            cout << "\nPlease enter value for Score #" << (y + 1);
            cin >> *(arrayptr + y);

            //Input validation for grades below ZERO
            while (*(arrayptr + y) < 0) {
                cout << "\nThe Students grade can't be smaller than zero" << endl;
                cout << "\nPlease enter value for Score #" << (y + 1);
                cin >> *(arrayptr + y);
            }


        }
        //This will show student grades in ascending order
        //LEAST to GREATEST
        sortArray(ArrayScore, size, count);

        //This will print the average score
        cout << "\n\n\n********************************************\n";
        cout << "The average of the scores for Student #" << count << " is : ";
        getAverage(ArrayScore, size);
        cout << "********************************************\n";
        //Drop Lowest grade for student
        dropLowest(ArrayScore, size);
    }

    cin >> size;


    return 0;
}


void sortArray (int array[], int size, int count){
    //Initialization of the pointer---//
    int * arrayptr = array;           //
    //--------------------------------//

    //These are for the BUBBLE sorting method//
    bool swap;                               //
    int temp;                                //
    //---------------------------------------//

    cout << "\n\n\n****************** DATA ********************\n";
    cout << "The ascending order of scores for student # "<< count << " are :" << endl;

    //BUBBLE SORT
    do{
        swap = false;
        for (int k = 0; k < (size - 1); k++){
            if (*(arrayptr + k) > *(arrayptr + (k + 1)))
            {
                temp = *(arrayptr + k);
                *(array + k) = *(array + (k + 1));
                *(array + (k + 1)) = temp;
                swap = true;
            }
        }
    }while(swap);

    //This FOR LOOP is to print all the value in
    // the array in ascending order
    for (int v=0; v < size ; v++)
    {
        cout << *(array + v) << endl;
    }
    cout << "********************************************\n";
}

int getAverage(int array[], int size){

    //Initialization of the pointer---//
    int * arrayptr = array;           //
    //--------------------------------//

    //Variables have to be set to Zero
    int total = 0, avg =0;

    for (int i=0; i < size; i++){

        //RUNNING TOTAL
        total += *(arrayptr + i);
    }

    //Calculate the average
    avg = total/(size);

    //Print out the average
    cout << "\n\n             " << avg << "%" << endl;

    return avg;
}


void dropLowest( int array[], int size ) {

    //Initialization of the pointer---//
    int * arrayptr = array;           //
    //--------------------------------//

    //Variables have to be set to Zero
    int total =0, avg =0, newSize =0;


    cout << "\n\n\n********************************************\n";
    //Preview to user what the lowest grade is.
    cout << "The lowest grade is " << *(array + 0) << endl;
    cout << "The lowest grade will be DROPPED!" << endl;

    // It is zero if the array has been sorted
    array[0] = 0;

    newSize = size -1;

    //Get the average with the lowest grade dropped
    cout << "The new average with the lowest grade dropped is : ";

    for (int i=0; i < size; i++){

        //RUNNING TOTAL
        total += *(arrayptr + i);
    }

    //Calculate the average
    avg = total/(newSize);

    //Print out the average
    cout << "\n\n             " << avg << "%" << endl;
    cout << "********************************************\n";
}