#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<ctype.h>
#define cls "\x1B[2J"

struct admin{
	char username[20];
	char password[15];
};
struct user{
	char username[20];
	char id[20];
	char fullname[20];
	char phonenumber[15];
	char email[15];
	char password[20];
};
struct employee{
	char name[20];
	char id[20];
	char email[15];
	float salery;
	char shift [10];
};
struct car{
	char name[20];
	char brand[20];
	float price;
	char color[15];
	char availability[15];
	char warranty[15];
	char id[15];
};
struct order{
	char name[20];
	char carid[20];
	char phone[15];
	char address[50];
	char city[30];
	int zipcode;
};
struct admin uandp={"umar","123"};
////////////////////////functions////////////////////////////////////
void header(const char *title);
void footer();
void color(int color);
void adminlogin();
void adminmenu();
void addcar();
void seecar();
void updatecar();
void deletecar();
void availablecar();
void cost();
void addemp();
void seeemp();
void delemp();
void usermenu();
void regnew();
void userlogin();
void viewuser();
void seecaruser();
void searchcar();
void order();
void vieworder();
void loaninf();
int main(){
	int num;

	
	color(7);//blue
	header("PAKISTAN CAR SHOWROOM");
	color(5);//white
printf("            Press 1 For Admin Login\n");
printf("            Press 2 For User Login\n");
printf("            Press 3 For Register New User\n");
footer();
printf("            Enter Your Choice.....\n");
footer();

scanf("%d",&num);
switch(num){
	case 1:
		adminlogin();
		break;
	case 2:
		userlogin();
		//usermenu();
		break;
	case 3:
		regnew();
		break;	
	}
	
	

	return 0;
}
/////////////////////////header////////////////////////////////////
void header(const char *title){
	printf("\n=================================================\n");
    printf("%33s\n", title);
    printf("=================================================\n");
}
/////////////////////////footer////////////////////
void footer(){
		printf("-------------------------------------------------\n");
}
/////////////////////////////color//////////////////////////////////
void color(int color){
	HANDLE Hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attribute=0;
	switch(color){
		case 1:
		attribute=FOREGROUND_RED|FOREGROUND_INTENSITY;
		break;
		case 2:
		attribute=FOREGROUND_GREEN|FOREGROUND_INTENSITY;
		break;
		case 3:
		attribute=FOREGROUND_BLUE|FOREGROUND_INTENSITY;
		break;
		case 4:
		attribute=FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
		break;
		case 5:
		attribute=FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY;//white
		break;
		case 6:
		attribute=FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
		break;
		case 7:
		attribute=FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
		break;
		default:
		attribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		break;
	}
	
	SetConsoleTextAttribute(Hconsole, attribute);
}////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////admin login////////////////////////////////////
void adminlogin(){
	while(1){
		char username[20];
		char password[20];
		system("cls");
		color(7);
		header("\tWELCOME TO ADMIN LOGIN.....");
		color(5);
		
		fflush(stdin);
		printf("\t    Enter Your UserName....\n");
		fgets(username,sizeof(username),stdin);
		username[strcspn(username,"\n")]='\0';
	for (int i = 0; username[i]; i++) {
    username[i] = tolower(username[i]);}
    	
		
		printf("\t    Enter Your Password....\n");
		fgets(password,sizeof(password),stdin);
		password[strcspn(password,"\n")]='\0';
	    for (int i = 0; password[i]; i++) {
        password[i] = tolower(password[i]);
        }
		if(strcmp(username,uandp.username)==0 && strcmp(password,uandp.password)==0){
			color(1);
			footer();
			printf("\tYour Have Successfully Login....\n");
			footer();
			color(5);
		adminmenu();
			break;
		}
		else{
			printf("kindly put correct username or password\n");
		}
	}
}
//////////////////////////////////ADMIN MENU////////////////////////////////////
void adminmenu(){
	int num;
system("cls");
color(7);
header("WELCOME TO ADMIN MENU");
color(6);
printf("            Press 1 For Add Car\n");
printf("            -------------------\n");
color(5);
printf("            Press 2 For Update Car \n");
printf("            ----------------------\n");
color(6);
printf("            Press 3 For View All Car\n");
printf("            ----------------------\n");
color(5);
printf("            Press 4 For Delete Car\n");
printf("            ---------------------\n");
color(6);
printf("            Press 5 For View All Available Cars\n");
printf("            -------------------------\n");
color(5);
printf("            Press 6 For View Cost Of All Cars\n");
printf("            -------------------------------\n");
color(6);
printf("            Press 7 For  Add Emp\n");
printf("            ------------------------------\n");
color(5);
printf("            Press 8 For View All Emp\n");
printf("            ----------------------\n");
color(6);
printf("            Press 9 For Delete Emp \n");
printf("            ----------------------\n");
color(5);
color(6);
printf("            Press 10 For for View All Users \n");
printf("            ----------------------\n");
color(5);

color(6);
printf("            Press 11 For for View Orders \n");
printf("            ----------------------\n");
color(5);
//footer();
printf("            Enter Your Choice......\n");
footer();
scanf("%d",&num);
switch(num){
	case 1:
	
		addcar();
		break;
		case 2:
			
			updatecar();
			break;
	case 3:
	
		printf("all the cars are below\n");
		seecar();
		break;
	case 4:
	
		deletecar();
		break;
	case 5:
	
	    availablecar();
	    break;
	case 6:
		cost();
		break;
	case 7:
		addemp();
		break;
	case 8:
		seeemp();
		break;
	case 9:
		delemp();
		break;
		case 10:
		viewuser();
			break;
			case 11:
		vieworder();
			break;
}
}
/////////////////////////////////////////add car//////////////////////////////////
void addcar() {
	color(7);
	header("ADD ALL THE INFORMATION....\n");
	color(5);
	char choice;
	do{
	system("cls");
	color(7);
	header("Enter Your Data");
	color(5);
	fflush(stdin);
	car cars;
	printf("Enter The Car Name.....\n");
	gets(cars.name);
	fflush(stdin);
	printf("Enter The Brand.....\n");
	gets(cars.brand);
	printf("Enter The Price.....\n");
	scanf("%f",&cars.price);
	fflush(stdin);
	printf("Enter The Color.....\n");
	gets(cars.color);
	fflush(stdin);
	printf("Enter Availability.....\n");
	gets(cars.availability);
	fflush(stdin);
	printf("Enter Warranty.....\n");
	gets(cars.warranty);
	fflush(stdin);
	printf("Enter id.....\n");
	gets(cars.id);
	fflush(stdin);
	FILE *u=fopen("data.dat","ab");
	if(u==NULL){
		printf("Unable To Open File\n");
		return;
	}
	fwrite(&cars,sizeof(cars),1,u);
	fclose(u);
	printf("Car Added");
	footer();
	
	printf("DO YOU WANT ADD ANOTHER CAR?(y/n)\n");
	fflush(stdin);
	scanf("%c",&choice);
}
while(choice=='y'||choice=='Y');

	adminmenu();
}

