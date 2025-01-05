/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author cx
 */
import java.io.*;
public class Hotel {
        private Room[] rooms;
    private Customer[] customers;
    private Employee[] employees;
    private int customerCount;
    private int employeeCount;

    public Hotel(int numRooms) {
        rooms = new Room[numRooms];
        customers = new Customer[100];
        employees = new Employee[100];
        customerCount = 0;
        employeeCount = 0;

        // Load existing data
        loadExistingData();

        for (int i = 0; i < numRooms; i++) {
            String roomType = (i % 3 == 0) ? "Suite" : (i % 2 == 0) ? "Double" : "Single";
            double roomPrice = (i % 3 == 0) ? 1500.0 : (i % 2 == 0) ? 850.00 : 400.0;
            rooms[i] = new Room(i + 1, roomType, roomPrice);
        }
    }

    private void loadExistingData() {
        loadCustomers();
        loadEmployees();
        loadRooms();
    }

    private void loadCustomers() {
        String[] data = FileManager.readFile("customers.txt");
        for (String line : data) { 
            if (line != null) {
                String[] parts = line.split(",");
                customers[customerCount++] = new Customer(Integer.parseInt(parts[0]), parts[1], (parts[2]), Integer.parseInt(parts[3]), parts[4], Integer.parseInt(parts[5]));
            }
        }
    }

    private void loadEmployees() {
        String[] data = FileManager.readFile("employees.txt");
        for (String line : data) {
            if (line != null) {
                String[] parts = line.split(",");
                employees[employeeCount++] = new Employee(parts[0], parts[1], parts[2], Integer.parseInt(parts[3]), parts[4], Double.parseDouble(parts[5]));
            }
        }
    }

    private void loadRooms() {
        String[] data = FileManager.readFile("rooms.txt");
        for (String line : data) {
            if (line != null) {
                String[] parts = line.split(",");
                Room room = new Room(Integer.parseInt(parts[0]), parts[1], Double.parseDouble(parts[2]));
                if (parts[3].equalsIgnoreCase("Yes")) {
                    room.occupyRoom();
                }
                rooms[Integer.parseInt(parts[0]) - 1] = room;
            }
        }
    }

    public void bookRoom(Customer customer) {
        for (Room room : rooms) {
            if (!room.isOccupied() && room.getRoomNumber() == customer.getRoomNumber()) {
                room.occupyRoom();
                customers[customerCount++] = customer;
                updateCustomerFile(customer);
                updateRoomFile(room);
                System.out.println("Room " + room.getRoomNumber() + " booked for " + customer.getFirstName() + " " + customer.getLastName());
                return;
            }
        }
        System.out.println("No available rooms.");
    }
    
    public void removeCustomer(String firstName, String lastName) {
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getFirstName().equalsIgnoreCase(firstName) && customers[i].getLastName().equalsIgnoreCase(lastName)) {
                vacateRoom(customers[i].getRoomNumber());
                customers[i] = customers[--customerCount]; // Replace removed customer with the last customer
                updateCustomerFile();
                System.out.println("Customer " + firstName + " " + lastName + " removed from the hotel.");
                return;
            }
        }
        System.out.println("Customer not found.");
    }

    private void vacateRoom(int roomNumber) {
        rooms[roomNumber - 1].vacateRoom();
        updateRoomFile(rooms[roomNumber - 1]);
    }

    private void updateCustomerFile(Customer customer) {
        String[] data = new String[customerCount];
        for (int i = 0; i < customerCount; i++) {
            data[i] = customers[i].toString();
        }
        FileManager.writeFile("customers.txt", data);
    }

    private void updateCustomerFile() {
        String[] data = new String[customerCount];
        for (int i = 0; i < customerCount; i++) {
            data[i] = customers[i].toString();
        }
        FileManager.writeFile("customers.txt", data);
    }

    private void updateRoomFile(Room room) {
        String[] data = new String[rooms.length];
        for (int i = 0; i < rooms.length; i++) { 
           data[i] = rooms[i].toString();
        }
        FileManager.writeFile("rooms.txt", data);
    }

    public void addEmployee(Employee employee) {
        employees[employeeCount++] = employee;
        updateEmployeeFile(employee);
        System.out.println("Employee " + employee.getFirstName() + " " + employee.getLastName() + " added.");
    }

    private void updateEmployeeFile(Employee employee) {
        String[] data = new String[employeeCount];
        for (int i = 0; i < employeeCount; i++) {
            data[i] = employees[i].toString();
        }
        FileManager.writeFile("employees.txt", data);
    }

    public void showCustomersInformation() {
        System.out.println("Id FName  LName    Age  PhoneNo RooomNO");
        String[] data = FileManager.readFile("customers.txt");
        for (String line : data) {
            if (line != null) {
                System.out.println(line);
            }
        }
    }

    public void showEmployeesInformation() {
        System.out.println("FName   LName    Sex   Age JobT  Salary");
        String[] data = FileManager.readFile("employees.txt");
        for (String line : data) {
            if (line != null) {
                System.out.println(line);
            }
        }
    }

    public void showAvailableRooms() {
    String[] data = FileManager.readFile("rooms.txt");
    System.out.println("Available Rooms:");
    for (String line : data) {
        if (line != null) {
            String[] parts = line.split(",");
            if (parts.length == 4 && parts[3].equalsIgnoreCase("No")) { // Check if the room is not occupied
                System.out.println("Room Number: " + parts[0] + ", Type: " + parts[1] + ", Price: " + parts[2]);
            }
        }
    }
}

}


