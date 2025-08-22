#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

#define ROWS 5
#define COLS 10

class Casting {
public:
    string director;
    string actors;
};

class Movie {
public:
    string name;
    float rating;
    int price;
    int availableSeats;
    Casting casting;
};

class Ticket {
public:
    string movieName;
    int row;
    int col;
    char screen;
};

class TicketBookingSystem {
private:
    vector<Movie> movies;
    vector<Ticket> tickets;
    int seats[5][ROWS][COLS] = {0};

public:
    TicketBookingSystem() {
        movies = {
            {"Dunki", 7.4, 243, 5, {"Rajkumar Hirani", "Shah Rukh Khan, Taapsee Pannu"}},
            {"Salaar", 8.3, 345, 9, {"Prashanth Neel", "Prabhas, Shruti Haasan"}},
            {"Animal", 8.2, 395, 3, {"Sandeep Reddy Vanga", "Ranbir Kapoor, Rashmika Mandanna"}},
            {"12TH_FAIL", 9.6, 265, 10, {"Vidhu Chopra", "Vikrant Massey, Medha Shankr"}},
            {"HANUMAN", 9.9, 390, 8, {"Prashanth Varma", "Teja Sajja, Varalaxmi Sarathkumar"}}
        };
    }

    void displayMovies() {
        cout << "\n==================== Movie Listing ====================\n";
        cout << left << setw(20) << "Movie Name"
             << setw(10) << "Rating"
             << setw(10) << "Price"
             << setw(25) << "Director"
             << "Cast" << endl;
        cout << "-------------------------------------------------------\n";

        for (auto &m : movies) {
            cout << left << setw(20) << m.name
                 << setw(10) << fixed << setprecision(1) << m.rating
                 << setw(10) << m.price
                 << setw(25) << m.casting.director
                 << m.casting.actors << endl;
        }
    }

    void displaySeats(int movieIndex) {
        cout << "\nSeat Map for " << movies[movieIndex].name << " (Screen " 
             << char('A' + movieIndex) << ")\n";
        cout << "----------------------------------------\n";
        cout << "      R|C ";
        for (int c = 1; c <= COLS; c++) cout << c << " ";
        cout << "\n     --|-----------------------\n";

        for (int r = 0; r < ROWS; r++) {
            cout << "      " << r + 1 << "| ";
            for (int c = 0; c < COLS; c++) {
                cout << (seats[movieIndex][r][c] == 0 ? "O " : "X ");
            }
            cout << endl;
        }
    }

    void displayAllSeats() {
        for (int i = 0; i < movies.size(); i++) {
            displaySeats(i);
        }
    }

    void displayBookedTickets() {
        cout << "\n================ Booked Tickets =================\n\n";
        cout << left << setw(20) << "Movie Name"
             << setw(12) << "Row"
             << setw(12) << "Col"
             << "Screen" << endl;
        cout << "-------------------------------------------------\n";

        for (auto &t : tickets) {
            cout << left << setw(20) << t.movieName
                 << setw(12) << t.row
                 << setw(12) << t.col
                 << t.screen << endl;
        }
    }

    void bookTicket() {
        displayMovies();
        cout << "\nEnter the name of the movie you want to book: ";
        string movieName;
        cin >> movieName;

        int movieIndex = -1;
        for (int i = 0; i < movies.size(); i++) {
            if (movies[i].name == movieName) {
                movieIndex = i;
                break;
            }
        }

        if (movieIndex == -1) {
            cout << "Movie not found. Please enter a valid movie name.\n";
            return;
        }

        displaySeats(movieIndex);

        int row, col;
        cout << "\nEnter row (1-5) and column (1-10): ";
        cin >> row >> col;

        if (row < 1 || row > ROWS || col < 1 || col > COLS || seats[movieIndex][row-1][col-1] == 1) {
            cout << "Invalid or already booked seat!\n";
            return;
        }

        // Book the seat
        seats[movieIndex][row-1][col-1] = 1;
        movies[movieIndex].availableSeats--;

        // Save ticket
        Ticket t = {movies[movieIndex].name, row, col, char('A' + movieIndex)};
        tickets.push_back(t);

        cout << "Seat booked successfully!\n";

        // Write to file
        ofstream fout("ticket.txt", ios::app);
        if (fout) {
            fout << "\n================ Ticket =================\n";
            fout << "Movie: " << t.movieName << "\n";
            fout << "Row: " << t.row << "  Col: " << t.col << "\n";
            fout << "Screen: " << t.screen << "\n";
            fout << "========================================\n";
            fout.close();
        }
    }
};

int main() {
    TicketBookingSystem system;
    int choice;

    do {
        cout << "\n========== Movie Ticket Booking System ==========\n";
        cout << "1. Display Movies\n";
        cout << "2. Display Seats\n";
        cout << "3. Book a Ticket\n";
        cout << "4. Display Booked Tickets\n";
        cout << "5. Exit\n";
        cout << "===============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.displayMovies(); break;
            case 2: system.displayAllSeats(); break;
            case 3: system.bookTicket(); break;
            case 4: system.displayBookedTickets(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 5);

    return 0;
}
