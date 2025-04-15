#include<fstream>
 #include<iostream>
 #include<string>
 using namespace std;
 //structure for customer
 struct Customer {
 	string firstname;
 	string lastname;
    int id;
    string address;
 	string email;
 	string phoneNumber;
 };
 //structure for Room
 struct Room {
 	int roomNumber;
 	double price;
 	string roomType;
 	bool isOccupied;
 };
 //structure for employee
 struct Employee{
 	string firstname;
 	string lastname;
 	int id;
 	int age;
 	char gender;
 	string role;
 };
 //structure for food menu
 struct Food{
 	string name;
 	int price;
 };

  //function prototyping or function declaration
  void writeCustomer();
  void  manageRooms(Customer guests[], int numGuests, Room rooms[], int numRooms);
  void checkInRoom(Room rooms[], int& numRooms);
  void availableRooms(Room rooms[], int numRooms);
  void checkOutRoom(Room rooms[], int& numRooms);
  void manageEmployee();
  void orderFood(Food menu[],int numItems);
  void generateGuestSummaryReport(Customer guests[], int numGuests, Room rooms[], int numRooms);

  // Main function
 int main()
 {
 	// Example food menu items
 	int numItems = 10;
 	Food menu[20] = { {"Shiro", 70},
	                        {"Thibsi", 200},
							{"KeyWeth", 150},
							{"Dilot", 110},
							{"Pasta", 80},
							{"BeyeAynet", 85},
							{"Fata", 65},
							{"FulHaja", 60},
							{"Selith", 75},
							{"Sosi", 90}
						};


 //Example of guests data
 int numGuests = 10;
 Customer guests[20] = { {"Hluf","Gebremeskel",101,"Mekelle","hlufenticho@gmail.com","+251908834511"},
                                {"Eden","Kidane",102,"Mekelle","eden@gmail.com","+251923746435"},
                                {"Meron","Embaye",103,"Mekelle","meron@gmail.com","+251945678329"},
                                {"Filimon","Gebretsadik",104,"Mekelle","fili@gmail.com","+251904475634"},
                                {"Soliana","Menkir",105,"Mekelle","solu@gmail.com","+251984567328"},
								{"Hayelom","Takele",106,"Mekelle","hayelom@gmail.com","+251935674523"},
								{"Gedion","Aschalew",107,"Mekelle","gedion@gmail.com","+251974536856"},
								{"Yaekob","Equbamichael",108,"mekelle","yaekob@gmail","+251947387654"},
								{"Biniam","Berhe",109,"mekelle","bini@gmail.com","+251936574893"},
								{"Yared","gebremeskel",110,"mekelle","yared@gmail.com","+251943748247"}
						};

	int numRooms=10;
 Room rooms[] = { {101, 150, "single", true},
                  {102, 300, "double", true},
				  {103, 150, "single", true},
				  {104, 150, "single", true},
				  {105, 300, "double", true},
				  {106, 150, "single", true},
				  {107, 150, "single", true},
				  {108, 300, "double", true},
				  {109, 300, "double", false},
				  {110, 150, "single", false}
			};

	int choice;

	 do {
	 	cout<<"\n ###### WELCOME TO THE HOTEL MANAGEMENT SYSTEM ######"<<endl;
	 	cout<<"press 1. to Write Customer"<<endl;
	 	cout<<"press 2. to Manage Rooms"<<endl;
	 	cout<<"press 3. to Check In Room"<<endl;
	 	cout<<"press 4. to Available Rooms"<<endl;
	 	cout<<"press 5. to Check Out Room"<<endl;
	 	cout<<"press 6. to Manage employee"<<endl;
	 	cout<<"press 7. to Order Food"<<endl;
	 	cout<<"press 8. to Generate Guest Summary Report"<<endl;
	 	cout<<"press 0  to Exit the program"<<endl;
	 	cout<<"Enter your choice: ";
	 	cin>>choice;

	 	switch(choice) {
	 		case 1:
	 			writeCustomer();
	 			break;
	 		case 2:
			   manageRooms(guests, numGuests, rooms, numRooms);
			   break;
			case 3:
			   checkInRoom(rooms, numRooms);
			   break;
			case 4:
			   availableRooms(rooms, numRooms);
			   break;
			case 5:
			   checkOutRoom(rooms, numRooms);
			   break;
			case 6:
			   manageEmployee();
			   break;
			case 7:
			   orderFood(menu, numItems);
			   break;
			case 8:
			   generateGuestSummaryReport(guests, numGuests, rooms, numRooms);
			   break;
			case 0:
			      cout<<"exiting program...."<<endl;
				  break;
			default:
				  cout<<"Invalid choice. Please try again."<<endl;
				  break;
		 }
	 }

	 while(choice != 0);

	 return 0;
 }

  //function to write customer
 void writeCustomer() {
 	Customer customers[200];  //assuming the customers are 200
 	int numCustomers = 0;
 	ofstream fout;
 	fout.open("customers.txt", ios::app);
 	if (fout.fail( ))
   {
    cout << "Output file opening failed.\n";
        exit(1);
    }
 	cout<<"\n enter customer information:";
 	cout<<"\n enter customer first name: ";
 	cin>>customers[numCustomers].firstname;
 	fout<<customers[numCustomers].firstname<<endl;
 	cout<<"\n enter customer last name: ";
 	cin>>customers[numCustomers].lastname;
 	fout<<customers[numCustomers].lastname<<endl;
 	cout<<"\n enter customer ID: ";
 	cin>>customers[numCustomers].id;
 	fout<<customers[numCustomers].id<<endl;
 	cout<<"\n enter customer address: ";
 	cin>>customers[numCustomers].address;
 	fout<<customers[numCustomers].address<<endl;
 	cout<<"\n enter customer email: ";
 	cin>>customers[numCustomers].email;
 	fout<<customers[numCustomers].email<<endl;
 	cout<<"\n enter customer phonenumber: ";
 	cin>>customers[numCustomers].phoneNumber;
 	fout<<customers[numCustomers].phoneNumber<<endl;

 	numCustomers++;
 	fout.close();
 }

 //function to manage rooms
 void  manageRooms(Customer guests[], int numGuests, Room rooms[], int numRooms) {

     int roomNo;
     do{

 	cout<<"\n enter room number: ";
 	cin>>roomNo;
     for(int i=0; i<numRooms; i++){
     if(roomNo==rooms[i].roomNumber){
     cout<<rooms[i].roomNumber<<", "<<rooms[i].price<<", "<<rooms[i].roomType<<", "
     <<rooms[i].isOccupied<<endl;
     }
  }
     for(int i=0;i<numGuests;i++){
     	if(roomNo==guests[i].id && rooms[i].isOccupied){
           cout<<guests[i].firstname<<" "<<guests[i].lastname<<", "<<guests[i].id<<", "
           <<guests[i].address<<", "<<guests[i].email<<", "<<guests[i].phoneNumber<<endl;
		 }
	 }
    }
    while(roomNo!=0);
 }

 //function to check in room
 void checkInRoom(Room rooms[], int& numRooms) {
 	int roomNumber;
 	cout<<"\n enter room number to check in: ";
 	cin>>roomNumber;

 	for(int i=0; i<numRooms; i++){
 		if(rooms[i].roomNumber == roomNumber){
 			rooms[i].isOccupied = true;
 			cout<<"\n room "<<roomNumber<<" checked in successfully.";
 			return;
		 }
	 }
	 cout<<"\n room is not found.";
 }

 //function to check available rooms
 void availableRooms(Room rooms[], int numRooms) {
 	cout<<"\n available rooms: ";
 	for(int i=0; i<numRooms; i++){
 		if(!rooms[i].isOccupied){
 			cout<<"\n room number: "<<rooms[i].roomNumber<<" , type: "<<rooms[i].roomType
 			<<" , price: "<<rooms[i].price<<endl;
		 }
	 }
 }

 //function to check out room
 void checkOutRoom(Room rooms[], int& numRooms) {
 	int roomNumber;
 	cout<<"\n enter room number to check out: ";
 	cin>>roomNumber;

 	for(int i=0; i<numRooms; i++){
 		if(rooms[i].roomNumber == roomNumber){
 			rooms[i].isOccupied = false;
 			cout<<"\n room "<<roomNumber<<" checked out successfully.";
 			return;
		 }
	 }
	 cout<<"\n room is not found.";
 }

