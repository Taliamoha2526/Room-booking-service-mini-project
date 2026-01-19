#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int Room_ID,Num_of_rooms, Num_of_customers;
double Fee, Total_fee;
// Define the calcfee function with seperate variable to avoid confusion.
double Calcfee ( int Num_of_rooms, int Num_of_customers, int Max_occupants, double Price_per_room){
        Fee= Price_per_room*Num_of_rooms;
        return Fee;
};
double Get_disc( double Fee){
    double Total_fee;
    if (Fee >= 180.00){
        Total_fee= Fee *0.95;
    }
    else{
         Total_fee= Fee;
    }
    return Total_fee;
};
int main(){
    using namespace std;
// We use multiple arrays so we can input different data types.
string Room_type[4]= {"Single Room", "Double Room", "Deluxe Room", "Suite"};
int RoomID[4]= {1, 2, 3, 4};
double RoomPrice[4]= {50, 90, 150, 250};
int MaxOccupants[4]= {1, 2, 4, 6};
cout << "    HOTEL ROOM    " << endl;
cout << "ID\t Room Type\t Price(RM)\t Max Occupants\t" << endl;
// A for loop is used to output every single element of the array and the tab is used to structure the output format.
for (int i=0; i<4; i++){
    cout << RoomID[i] <<"\t";
    cout << left<< setw(15)<< Room_type[i] << "\t";
    cout << RoomPrice[i] <<"\t\t";
    cout << MaxOccupants[i];
    cout << endl;
}
// We exit the for loop after outputting the room details and start asking the user for input.
cout << "Please enter room id." << endl;
cin >> Room_ID;
cout << "Enter number of rooms to book." << endl;
cin >> Num_of_rooms;
cout << "Enter the number of customers." << endl;
cin >> Num_of_customers;
if (Num_of_customers <= (MaxOccupants[Room_ID -1]*Num_of_rooms)){
    Fee= Calcfee(Num_of_rooms, Num_of_customers, MaxOccupants[Room_ID -1], RoomPrice[Room_ID -1]);
    Total_fee= Get_disc(Fee);
    // We use the room id to acces the index of the attributes required for the function.
    cout << "    Receipt    " << endl;
    cout << "Room Type "<< Room_type[Room_ID -1] << endl;
    cout << "Room Price (RM) "<<RoomPrice[Room_ID -1] << endl;
    cout << "Number of rooms "<<Num_of_rooms << endl;
    cout << "Number of guests "<<Num_of_customers << endl;
    cout << "Total cost "<< Fee << endl;
    cout << "Final amount " << Total_fee << endl;
    cout << "Thank you for booking! " << endl;
}
else {
     cout << "Error: Number of occupants exceeds maximum capacity. Please Try again." << endl;
    };
return 0;
}