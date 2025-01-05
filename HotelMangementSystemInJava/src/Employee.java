/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author cx
 */
public class Employee {
    private String firstName;
    private String lastName;
    private String gender;
    private int age;
    private String jobTitle;
    private double salary;

    public Employee(String firstName, String lastName, String gender, int age, String jobTitle, double salary) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.gender = gender;
        this.jobTitle = jobTitle;
        this.salary = salary;
    }

    public String getFirstName() {
        return firstName;
    }
    public String getLastName() {
        return lastName;
    }
    public String getGender() {
        return gender;
    }
    public String getJobTitle() {
        return jobTitle;
    }
    public double getSalary() {
        return salary;
    }
    public int getAge(){
        return age;
    }

    @Override
    public String toString() {
        return firstName + "," + lastName + "," + gender + "," + age + "," + jobTitle + "," + salary;
    }
}


