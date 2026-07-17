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

SweetCrust-Cookies-Management-System/
│
├── customer.cpp
│   ├── // Customer Structure
│   ├── // Validation Functions
│   │   ├── CheckName()
│   │   ├── CheckCNIC()
│   │   ├── CheckCNICFormat()
│   │   └── CheckContact()
│   ├── // Customer Functions
│   │   ├── Cus_registration()
│   │   ├── read_customers()
│   │   └── CheckCustomer()
│   └── // End of customer.cpp
│
├── cookies.cpp
│   ├── // Cookies Structure
│   ├── // Validation Functions
│   │   ├── CheckCookieID()
│   │   ├── CheckCookieIDInput()
│   │   ├── CheckPrice()
│   │   ├── CheckStock(int&)
│   │   └── CheckQuantity()
│   ├── // Cookie Functions
│   │   ├── write_cookies()
│   │   ├── read_Cookies()
│   │   ├── GetCookieName()
│   │   ├── GetCookiePrice()
│   │   ├── CheckStock(int,int)
│   │   └── Stockupdate()
│   └── // End of cookies.cpp
│
├── orders.cpp
│   ├── // Order Structure
│   ├── // Validation Functions
│   │   ├── CheckOrderID()
│   │   ├── CheckOrderIDInput()
│   │   └── CheckYN()
│   ├── // Order Functions
│   │   ├── write_Bookings()
│   │   ├── read_Bookings()
│   │   ├── customize_gift_box()
│   │   ├── BookOrder()
│   │   ├── searchCustomerorder()
│   │   └── CancelOrder()
│   └── // End of orders.cpp
│
├── main.cpp
│   ├── // Menu Validation
│   │   └── CheckChoice()
│   ├── // Main Function
│   │   └── main()
│   └── // End of main.cpp
│
└── README.md

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



