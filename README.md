🎬 Movie Ticket Booking System
1. 📖 Introduction

This is a simple Movie Ticket Booking System implemented in C++. It allows users to browse movies, check available seats, and book tickets interactively. Booked tickets are stored in a text file (ticket.txt) for record-keeping.

2. ✨ Features

🎥 Movie Listings with name, rating, price, director, and cast.

🪑 Seat Map Display showing available (O) and booked (X) seats.

🎟️ Ticket Booking with row/column seat selection.

📂 Persistent Storage of tickets in a text file.

📊 Track Available Seats dynamically.

📋 View All Booked Tickets in a formatted way.

3. 🛠 Tech Stack

Programming Language: C++

File Handling: Used for saving ticket details in ticket.txt

4. 📂 Data Structures Used

struct → For Movie, Casting, and Ticket objects.

vector → To store movie details and booked tickets dynamically.

3D array (int seats[5][ROWS][COLS]) → For managing seat booking status across screens.

5. 🌟 Uniqueness

Supports multiple screens with separate seat maps.

Stores cast and director info along with movie details.

Seats are visualized like a real theater layout.

Data is saved to a file, ensuring ticket history persistence.

6. 📚 Learning Outcomes

Improved knowledge of OOP concepts in C++.

Hands-on practice with vectors, arrays, and structs.

File handling in C++ for saving and retrieving booking info.

Building a menu-driven console application with real-life use case.

7. 🎥 Demo & Flow

Run the program → Menu will be displayed.

Choose an option:

1. Display Movies → Shows movie list with details.

2. Display Seats → View seat maps of all movies.

3. Book a Ticket → Select movie → Pick a seat → Ticket gets booked.

4. Display Booked Tickets → View all past bookings.

5. Exit → Close program.

Tickets are automatically saved in ticket.txt.
