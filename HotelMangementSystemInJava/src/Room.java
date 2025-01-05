/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author cx
 */
public class Room {
    private int roomNumber;
    private String roomType;
    private boolean isOccupied;
    private double roomPrice;

    public Room(int roomNumber, String roomType, double roomPrice) {
        this.roomNumber = roomNumber;
        this.roomType = roomType;
        this.roomPrice = roomPrice;
        this.isOccupied = false;
    }

    public int getRoomNumber() {
        return roomNumber;
    }

    public String getRoomType() {
        return roomType;
    }
    
    public double getRoomPrice() {
        return roomPrice;
    }

    public boolean isOccupied() {
        return isOccupied;
    }

    public void occupyRoom() {
        isOccupied = true;
        updateRoomStatus();
    }

    public void vacateRoom() {
        isOccupied = false;
        updateRoomStatus();
    }

    @Override
    public String toString() {
        return roomNumber + "," + roomType + "," + roomPrice + "," + (isOccupied ? "Yes" : "No");
    }
   
    private void updateRoomStatus() {
        String[] roomData = FileManager.readFile("rooms.txt");
        for (int i = 0; i < roomData.length; i++) {
            if (roomData[i] != null && roomData[i].startsWith(String.valueOf(roomNumber))) {
                roomData[i] = this.toString();
                FileManager.writeFile("rooms.txt", roomData);
                return;
            }
        }
    }
}


