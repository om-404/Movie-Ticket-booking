🎬 Movie Ticket Booking System
---

📖 **Introduction**
---
This is a simple Movie Ticket Booking System implemented in C++. It allows users to browse movies, check available seats, and book tickets interactively. Booked tickets are stored in a text file (`ticket.txt`) for record-keeping.

✨ **Features**
---
- 🎥 Movie Listings with name, rating, price, director, and cast.  
- 🪑 Seat Map Display showing available (O) and booked (X) seats.  
- 🎟️ Ticket Booking with row/column seat selection.  
- 📂 Persistent Storage of tickets in a text file.  
- 📊 Track Available Seats dynamically.  
- 📋 View All Booked Tickets in a formatted way.  

🛠 **Tech Stack**
---
- **Programming Language:** C++  
- **File Handling:** Used for saving ticket details in `ticket.txt`  

📂 **Data Structures Used**
---
- `struct` → For Movie, Casting, and Ticket objects.  
- `vector` → To store movie details and booked tickets dynamically.  
- `int seats[5][ROWS][COLS]` → For managing seat booking status across screens.  

🌟 **Uniqueness**
---
- Supports multiple screens with separate seat maps.  
- Stores cast and director info along with movie details.  
- Seats are visualized like a real theater layout.  
- Data is saved to a file, ensuring ticket history persistence.  

📚 **Learning Outcomes**
---
- Improved knowledge of OOP concepts in C++.  
- Hands-on practice with vectors, arrays, and structs.  
- File handling in C++ for saving and retrieving booking info.  
- Building a menu-driven console application with real-life use case.  

🎥 **Demo & Flow**
---
1. Run the program → Menu will be displayed. <br>
![Menu Screenshot](assets/1.PNG) <br>
2. Choose an option:  
   - **Display Movies** → Shows movie list with details. <br>
![movies Screenshot](assets/2.PNG) <br>
   - **Display Seats** → View seat maps of all movies. <br>
![seats Screenshot](assets/3.PNG) <br>
   - **Book a Ticket** → Select movie → Pick a seat → Ticket gets booked.
![movie Screenshot](assets/4.PNG)   ![book Screenshot](assets/5.PNG)  ![Menu Screenshot](assets/6.PNG) <br>
   - **Display Booked Tickets** → View all past bookings.  <br>
![Menu Screenshot](assets/7.PNG) <br>
   - **Exit** → Close program.  

Tickets are automatically saved in `ticket.txt`. <br>


