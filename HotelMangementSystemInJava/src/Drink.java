/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author cx
 */
public class Drink {
    private String[] menuItems = {"Tea", "Coffee", "Milk", "Makyato", "1L Water", "Pepsi", "Coca Cola", "Beer", "Wine", "Whiskey"}; 
    private double[] price = {5.0, 10.0, 25.0, 25.0, 30.0, 40.0, 40.0, 70.0, 1000.0, 2500.0};  

    public void showMenu() {
        for (int i = 0; i < menuItems.length; i++) {
            System.out.println(i + 1 + ". " + menuItems[i] + ": Birr " + price[i]);
        }
    }

    public String[] getMenuItems() {
        return menuItems;
    }

    public double getPrice(int choice) {
        return price[choice - 1];
    }
}
   