/////////////////////////////////////// print cars//////////////////////////////
void seecar() {
	system("cls");
	
    struct car cars; 
    FILE *u = fopen("data.dat", "rb"); 
    if (u == NULL) {
        printf("No car records found.\n");
        return;
    }
color(7);
header("ALL CARS IN SHOW ROOM...");
color(1);
printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s \n","Car Name","Brand","Price","Color","Availability","Warranty","Id");
printf("---------------------------------------------------------------------------------------------------------\n");
color(5);
    while (fread(&cars, sizeof(cars), 1, u)) {
   printf("%-15s %-15s %-15f %-15s %-15s %-15s %-15s \n",cars.name,cars.brand,cars.price,cars.color,cars.availability,cars.warranty,cars.id);
       
    }

    fclose(u); 
    color(6);
footer();
char choice;
printf("\tDO YOU WANT GO BACK ADMIN MENU....(y/n)\n");
footer();
color(5);
fflush(stdin);
scanf("%c",&choice);

if(choice=='y'||choice=='Y'){
	adminmenu();
}

}
    
    


////////////////////////////////////////////////update car///////////////////////////////
void updatecar(){
	char id[20];
	color(7);
	header("WELCOME TO UPDATATION OF CAT INFORMATION");
	color(5);
	printf("\t\tEnter Car Id....\n");
	scanf("%s",&id);
	system("cls");
	FILE *u=fopen("data.dat","rb");
	FILE *utemp=fopen("temp.dat","wb");
	if(u==NULL||utemp==NULL){
		printf("Unable To Open File....\n");
	}
	car cars; 
	int flg;
	while(fread(&cars,sizeof(cars),1,u)){
		if(strcmp(cars.id,id)==0){
		flg=1;
		fflush(stdin);
		color(7);
		footer();
		printf("\tEnter The Updated Record....\n");
		footer();
		color(5);
		fflush(stdin);
		printf("\tEnter The Car Name.....\n");
	gets(cars.name);
	fflush(stdin);
	printf("\tEnter The Brand.....\n");
	gets(cars.brand);
	fflush(stdin);
	printf("\tEnter The Price.....\n");
	scanf("%f",&cars.price);
	fflush(stdin);
	printf("\tEnter The Color.....\n");
	gets(cars.color);
	fflush(stdin);
	printf("\tEnter Availability.....\n");
	gets(cars.availability);
	fflush(stdin);
	printf("\tEnter Warranty.....\n");
	gets(cars.warranty);
	fflush(stdin);
	fwrite(&cars,sizeof(cars),1,utemp);
		}
		else{
			fwrite(&cars,sizeof(cars),1,utemp);
		}
	}
	fclose(u);
	fclose(utemp);
	remove("data.dat");
	rename("temp.dat","data.dat");
	if(flg==0){
		printf("\tNo Record Found.....\n");
	}
	else{
		color(1);
		footer();
		printf("Record Updated.....");
		footer();
		color(5);
	}
	color(6);
footer();
char choice;
printf("\tDO YOU WANT UPDATE MORE CARS....(y/n)\n");
footer();
color(5);
fflush(stdin);
scanf("%c",&choice);

if(choice=='y'||choice=='Y'){
	updatecar();
}
else{
	adminmenu();
}
}

