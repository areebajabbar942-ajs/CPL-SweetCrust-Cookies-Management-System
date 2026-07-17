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
├── main.cpp
│
├── Structures
│   ├── customers
│   ├── cookies
│   └── order
│
├── Customer Functions
│   ├── CheckName()
│   ├── CheckCNIC()
│   ├── CheckCNICFormat()
│   ├── CheckContact()
│   ├── CheckCustomer()
│   ├── Cus_registration()
│   └── read_customers()
│
├── Cookie Functions
│   ├── GetCookieName()
│   ├── GetCookiePrice()
│   ├── CheckCookieID()
│   ├── CheckCookieIDInput()
│   ├── CheckStock()
│   ├── Stockupdate()
│   ├── write_cookies()
│   └── read_Cookies()
│
├── Order Functions
│   ├── CheckOrderID()
│   ├── CheckOrderIDInput()
│   ├── CheckQuantity()
│   ├── CheckYN()
│   ├── customize_gift_box()
│   ├── write_Bookings()
│   ├── read_Bookings()
│   ├── BookOrder()
│   ├── searchCustomerorder()
│   └── CancelOrder()
│
├── Validation Functions
│   ├── CheckPrice()
│   ├── CheckStock(int&)
│   └── CheckChoice()
│
└── main()

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



