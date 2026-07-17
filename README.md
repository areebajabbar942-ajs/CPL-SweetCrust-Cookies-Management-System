# 🍪 SweetCrust Cookies Management System
A C++ console-based Cookie Shop Management System using file handling and structures. Supports customer registration, order booking, stock management, gift box customization, and order cancellation.

## Features
- Customer Registration
- Customer Record Management
- Cookie Catalog Management
- Book Cookie Orders
- Multiple Cookies in One Order
- Gift Box Customization
- Automatic Bill Generation
- Stock Availability Checking
- Automatic Stock Update
- Search Customer Orders
- Cancel Orders
- Cancellation Fine Calculation
- File Handling
  
## File Structure

```text
Hotel-Management-System
│
├── main.cpp
│   ├── Structures
│   └── main()
│
├── customer.cpp
│   ├── WriteFor_Customers()
│   ├── ReadFrom_Customers()
│   └── Search_Customer()
│
├── rooms.cpp
│   ├── WriteFor_Rooms()
│   ├── ReadFrom_Rooms()
│   ├── search_rooms()
│   ├── updateRoom()
│   ├── cancel_room()
│   └── checkAvailability()
│
├── booking.cpp
│   ├── getDaysInMonth()
│   ├── MakeBooking()
│   ├── check_bill()
│   ├── viewbookings()
│   └── cancel_booking()
│
├── Customers.txt
├── Rooms.txt
├── Bookings.txt
└── README.md
```

## Files
Cookies.txt
Stores
- Cookie ID
- Cookie Name
- Price
- Stock

Customers.txt
Stores
- Customer Name
- CNIC
- Contact Number

Orders.txt
Stores
- Order ID
- Customer CNIC
- Cookie ID
- Quantity
- Price
- Gift Box
- Gift Charges
- Total Cost
- Status

## Project Modules

1. Add Cookies
2. Register Customer
3. View Customers
4. Book Order
5. Search Customer Orders
6. Cancel Order
7. View Cookie Catalog

## Concepts Used
- Structures
- Structure Arrays
- Dynamic Arrays
- File Handling
- Searching
- Validation
- Stock Management