//function to manage employee
  void manageEmployee() {
  Employee employees[50]; //assuming the employees are 50.
 	int numEmployees = 0;
 	ofstream fout;
    fout.open("employees.txt", ios::app);
     if (fout.fail( ))
   {
    cout << "Output file opening failed.\n";
        exit(1);
    }
 	cout<<"\n enter employee informations: ";
 	cout<<"\n enter employee first name: ";
 	cin>>employees[numEmployees].firstname;
 	fout<<employees[numEmployees].firstname<<endl;
 	cout<<"\n enter employee last name: ";
 	cin>>employees[numEmployees].lastname;
 	fout<<employees[numEmployees].lastname<<endl;
 	cout<<"\n enter employee ID: ";
 	cin>>employees[numEmployees].id;
 	fout<<employees[numEmployees].id<<endl;
 	cout<<"\n enter employee age: ";
 	cin>>employees[numEmployees].age;
 	fout<<employees[numEmployees].age<<endl;
 	cout<<"\n enter employee gender: ";
 	cin>>employees[numEmployees].gender;
 	fout<<employees[numEmployees].gender<<endl;
 	cout<<"\n enter employee role: ";
 	cin>>employees[numEmployees].role;
    fout<<employees[numEmployees].role<<endl;
 	numEmployees++;

 	fout.close();
 }

 //function to order food
 void orderFood(Food menu[],int numItems) {
 	cout<<"\n menu of Food: ";
 	for(int i=0; i<numItems; i++){
 		cout<<i+1<<". "<<menu[i].name<<" - Birr "<<menu[i].price<<endl;
	 }
	 int choice;
	 cout<<"\n enter item number to order(0 to finish): ";
	 cin>>choice;
	 double total = 0;
	 while(choice != 0){
	 	if(choice >= 1 && choice <= numItems){
	 		total = total + menu[choice-1].price;
		 }
		 cout<<"\n enter item number to order (0 to finish): ";
		 cin>>choice;
	 }
	 cout<<"\n total amount to pay: Birr "<<total<<endl;
 }

 //function to generate guest summary report
 void generateGuestSummaryReport(Customer guests[], int numGuests, Room rooms[], int numRooms){
 	cout<<"\n guest summary report: ";
 	for(int i=0; i<numGuests; i++){
 		cout<<"\n Name: "<<guests[i].firstname<<" "<<guests[i].lastname<<", Room Number: ";
 		for(int j=0; j<numRooms; j++){
 			if(rooms[j].isOccupied && rooms[j].roomNumber == guests[i].id){
 				cout<<rooms[j].roomNumber<<endl;
 				break;
			 }
		 }
	 }
 }
 /* 
 SECTION-1
 2ND YEAR , 1ST SEMISISTER.
 SUBMMITTED TO INS: MIHRETAB
 SUBMMISSION DATE 24/09/2016.
 */
  // END OF THE PROGRAM.


