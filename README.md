# Auto-trader
This project is a vehicle dealership system implemented in C++. The system manages vehicles, customers, orders, and inventory, while also automating the creation of sales contracts and receipts for purchases.
 ![Class Diagram](Classsiagram.png)
 # 1. Vehicle

The Vehicle class is the base class representing a general vehicle.

It serves as the foundation for specific vehicle classes: Car, Motorcycle, and Truck.

Contains common attributes shared by all vehicles, such as brand and model.

As an abstract class, it includes virtual functions that must be implemented by the subclasses.

# 2. Car

The Car class is a subclass of Vehicle representing a car.

Contains car-specific attributes such as registration number and price.

Handles functions unique to cars, such as displaying information or updating the price.

# 3. Motorcycle

The Motorcycle class is a subclass of Vehicle representing a motorcycle.

Contains motorcycle-specific attributes such as mileage and model year.

Handles functions unique to motorcycles.

# 4. Truck

The Truck class is a subclass of Vehicle representing a truck.

Contains truck-specific attributes such as cargo capacity and weight.

Manages functions unique to trucks.

#5. Customer

The Customer class represents a customer in the system.

Stores customer information such as name, phone number, and a unique customer ID.

Maintains a list of vehicles the customer has purchased, as well as any orders associated with the customer.

Responsible for adding vehicles and orders for a customer and generating purchase contracts.

 # 6. Order

The Order class represents a purchase order made by a customer.

Contains details about the vehicle associated with the order, such as type, brand, model, and year.

Closely linked to the Customer class and keeps track of all orders made by a customer.

# 7. Stock

The Stock class manages the entire inventory of vehicles and customers.

Responsible for organizing, adding, removing, and storing vehicles, as well as managing all customer information and orders.

Handles reading and writing data to files, ensuring that system data persists between program runs.

# Program Workflow
1. On startup, the program reads all files containing information about orders, available vehicles, purchased vehicles, and customer data.
2. The main function launches a menu-driven interface within a while-loop.
3. Based on user choices, the system allows users to:

   Purchase vehicles

   Register as a customer

   Manage orders

    Search for specific vehicles
4. Upon exiting the program, all changes (new orders, purchased vehicles, etc.) are saved back to the respective files, ensuring persistence across sessions.