///////////////////////////////////////////////////delete car////////////////////////////////
void deletecar(){

char id[15];
color(7);
header("\tDelete Your Car...\n");
color(5);
printf("\tEnter the Id.....\n");
scanf("%s",id);
FILE *u=fopen("data.dat","rb");
FILE*utemp=fopen("temp.dat","wb");
if(u==NULL || utemp==NULL){
	printf("\tUnable To Open File....\n");
	return;
}
car cars;
int flg=0;
while(fread(&cars,sizeof(cars),1,u)){
	if(strcmp(cars.id,id)==0){
		flg=1;
		continue;
	}
	
		fwrite(&cars,sizeof(cars),1,utemp);
	}

fclose(u);
fclose(utemp);
remove("data.dat");
rename("temp.dat","data.dat");
if(flg==1){
	printf("\trecord deleted....\n");
}
else{
	printf("record not found....\n");
}
color(6);
footer();
char choice;
printf("\tDO YOU WANT DELETE MORE CARS....(y/n)\n");
footer();
color(5);
fflush(stdin);
scanf("%c",&choice);

if(choice=='y'||choice=='Y'){
	deletecar();
}
else{
	adminmenu();
}
}
/////////////////////////////////////////////////////view available cars////////////////////////
void availablecar(){
	system("cls");
	FILE *u=fopen("data.dat","rb");
	if(u==NULL){
		printf("Unable To Open File...");
		return;
	}
	car cars;
	int availablecar=0;
	color(7);
    header("       ALL AVAILABLE CARS IN SHOWROOM...");
   color(1);
   printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s \n", "Car Name", "Brand", "Price", "Color", "Availability", "Warranty", "Id");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    color(5);
    while(fread(&cars,sizeof(cars),1,u)){
    	if(strcmp(cars.availability,"available")==0){
    		availablecar=1;
    		printf("%-15s %-15s %-15f %-15s %-15s %-15s %-15s \n", cars.name, cars.brand, cars.price, cars.color, cars.availability, cars.warranty, cars.id);
		}
	}
	if(!availablecar){
		printf("No Available Car\n");

	}

fclose(u);
}
/////////////////////////////////////////////cost of all cars/////////////////////////////
void cost(){
	system("cls");
	color(7);
	header("All Cost");
	color(5);
	float sum=0;
	
	car cars;
	FILE *u=fopen("data.dat","rb");
	if(u==NULL){
		printf("Unable To Open File...\n");
		return;
	}
	while(fread(&cars,sizeof(cars),1,u)){
		sum=sum+cars.price;
	}
	fclose(u);
	color(6);
	footer();
	printf("The Total Cost Of All Cars=%f\n",sum);
	footer();
	color(5);
	char choice;
	footer();
	color(5);
	printf("DO YOU WANT GO BACK IN ADMIN MENU(y/n)\n");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice=='y'||choice=='Y'){
		adminmenu();
	}
}
///////////////////////////add employee//////////////////////////////////////
void addemp(){
	system("cls");
	color(7);
	header("ENTER THE DATA OF EMPLYEE\n");
	color(5);
	char choice;
	employee emp;
	fflush(stdin);
	printf("\tEnter Employee Name\n");
	gets(emp.name);
	fflush(stdin);
	printf("\tEnter Employee Id\n");
	gets(emp.id);
	fflush(stdin);
	printf("\tEnter Employee Email\n ");
	gets(emp.email);
	fflush(stdin);
	printf("\tEnter Employee Salery\n ");
	scanf("%f",&emp.salery);
	fflush(stdin);
	printf("\tEnter Employee Shift\n ");
	gets(emp.shift);
	fflush(stdin);
	FILE *u=fopen("empdata.dat","ab");
	if(u==NULL){
		printf("Unable To Open File...");
	}
	fwrite(&emp,sizeof(emp),1,u);
	fclose(u);
	printf("Employee Data Added\n");
	footer();
	 printf("DO YOU WANT TO ADD ANOTHER EMPLOYEE? (y/n)\n");
        fflush(stdin);
        scanf("%c", &choice);
        if(choice=='y'||choice=='Y'){
        	addemp();
		}
		else{
			adminmenu();
		}
}
///////////////////////////////////////view all employee////////////////////////////////////////
void seeemp() {
	system("cls");
	
     employee emp; 
    FILE *u = fopen("empdata.dat", "rb"); 
    if (u == NULL) {
        printf("Unable To Open File\n");
        return;
    }
color(7);
header("ALL CARS IN SHOW ROOM...");
color(1);
printf("%-15s %-15s %-25s %-15s %-15s  \n","Emp Name","Emp Id","Emp Email","Emp Salery","Emp Shift");
printf("------------------------------------------------------------------------------------------\n");
color(5);
    while (fread(&emp, sizeof(emp), 1, u)) {
   printf("%-15s %-15s %-25s %-15f %-15s\n",emp.name,emp.id,emp.email,emp.salery,emp.shift);
       
    }

    fclose(u); 
    color(6);
footer();
char choice;
printf("\tDO YOU WANT GO BACK ADMIN MENU....(y/n)\n");
footer();
color(5);
fflush(stdin);
scanf("%c",&choice);

if(choice=='y'||choice=='Y'){
	adminmenu();
}

}
/////////////////////////////////////////////////////delete emp/////////////////////////////////////
void delemp(){
	system("cls");
	char id[20];
	int flg=0;
	color(7);
	header("Delete Your Emp.....");
	color(5);
	printf("\t     Enter Employee Id...\n");
	scanf("%s",&id);
	FILE *u=fopen("empdata.dat","rb");
	FILE *utemp=fopen("temp.dat","wb");
	if(u==NULL||utemp==NULL){
		printf("Unable To Open File....");
	}
	employee emp;
	
	while(fread(&emp,sizeof(emp),1,u)){
		if(strcmp(emp.id,id)==0){
			flg=1;
		}
		else{
			fwrite(&emp,sizeof(emp),1,utemp);
		}
	}
	fclose(u);
	fclose(utemp);
	remove("empdata.dat");
	rename("temp.dat","empdata.dat");
	if(flg==1){
		printf("record deleted\n");
		
	}
	else{
		printf("recored not found\n");
	}
	footer();
char choice;
printf("\tDO YOU WANT Try Again....(y/n)\n");
footer();
color(5);
fflush(stdin);
scanf("%c",&choice);

if(choice=='y'||choice=='Y'){
	delemp();
}
else{
	adminmenu();
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void usermenu(){
	system("cls");
	color(7);
	header("Welcome To User Login..\n");
	color(5);
	color(6);
printf("            Press 1 For View All Cars\n");
printf("            -------------------------\n");
color(5);
printf("            Press 2 For Search Car \n");
printf("            ----------------------\n");
color(6);
printf("            Press 3 For Give Order\n");
printf("            ----------------------\n");
color(5);
printf("            Press 4 For Loan Information\n");
printf("            -----------------------------\n");
color(6);
printf("            Press 5 For Search Car According to Range\n");
printf("            ------------------------------------------\n");
color(5);
printf("            Press 6 For Give Feedback\n");
printf("            ---------------------------\n");
color(6);
printf("            Press 7 For  Apply For Loan\n");
printf("            ------------------------------\n");
color(5);
printf("            Press 8 For View All Emp\n");
printf("            --------------------------\n");
color(6);
printf("            Press 9 For Delete Emp \n");
printf("            ----------------------\n");
color(5);
color(6);
printf("            Press 10 For for View All Users \n");
printf("            ----------------------------------\n");
color(5);
footer();
printf("            Enter Your Choice......\n");
footer();
int num;
scanf("%d",&num);
	switch(num){
		case 1:
			seecaruser();
			break;
		case 2:
			searchcar();
			break;
			case 3:
				order();
				break;
		case 4:
			loaninf();
			break;
	}
	
	
	
	
	
	
}
void regnew(){
	system("cls");
	color(7);
	header("        WELCOME TO REGISTRATION MENU\n");
	color(5);
	user pro;
	fflush(stdin);
	printf("\t     Enter Your FullName\n");
	gets(pro.fullname);
	fflush(stdin);
	printf("\t     Enter Your Username\n");
	gets(pro.username);
	fflush(stdin);
	printf("\t     Enter Your Id\n");
	gets(pro.id);
	fflush(stdin);
	printf("\t     Enter Your Password\n");
	gets(pro.password);
	fflush(stdin);
	printf("\t     Enter Your Email\n");
	gets(pro.email);
	fflush(stdin);
	printf("\t     Enter Your Phone Number...\n");
	gets(pro.phonenumber);
	FILE *u=fopen("users.dat","ab");
	if(u==NULL){
		printf("Unable To Open File\n");
	}
	fwrite(&pro,sizeof(pro),1,u);
	fclose(u);
	footer();
	printf("User Added\n");
	footer();
}
//////////////////////////////////////////userlogin/////////////////////////////////////////
void userlogin(){

	system("cls");
	color(7);
	header("WELCOME TO USER LOGIN");
	color(5);
	FILE *u=fopen("users.dat","rb");
	char name[20];
	char pass[20];
	fflush(stdin);
	printf("\t     Enter Your UserName\n");
	gets(name);
	for(int i=0;name[i];i++){
		name[i]=tolower(name[i]);
	}
	fflush(stdin);
	printf("\t     Enter Your Password\n");
	gets(pass);
	for(int i=0;pass[i];i++){
		pass[i]=tolower(pass[i]);
	}
	int login=0;
	user use;
	while(fread(&use,sizeof(use),1,u)){
		if(strcmp(use.username,name)==0 && strcmp(use.password,pass)==0){
			login=1;
			printf("      You Have Successfully Login\n");
			usermenu();
			break;
		}
	}
		if(!login){
			printf("Put The Correct Data\n");
		
		}
	
	fclose(u);
	}
////////////////////////////////////////admin view all users///////////////////////////////////
void viewuser(){
	system("cls");
	color(7);
	header("ALL THE USERS ARE BELOW\n");
	color(5);
	color(6);
	printf("%-15s %-15s %-15s %-15s %-25s %-15s\n","Username","Id","FullName","PhoneNumber","Email","Password");
	printf("------------------------------------------------------------------------------------------------\n");
	color(5);
	user use;
	FILE *u=fopen("users.dat","rb");
	if(u==NULL){
		printf("Unable to open file\n");
	}
	while(fread(&use,sizeof(use),1,u)){
		printf("%-15s %-15s %-15s %-15s %-25s %-15s\n",use.username,use.id,use.fullname,use.phonenumber,use.email,use.password);
}
			
	fclose(u);
	
	color(6);
	char choice;
	printf("DO YOU WANT GO BACK ADMIN MENU(y/n)\n");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice=='y'||choice=='Y'){
		adminmenu();
	}
}
/////////////////////////////////////////////////////seecaruser////////////////////
void seecaruser() {
	system("cls");
	
    struct car cars; 
    FILE *u = fopen("data.dat", "rb"); 
    if (u == NULL) {
        printf("No car records found.\n");
        return;
    }
color(7);
header("ALL CARS IN SHOW ROOM...");
color(1);
printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s \n","Car Name","Brand","Price","Color","Availability","Warranty","Id");
printf("---------------------------------------------------------------------------------------------------------\n");
color(5);
    while (fread(&cars, sizeof(cars), 1, u)) {
   printf("%-15s %-15s %-15f %-15s %-15s %-15s %-15s \n",cars.name,cars.brand,cars.price,cars.color,cars.availability,cars.warranty,cars.id);
       
    }

    fclose(u); 
    color(6);
footer();
char choice;
printf("\tDO YOU WANT GO BACK USER MENU....(y/n)\n");
footer();
color(5);
fflush(stdin);
scanf("%c",&choice);

if(choice=='y'||choice=='Y'){
	usermenu();
}

}
/////////////////////////////////////search car///////////////////////////////////
void searchcar(){
	system("cls");
	char id[20];
	car cars;
	int flg=0;
	FILE *u=fopen("data.dat","rb");
	if(u==NULL){
		printf("Unable To Open\n");
	}
	color(7);
	header("     WELCOME TO SEARCH\n");
	color(5);
	
	printf("\t      Enter The Id Of Car\n");
	fflush(stdin);
	footer();
	gets(id);
	while(fread(&cars,sizeof(cars),1,u)){
		if(strcmp(cars.id,id)==0){
			flg=1;
			system("cls");
			color(7);
	header("     WELCOME TO SEARCH\n");
	color(5);
			printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s \n","Car Name","Brand","Price","Color","Availability","Warranty","Id");
printf("------------------------------------------------------------------------------------------------------------------------\n");
 printf("%-15s %-15s %-15f %-15s %-15s %-15s %-15s \n",cars.name,cars.brand,cars.price,cars.color,cars.availability,cars.warranty,cars.id);
 break;
		}
		
		}
		if(!flg){
			color(1);
			
			printf("\t\tNO CAR WITH THIS ID FOUND!\n");
			color(5);
		}
	
	
	fclose(u);
}
////////////////////////////////////////////////////order/////////////////////////////////////////////
void order(){
	system("cls");
struct order ord;

	color(7);
	header("GIVE YOUR ORDER\n");
	color(5);
	fflush(stdin);
	printf("\t     Enter Your Name\n");
	gets(ord.name);
	fflush(stdin);
	printf("\t     Enter Car Id\n");
	gets(ord.carid);
	fflush(stdin);
		printf("\t     Enter Your Address\n");
	gets(ord.address);
	fflush(stdin);
		printf("\t     Enter Your City\n");
	gets(ord.city);
	fflush(stdin);
		printf("\t     Enter Your City ZipCode\n");
	scanf("%d",&ord.zipcode);
	fflush(stdin);
		printf("\t     Enter Your Phone\n");
	gets(ord.phone);
	fflush(stdin);
		FILE *u=fopen("order.dat","ab");
	if(u==NULL){
		printf("Unable To Open File\n");
		return;
	}
	(fwrite(&ord,sizeof(ord),1,u));
	fclose(u);
	printf("Order Submitted\n");
}
/////////////////////////////////////////////view order/////////////////////////
void vieworder(){
	system("cls");
	FILE *u=fopen("order.dat","rb");
	if(u==NULL){
		printf("Unable To Open File\n");
	}
	struct order ord;
	color(6);
	printf("%-15s %-15s %-15s %-30s %-15s %-15s\n","Name","CarId","Phone Number","Address","City","ZipCode");
	printf("----------------------------------------------------------------------------------------------------");
	color(5);
	while(fread(&ord,sizeof(ord),1,u)){
		printf("\n%-15s %-15s %-15s %-30s %-15s %-15d\n",ord.name,ord.carid,ord.phone,ord.address,ord.city,ord.zipcode);	
	}
	fclose(u);
}
/////////////////////////////////////////////loan information///////////////////////////////////////
void loaninf(){
	system("cls");
color(7);
header("\t     WELCOME TO LOAN INFORMATION\n");
color(5);
color(1);
printf("\t     WE OFFFER THREE(3) TYPES OF LOANS!\n");	       
	color(5);
	printf("")
	
}

