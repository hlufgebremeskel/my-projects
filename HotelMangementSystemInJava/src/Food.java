/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author cx
 */
public class Food {
    
    private String[] menuItems = {"Shiro", "Thibsi", "Keyweth", "Dulet", "Pizza", "Burger", "Sandwich", "Fata", "Fulhaja", "BeyeAynet"};
    private double[] price = {75.0, 310.0, 200.0, 170.0, 550.0, 450.0, 350.0, 80.0, 85.0, 110.0};

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


