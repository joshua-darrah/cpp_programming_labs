// Hotel Management Application in C++
// Group 20

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Room class to represent each hotel room
class Room {
public:
    int roomNumber;
    bool isOccupied;
    string occupantName;

    Room(int num) : roomNumber(num), isOccupied(false), occupantName("") {}

    void displayRoomInfo() const {
        cout << "Room " << roomNumber << " - ";
        if (isOccupied) {
            cout << "Occupied by " << occupantName << endl;
        } else {
            cout << "Available" << endl;
        }
    }
};

// Hotel class to manage rooms
class Hotel {
private:
    vector<Room> rooms;
    const string filename = "hotel_data.txt";

public:
    // Load rooms from file
    void loadFromFile() {
        ifstream infile(filename);
        int roomNum;
        bool occupied;
        string occupant;
        while (infile >> roomNum >> occupied) {
            Room room(roomNum);
            room.isOccupied = occupied;
            if (occupied) infile.ignore(), getline(infile, room.occupantName);
            rooms.push_back(room);
        }
        infile.close();
    }

    // Save rooms to file
    void saveToFile() const {
        ofstream outfile(filename);
        for (const Room& room : rooms) {
            outfile << room.roomNumber << " " << room.isOccupied;
            if (room.isOccupied) outfile << " " << room.occupantName;
            outfile << endl;
        }
        outfile.close();
    }

    // Add new room
    void addRoom(int roomNum) {
        rooms.push_back(Room(roomNum));
        cout << "Room " << roomNum << " added.\n";
    }

    // Remove a room
    void removeRoom(int roomNum) {
        for (auto it = rooms.begin(); it != rooms.end(); ++it) {
            if (it->roomNumber == roomNum) {
                rooms.erase(it);
                cout << "Room " << roomNum << " removed.\n";
                return;
            }
        }
        cout << "Room not found.\n";
    }

    // View all rooms
    void viewRooms() const {
        for (const Room& room : rooms) {
            room.displayRoomInfo();
        }
    }

    // Assign occupant to a room
    void assignOccupant(int roomNum, const string& name) {
        for (Room& room : rooms) {
            if (room.roomNumber == roomNum && !room.isOccupied) {
                room.isOccupied = true;
                room.occupantName = name;
                cout << "Assigned " << name << " to Room " << roomNum << ".\n";
                return;
            }
        }
        cout << "Room not available for assignment.\n";
    }

    // Search for available rooms
    void searchAvailableRooms() const {
        bool found = false;
        for (const Room& room : rooms) {
            if (!room.isOccupied) {
                cout << "Available: Room " << room.roomNumber << endl;
                found = true;
            }
        }
        if (!found) cout << "No available rooms.\n";
    }
};

int main() {
    Hotel hotel;
    hotel.loadFromFile();
    int choice;
    do {
        cout << "\nHotel Management Menu\n";
        cout << "1. Search for available rooms\n";
        cout << "2. Add a new room\n";
        cout << "3. Remove a room\n";
        cout << "4. View all rooms\n";
        cout << "5. Assign room to occupant\n";
        cout << "6. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            hotel.searchAvailableRooms();
        } else if (choice == 2) {
            int num;
            cout << "Enter new room number: ";
            cin >> num;
            hotel.addRoom(num);
        } else if (choice == 3) {
            int num;
            cout << "Enter room number to remove: ";
            cin >> num;
            hotel.removeRoom(num);
        } else if (choice == 4) {
            hotel.viewRooms();
        } else if (choice == 5) {
            int num;
            string name;
            cout << "Enter room number: ";
            cin >> num;
            cout << "Enter occupant name: ";
            cin.ignore();
            getline(cin, name);
            hotel.assignOccupant(num, name);
        }
    } while (choice != 6);

    hotel.saveToFile();
    cout << "Hotel data saved. Goodbye!\n";
    return 0;
}
