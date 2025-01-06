// HOTEL MANAGEMENT SYSTEM
#include <iostream>
 #include <string>
 #include <algorithm>
 using namespace std;
 
  // Define struct 
 struct Hotel {
    int id;
    int capacity;
    string name;
    string location;
    string roomType;
    string bookingStatus;
    bool availability;
    double price;
};
  
 //protyping or declaration of functions.
 void displayMenu();
 void addHotel(Hotel hotels[], int & numHotels);
 void updateHotel(Hotel hotels[], int numHotels, int hotelID);
 void searchHotel(Hotel hotels[], int numHotels, string location);
 void deleteHotel(Hotel hotels[], int & numHotels, int hotelID);
 void sortHotels(Hotel hotels[], int numHotels);
 void manageBookings(Hotel hotels[], int numHotels, int hotelID);
  
 
  int main()
  {
  	
	  displayMenu(); //display the menu-driven program
  	  return 0;
  
  }
  // menu-driven program(function for user-friendly interface)
  void displayMenu() {
    char choice;
    int hotelID;
    string location;

    Hotel hotels[100]; // Assuming we can manage up to 100 hotels
    int numHotels = 0; 
    
    do {
        cout << "\nHotel Management System Menu\n";
        cout << "1. Add new hotel\n";
        cout << "2. Update hotel information\n";
        cout << "3. Search for hotels\n";
        cout << "4. Delete hotel\n";
        cout << "5. Sort hotels\n";
        cout << "6. Manage room bookings\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                addHotel(hotels, numHotels);
                break;
            case '2':
                cout << "Enter hotel ID to update: ";
                cin >> hotelID;
                updateHotel(hotels, numHotels, hotelID);
                break;
            case '3':
                cout << "Enter location to search: ";
                getline(cin, location);
                searchHotel(hotels, numHotels, location);
                break;
            case '4':
                cout << "Enter hotel ID to delete: ";
                cin >> hotelID;
                deleteHotel(hotels, numHotels, hotelID);
                break;
            case '5':
                sortHotels(hotels, numHotels);
                break;
            case '6':
                cout << "Enter hotel ID to manage bookings: ";
                cin >> hotelID;
                manageBookings(hotels, numHotels, hotelID);
                break;
            case '0':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != '0');
}
     // Function to add a new hotel record
 void addHotel(Hotel hotels[], int& numHotels) {
    cout << "Enter hotel details:\n";
    cout << "ID: ";
    cin >> hotels[numHotels].id;
    cout << "\nName: "; 
    getline(cin, hotels[numHotels].name);
    cout << "\nLocation: ";
    getline(cin, hotels[numHotels].location);
    cout << "\nCapacity: ";
    cin >> hotels[numHotels].capacity;
    cout << "\nAvailability (1 for available, 0 for unavailable): ";
    cin >> hotels[numHotels].availability;
    cout << "\nRoom Type: ";
    getline(cin, hotels[numHotels].roomType);
    cout << "\nPrice per night: ";
    cin >> hotels[numHotels].price;
    cout << "\nBooking Status: ";
    getline(cin, hotels[numHotels].bookingStatus);
    
    numHotels++; // Increment the count of hotels
    cout << "\nHotel added successfully!\n";
}
   // Function to update existing hotel information
 void updateHotel(Hotel hotels[], int numHotels, int hotelID) {
    bool found = false;
    for (int i = 0; i < numHotels; ++i) {
        if (hotels[i].id == hotelID) {
            found = true;
            cout << "Enter updated information for hotel " << hotelID << ":\n";
            cout << "Name: ";
            getline(cin, hotels[i].name);
            cout << "\nLocation: ";
            getline(cin, hotels[i].location);
            cout << "\nCapacity: ";
            cin >> hotels[i].capacity;
            cout << "\nAvailability (1 for available, 0 for unavailable): ";
            cin >> hotels[i].availability;
            cout << "\nRoom Type: ";
            getline(cin, hotels[i].roomType);
            cout << "\nPrice per night: ";
            cin >> hotels[i].price;
            cout << "\nBooking Status: ";
            getline(cin, hotels[i].bookingStatus);
            cout << "\nHotel information updated successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "Hotel with ID " << hotelID << " not found.\n";
    }
}
 // Function to search for hotels based on specific criteria
void searchHotel(Hotel hotels[], int numHotels, string location) {
    bool found = false;
    cout << "Hotels in " << location << ":\n";
    for (int i = 0; i < numHotels; ++i) {
        if (hotels[i].location == location) {
            found = true;
            cout << "ID: " << hotels[i].id << endl;
            cout << "Name: " << hotels[i].name << endl;
            cout << "Location: " << hotels[i].location << endl;
            cout << "Capacity: " << hotels[i].capacity << endl;
            cout << "Availability: " << (hotels[i].availability ? "Available" : "Unavailable") << endl;
            cout << "Room Type: " << hotels[i].roomType << endl;
            cout << "Price per night: " << hotels[i].price << endl;
            cout << "Booking Status: " << hotels[i].bookingStatus << endl << endl;
        }
    }
    if (!found) {
        cout << "No hotels found in " << location << ".\n";
    }
}
 // Function to delete a hotel record
void deleteHotel(Hotel hotels[], int& numHotels, int hotelID) {
    bool found = false;
    for (int i = 0; i < numHotels; ++i) {
        if (hotels[i].id == hotelID) {
            found = true;
            // Move the last hotel record to the current position to overwrite
            hotels[i] = hotels[numHotels - 1];
            numHotels--; // Decrement the count of hotels
            cout << "Hotel with ID " << hotelID << " deleted successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "Hotel with ID " << hotelID << " not found.\n";
    }
}
 // Function to sort hotels based on name
void sortHotels(Hotel hotels[], int numHotels) { 

    sort(hotels, hotels + numHotels, [](const Hotel& a, const Hotel& b) {
        return a.name < b.name;
    });
    
    cout << "Hotels sorted by name.\n";
    // Print sorted hotels
    for (int i = 0; i < numHotels; ++i) {
        cout << "ID: " << hotels[i].id << endl;
        cout << "Name: " << hotels[i].name << endl;
        cout << "Location: " << hotels[i].location << endl;
        cout << "Capacity: " << hotels[i].capacity << endl;
        cout << "Room Type: " << hotels[i].roomType << endl;
        cout << "Price per night: " << hotels[i].price << endl;
        cout << "Booking Status: " << hotels[i].bookingStatus << endl << endl;
   }
}
 // Function to manage room bookings and reservations
void manageBookings(Hotel hotels[], int numHotels, int hotelID) {
    bool found = false;
    for (int i = 0; i < numHotels; ++i) {
        if (hotels[i].id == hotelID) {
            found = true;
            char choice;
            cout << "Manage bookings for hotel " << hotelID << ":\n";
            cout << "1. Book room\n";
            cout << "2. Cancel booking\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice) {
                case '1':
                    hotels[i].availability = false; // Book the room
                    cout << "Room booked successfully!\n";
                    break;
                case '2':
                    hotels[i].availability = true; // Cancel the booking
                    cout << "Booking cancelled successfully!\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
            break;
        }
    }
    if (!found) {
        cout << "Hotel with ID " << hotelID << " not found.\n";
    }
}
  //end of the program.
