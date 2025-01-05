/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author cx
 */
import java.util.Scanner;
public class HotelMangementSystem {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Hotel hotel = new Hotel(100);
        Food food = new Food();
        Drink drink = new Drink();
        boolean exit = false;

        while (!exit) {
            displayMainMenu();
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("==== Available Rooms =====");
                    hotel.showAvailableRooms();
                    break;
                case 2:
                    bookRoomForCustomer(hotel, scanner);
                    break;
                case 3:
                    removeCustomerFromHotel(hotel, scanner);
                    break;
                case 4:
                    System.out.println("====== Customers Information======");
                    hotel.showCustomersInformation();
                    break;
                case 5:
                    addEmployeeToHotel(hotel, scanner);
                    break;
                case 6:
                    System.out.println("====== Employees Information ======");
                    hotel.showEmployeesInformation();
                    break;
                case 7:
                    orderFood(food, scanner);
                    break;
                case 8:
                    orderToDrink(drink, scanner);
                    break;
                case 0:
                    exit = true;
                    System.out.println("Exiting the system. Thank you for using the Hotel Management System.");
                    break;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }

        scanner.close();
    }

    private static void displayMainMenu() {
        System.out.println("\n================= Welcome to Hotel Management System =======================");
        System.out.println("1. Show Available Rooms");
        System.out.println("2. Book a Room");
        System.out.println("3. Remove a Customer");
        System.out.println("4. Show Customers Information");
        System.out.println("5. Add an Employee");
        System.out.println("6. Show Employees Information");
        System.out.println("7. Order Food");
        System.out.println("8. Order Drink");
        System.out.println("0. Exit");
        System.out.println("-----------------------------------");
    }

    private static void bookRoomForCustomer(Hotel hotel, Scanner scanner) {
        System.out.println("\n--- Booking a Room ---");
        System.out.print("Enter customer Id: ");
        int customerId = scanner.nextInt();
        System.out.print("Enter customer First Name: ");
        String firstName = scanner.next();
        System.out.print("Enter customer Last Name: ");
        String lastName = scanner.next();
        System.out.print("Enter customer Age: ");
        int age = scanner.nextInt();
        System.out.print("Enter customer Phone Number: ");
        String phone = scanner.next();
        System.out.print("Enter room number to book: ");
        int roomNumber = scanner.nextInt();
        Customer customer = new Customer(customerId, firstName, lastName, age, phone, roomNumber);
        hotel.bookRoom(customer);
    }

    private static void removeCustomerFromHotel(Hotel hotel, Scanner scanner) {
        System.out.println("\n--- Removing a Customer ---");
        System.out.print("Enter customer First Name: ");
        String firstName = scanner.next();
        System.out.print("Enter customer Last Name: ");
        String lastName = scanner.next();
        hotel.removeCustomer(firstName, lastName);
    }

    private static void addEmployeeToHotel(Hotel hotel, Scanner scanner) {
        System.out.println("\n--- Adding a New Employee ---");
        System.out.print("Enter employee First Name: ");
        String firstName = scanner.next();
        System.out.print("Enter employee Last Name: ");
        String lastName = scanner.next();
        System.out.print("Enter employee Gender: ");
        String gender = scanner.next();
        System.out.print("Enter employee Age: ");
        int age = scanner.nextInt();
        System.out.print("Enter job title: ");
        String jobTitle = scanner.next();
        System.out.print("Enter salary: ");
        double salary = scanner.nextDouble();
        Employee employee = new Employee(firstName, lastName, gender, age, jobTitle, salary);
        hotel.addEmployee(employee);
    }

    private static void orderFood(Food food, Scanner scanner) {
        System.out.println("==== Menu of Food =====");
        food.showMenu();
        System.out.println("Enter item number from 1 up to 10 (0 to finish) to order food");
        int item = scanner.nextInt();
        double total = 0;
        while (item != 0) {
            if (item >= 1 && item <= food.getMenuItems().length) {
                total += food.getPrice(item);
            }
            System.out.println("Enter item number from 1 up to 10 (0 to finish) to order food");
            item = scanner.nextInt();
        }
        System.out.println("Total amount to pay is: Birr " + total);
    }

    private static void orderToDrink(Drink drink, Scanner scanner) {
        System.out.println("==== Menu of Drink =====");
        drink.showMenu();
        System.out.println("Enter item number from 1 up to 10 (0 to finish) to order drink");
        int item = scanner.nextInt();
        double total = 0;
        while (item != 0) {
            if (item >= 1 && item <= drink.getMenuItems().length) {
                total += drink.getPrice(item);
            }
            System.out.println("Enter item number from 1 up to 10 (0 to finish) to order drink");
            item = scanner.nextInt();
        }
        System.out.println("Total amount to pay is: Birr " + total);
    }
}
/*
Group Members
 Name                       Id No               section
1. Hluf Gebremeskel    EITM/TUR181538/16           1
2.Eden Kidane          EITM/TUR181647/16           1
3.Tekle Beyene         UGR/170122/12               1
4. Meron Embaye        EITM/TUR181583/16           1
5.Soliana Menkir       UGR/178425/12               1
Departement  -----------Software Engineering
*/

