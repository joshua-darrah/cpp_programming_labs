// Hotel Management Application
// Group 20

#include <iostream>     // For input/output stream
#include <fstream>      // For file handling
#include <vector>       // To use the vector container
#include <string>       // To handle strings
using namespace std;    // Use standard namespace to avoid std:: prefix

// Room class to represent each hotel room 
class Room {
public:
    int roomNumber;           // Room number
    bool isOccupied;          // Occupancy status
    string occupantName;      // Name of the occupant

    // Constructor to initialize room with a room number
    Room(int num) : roomNumber(num), isOccupied(false), occupantName("") {}

    // Display information about the room
    void displayRoomInfo() const {
        cout << "Room " << roomNumber << " - ";
        if (isOccupied) {
            cout << "Occupied by " << occupantName << endl;
        } else {
            cout << "Available" << endl;
        }
    }
};

// Hotel class to manage multiple rooms
class Hotel {
private:
    vector<Room> rooms;               // Vector to hold all rooms
    const string filename = "hotel_data.txt"; // File to save/load room data

public:
    // Load room data from file
    void loadFromFile() {
        ifstream infile(filename);   // Open file for reading
        int roomNum;                 // Temporary variable for room number
        bool occupied;               // Temporary variable for occupancy status
        string occupant;             // Temporary variable for occupant name

        // Read file line by line: roomNum and occupied status
        while (infile >> roomNum >> occupied) {
            Room room(roomNum);                 // Create Room object
            room.isOccupied = occupied;         // Set occupancy status

            // If room is occupied, read the occupant's name
            if (occupied) infile.ignore(), getline(infile, room.occupantName);

            rooms.push_back(room);              // Add room to vector
        }

        infile.close();                         // Close the file
    }

    // Save room data to file
    void saveToFile() const {
        ofstream outfile(filename);             // Open file for writing

        // Loop through all rooms
        for (const Room& room : rooms) {
            outfile << room.roomNumber << " " << room.isOccupied;

            // If room is occupied, also write occupant name
            if (room.isOccupied) outfile << " " << room.occupantName;

            outfile << endl;                    // End line for this room
        }

        outfile.close();                         // Close the file
    }

    // Add a new room to the hotel
    void addRoom(int roomNum) {
        rooms.push_back(Room(roomNum));         // Create and add Room object
        cout << "Room " << roomNum << " added.\n";
    }

    // Remove a room from the hotel
    void removeRoom(int roomNum) {
        // Loop through rooms to find matching room number
        for (auto it = rooms.begin(); it != rooms.end(); ++it) {
            if (it->roomNumber == roomNum) {
                rooms.erase(it);                // Remove room from vector
                cout << "Room " << roomNum << " removed.\n";
                return;
            }
        }
        cout << "Room not found.\n";            // If not found, show message
    }

    // View all rooms and their status
    void viewRooms() const {
        for (const Room& room : rooms) {
            room.displayRoomInfo();             // Display room info
        }
    }

    // Assign a room to an occupant
    void assignOccupant(int roomNum, const string& name) {
        // Loop through rooms to find the target room
        for (Room& room : rooms) {
            if (room.roomNumber == roomNum && !room.isOccupied) {
                room.isOccupied = true;         // Mark as occupied
                room.occupantName = name;       // Set occupant name
                cout << "Assigned " << name << " to Room " << roomNum << ".\n";
                return;
            }
        }
        cout << "Room not available for assignment.\n"; // If room is taken or not found
    }

    // Search and display all available (unoccupied) rooms
    void searchAvailableRooms() const {
        bool found = false;                     // Flag to check if any room is available

        // Loop through rooms
        for (const Room& room : rooms) {
            if (!room.isOccupied) {             // If room is free
                cout << "Available: Room " << room.roomNumber << endl;
                found = true;
            }
        }

        if (!found) cout << "No available rooms.\n";  // If none found
    }
};

// Main function
int main() {
    Hotel hotel;                // Create Hotel object
    hotel.loadFromFile();       // Load existing data from file

    int choice;                 // Menu choice input

    // Loop until user chooses to exit
    do {
        // Display menu options
        cout << "\nHotel Management Menu\n";
        cout << "1. Search for available rooms\n";
        cout << "2. Add a new room\n";
        cout << "3. Remove a room\n";
        cout << "4. View all rooms\n";
        cout << "5. Assign room to occupant\n";
        cout << "6. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user choices
        if (choice == 1) {
            hotel.searchAvailableRooms();     // Show available rooms
        } else if (choice == 2) {
            int num;
            cout << "Enter new room number: ";
            cin >> num;
            hotel.addRoom(num);               // Add room
        } else if (choice == 3) {
            int num;
            cout << "Enter room number to remove: ";
            cin >> num;
            hotel.removeRoom(num);            // Remove room
        } else if (choice == 4) {
            hotel.viewRooms();                // View all rooms
        } else if (choice == 5) {
            int num;
            string name;
            cout << "Enter room number: ";
            cin >> num;
            cout << "Enter occupant name: ";
            cin.ignore();                     // Ignore leftover newline from cin
            getline(cin, name);               // Read full name with spaces
            hotel.assignOccupant(num, name);  // Assign occupant to room
        }

    } while (choice != 6);                     // Repeat until user exits

    hotel.saveToFile();                        // Save all room data to file
    cout << "Hotel data saved. Goodbye!\n";    
    return 0;                                  // Exit program
}
