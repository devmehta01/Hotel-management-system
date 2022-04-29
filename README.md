# Hotel-management-system
In this code, I have implemented a Hotel Management System.

The program first prompts the user to enter their credentials (username and password). This ensures that only employees of the hotel can access the system. This is implemented by matching the details entered with the details present in the employee details file. An added functionality allows an existing employee to add a new employees information to the file.

Once the employee successfully enters the system, they are presented with 5 functionalities:
1. Check in a new customer
2. Check out an existing customer
3. Display customer details
4. Change details
5. Display total earnings

The system has been created using a C++ class. Each record or entry consists of room number, type of room (standard or suite), cost of the room (will be calculates on the type of room chosen), number of days customer will be staying, name of the customer, and the id of the customer.

## 1. Checking in a new customer
The user is prompted to enter the number of customers and then enter the room number, type of room, number of days of stay, name of the customer, and the id of the customer. These values are written to the file.

## 2. Checking out an existing customer
2 functionalities have been given to check out a customer:
1. Checkout by the room number
2. Checkout by the customer name

The room number or the customer name is entered and matched with the data. If details do not match then 'No such room' or 'No such customer' is displayed respectively. The total cost is calculated based on the number of days and type of room booked. Cost of standard room is taken as 1000 and cost of a suite is taken as 1500.
The user is then prompted if the customer has paid or not. If payment has been done then customer is checked out, else they are asked to complete payment.

## 3. Displaying details of the stay of a customer
4 functionalities have been given to display the details:
1. Display information for all customers
2. Display details of customer with a particular name
3. Display details of customer using the room number
4. Display details of customer using their id

## 4. Changing details of a customer
2 functionalities have been provided to change details
1. Change room number of the customer
2. Change personal details of the customer

The first method also allows to change the number of days of stay of the customer.
