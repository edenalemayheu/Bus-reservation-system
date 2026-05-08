#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Ticket {
    int seatNumber;
    string passengerName;
    string busName;
    string route;
    double price;
    bool booked;
};
vector<Ticket> tickets;
void setupBus() {
    string routes[10] = {
        "Summit -> Megenagna", "Summit -> Piassa", "Summit -> Merkato",
        "Summit -> Bole", "Summit -> Legehar",
        "Ayat -> Megenagna", "Ayat -> Piassa", "Ayat -> Merkato",
        "Ayat -> Bole", "Ayat -> Legehar"
    };
    double prices[10] = {25, 35, 40, 30, 45, 20, 30, 35, 28, 40};
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= 4; j++) {
            Ticket t;
            t.seatNumber   = (i * 4) + j;
            t.passengerName = "";
            t.busName      = (i % 2 == 0 ? "Sheger Bus" : "Ambessa Bus");
            t.route        = routes[i];
            t.price        = prices[i];
            t.booked       = false;
            tickets.push_back(t);
        }
    }
}
void showRoutes() {
    cout << "\n========== AVAILABLE ROUTES ==========\n";
    for (int i = 0; i < tickets.size(); i += 4) {
        cout << "\nRoute Number : " << (i / 4) + 1 << endl;
        cout << "Bus          : " << tickets[i].busName << endl;
        cout << "Route        : " << tickets[i].route << endl;
        cout << "Price        : " << tickets[i].price << " Birr\n";
    }
}
void viewSeats() {
    cout << "\n========== SEAT STATUS ==========\n";
    for (int i = 0; i < tickets.size(); i++) {
        cout << "\nSeat Number : " << tickets[i].seatNumber << endl;
        cout << "Bus         : " << tickets[i].busName << endl;
        cout << "Route       : " << tickets[i].route << endl;
        cout << "Price       : " << tickets[i].price << " Birr" << endl;
        cout << "Status      : " << (tickets[i].booked ? "Booked" : "Available") << endl;
    }
}
void bookTicket() {
    int routeChoice, seatChoice;
    cout << "\nChoose Route Number: ";
    cin >> routeChoice;
    if (routeChoice < 1 || routeChoice > 10) {
        cout << "\nInvalid route number.\n";
        return;
    }
    cout << "\nAvailable seats for this route:\n";
    for (int i = 0; i < tickets.size(); i++) {
        if ((i / 4) + 1 == routeChoice && !tickets[i].booked) {
            cout << "Seat " << tickets[i].seatNumber << " - Available\n";
        }
    }
    cout << "\nEnter seat number: ";
    cin >> seatChoice;
    cin.ignore();
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].seatNumber == seatChoice && (i / 4) + 1 == routeChoice) {
            if (tickets[i].booked) {
                cout << "\nSeat already booked.\n";
                return;
            }
            cout << "Enter passenger name: ";
            getline(cin, tickets[i].passengerName);
            tickets[i].booked = true;
            cout << "\n========== TICKET ==========\n";
            cout << "Passenger : " << tickets[i].passengerName << endl;
            cout << "Bus       : " << tickets[i].busName << endl;
            cout << "Route     : " << tickets[i].route << endl;
            cout << "Seat No   : " << tickets[i].seatNumber << endl;
            cout << "Price     : " << tickets[i].price << " Birr\n";
            cout << "\nTicket booked successfully.\n";
            return;
        }
    }
    cout << "\nInvalid seat number.\n";
}
void cancelTicket() {
    int seat;
    cout << "\nEnter seat number to cancel: ";
    cin >> seat;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].seatNumber == seat) {
            if (!tickets[i].booked) {
                cout << "\nThis seat is not booked.\n";
            } else {
                tickets[i].booked = false;
                tickets[i].passengerName = "";
                cout << "\nTicket cancelled successfully.\n";
            }
            return;
        }
    }
    cout << "\nSeat not found.\n";
}
void bookedTickets() {
    cout << "\n========== BOOKED TICKETS ==========\n";
    bool found = false;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].booked) {
            found = true;
            cout << "\nPassenger : " << tickets[i].passengerName << endl;
            cout << "Bus       : " << tickets[i].busName << endl;
            cout << "Route     : " << tickets[i].route << endl;
            cout << "Seat No   : " << tickets[i].seatNumber << endl;
            cout << "Price     : " << tickets[i].price << " Birr\n";
        }
    }
    if (!found) cout << "\nNo booked tickets found.\n";
}
int main() {
    setupBus();
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "     ETHIOPIAN BUS RESERVATION SYSTEM\n";
        cout << "========================================\n";
        cout << "1. View Routes\n";
        cout << "2. View Seat Status\n";
        cout << "3. Book Ticket\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. View Booked Tickets\n";
        cout << "6. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: showRoutes(); break;
            case 2: viewSeats(); break;
            case 3: showRoutes(); bookTicket(); break;
            case 4: cancelTicket(); break;
            case 5: bookedTickets(); break;
            case 6: cout << "\nThank you for using the system.\n"; break;
            default: cout << "\nInvalid choice.\n";
        }
    } while(choice != 6);
    return 0;
}

