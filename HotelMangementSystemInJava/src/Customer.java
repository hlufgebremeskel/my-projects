/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author cx
 */
public class Customer {
    private int customerId;
    private String firstName;
    private String lastName;
    private int age;
    private String phoneNumber;
    private int roomNumber;

    public Customer(int customerId, String firstName, String lastName, int age, String phoneNumber, int roomNumber) {
        this.customerId = customerId;
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.phoneNumber = phoneNumber;
        this.roomNumber = roomNumber;
    }

    public String getFirstName() {
        return firstName;
    }
    public String getLastName() {
        return lastName;
    }
    public int getRoomNumber() {
        return roomNumber;
    }
    public int getAge() {
        return age;
    }
    public String getPhoneNumber() {
        return phoneNumber;
    }
    public int getCustomerId(){
        return customerId;
    }

    @Override
    public String toString() {
        return customerId + ", " + firstName + "," + lastName + "," + age + "," + phoneNumber + "," + roomNumber;
    }
}
   

