# Hotel Management Application (C++)

A simple console-based hotel management system written in C++. This application allows hotel admins to manage rooms and guests to check for availability.

## 🔧 Features

- Guests can search for available rooms
- Admin can add and remove rooms
- Admin can view all rooms and their status
- Admin can assign occupants to rooms
- Data is saved to and loaded from a file (`hotel_data.txt`)

## 🛠 Technologies Used

- Language: C++
- File Handling: `fstream`

## 📂 File Structure

```
HotelManagement/
│
├── hotel.cpp              # Main source code
├── hotel_data.txt         # Data file for saving room info
└── README.md              # Project readme
```

## 🧾 Data Format (hotel_data.txt)
```
101 0
102 1 John Doe
103 0
```
Each line contains:
- Room Number
- Occupied (0 = No, 1 = Yes)
- Occupant Name (if occupied)

## ▶️ How to Run

1. Open terminal in the project directory.
2. Compile:
   ```bash
   g++ hotel.cpp -o hotel
   ```
3. Run:
   ```bash
   ./hotel
   ```
4. Make sure `hotel_data.txt` is in the same directory.

## 🚀 Future Enhancements

- Add login functionality for admin
- Room pricing and types
- Replace file handling with database support

## 👤 Author

**Joshua Darrah**  
BSc. Computer Engineering  
Kwame Nkrumah University of Science and Technology (KNUST)

---
Feel free to fork this project and contribute!
