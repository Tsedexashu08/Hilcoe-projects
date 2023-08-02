/*
course:CS221 lab
Batch:DRB2202 section c
Group members: 1.Amanuel Fessahaye
               2.Fikir Bisrat
               3.Nahom Alemu
               4.Ruhama Kassahun
               5.Tsedalu Ashenafi
>>This program allows the user to create and estimate the cost to build multiple tables.<<
                       >>Table Estimator<<
*/
#include<iostream>
#include<stdlib.h>//for including the clearing operator.
using namespace std;
#define PI 3.14
char shapes,types;
int i,tracker=0,total_cost=0;
float discount=0,diameter,shortbase,longbase,length,width,height,area[10]={},cost[10]={};
string shape[10]={},type[10]={},first_name,last_name;


int main(){
cout<<"welcome to Wall Mart,your number one choice for tables!"<<"\n"<<"Bob-Master Builder"<<"\n";
cout<<"enter full name: ";
cin>>first_name>>last_name;
while(first_name.size()<3||last_name.size()<3){
        if(first_name.size()<3&&last_name.size()<3){
    cout<<"\t\t----------------------------------\n";
    cout<<"\t\t>>full name too short!Try again.<<\n";
    cout<<"\t\t----------------------------------";
    }else if(last_name.size()<3){
    cout<<"\t\t----------------------------------\n";
    cout<<"\t\t>>last name too short!Try again.<<\n";
    cout<<"\t\t----------------------------------";
    }else if(first_name.size()<3){
    cout<<"\t\t----------------------------------\n";
    cout<<"\t\t>>first name too short!Try again.<<\n";
    cout<<"\t\t----------------------------------";
    }
   cout<<"\n\t enter name: ";
  cin>>first_name>>last_name;
}//this loop executes if the one of the names(first or last names) entered is less than 3 characters & asks for re-entry.

for(i=0;i<10;i++){//first for loop  accepts 10 table inputs or until user chooses to exit.
cout<<"\n\t What shape of table do you wish to build?"<<"\n \t  1. Rectangular"<<"\n \t  2. Circular"<<"\n \t  3. Trapezoid"<<"\n \t  4. end program \n";
cout<<"enter menu entry: ";
    cin>>shapes;
    tracker++;//tracks number of entries
switch(shapes){
      case '1':
          length:
    cout<<"enter length of your table(in inches): ";
    cin>>length;
     if(length<0){
        cout<<"\t\t----------------------------\n";
        cout<<"\t\t>>invalid entry!Try again.<<\n";
        cout<<"\t\t----------------------------\n";
        goto length;
    }//validates if entry is positive.
    width:
    cout<<"enter width of your table(in inches): ";
    cin>>width;
    if(width<0){
        cout<<"\t\t----------------------------\n";
        cout<<"\t\t>>invalid entry!Try again.<<\n";
        cout<<"\t\t----------------------------\n";
        goto width;
    }//validates if entry is positive.
    shape[i]="Rectangular";
    area[i]=(length*width);
    cout<<"\n\t What type of material of do you want to use?\n\t 1. Laminate (12.5 Birr per square inches)\n \t 2. Oak (22.5 Birr per square inches)\n";
    cout<<"enter menu entry: ";
    cin>>types;
    break;
     case '2':
         diameter:
       cout<<"enter diameter of your circle(in inches): ";
       cin>>diameter;
        if(diameter<0){
        cout<<"\t\t----------------------------\n";
        cout<<"\t\t>>invalid entry!Try again.<<\n";
        cout<<"\t\t----------------------------\n";
        goto diameter;
    }//validates if entry is positive.
       cout<<"\n\t What type of material of do you want to use?\n\t 1. Laminate (12.5 Birr per square inches)\n \t 2. Oak (22.5 Birr per square inches)\n";
    cout<<"enter menu entry: ";
    cin>>types;
    shape[i]="circular";
        area[i]=(diameter/2)*(diameter/2)*PI;
      break;
   case '3':
       shortbase:
    cout<<"enter short base length of your table(in inches): ";
    cin>>shortbase;
    if(shortbase<0){
        cout<<"\t\t----------------------------\n";
        cout<<"\t\t>>invalid entry!Try again.<<\n";
        cout<<"\t\t----------------------------\n";
        goto shortbase;
    }//validates if entry is positive.
     longbase:
    cout<<"enter long base length of your table(in inches): ";
    cin>>longbase;
    if(longbase<0){
        cout<<"\t\t----------------------------\n";
        cout<<"\t\t>>invalid entry!Try again.<<\n";
        cout<<"\t\t----------------------------\n";
        goto longbase;
    }//validates if entry is positive.
    height:
    cout<<"enter the height of your table(in inches): ";
    cin>>height;
    if(height<0){
        cout<<"\t\t----------------------------\n";
        cout<<"\t\t>>invalid entry!Try again.<<\n";
        cout<<"\t\t----------------------------\n";
        goto height;
    }//validates if entry is positive.
    cout<<"\n\t What type of material of do you want to use?\n\t 1. Laminate (12.5 Birr per square inches)\n \t 2. Oak (22.5 Birr per square inches)\n";
    cout<<"enter menu entry: ";
    cin>>types;
    shape[i]="Trapezoidal";
    area[i]=((shortbase+longbase)/2)*height;
    break;
   case '4':
       tracker--;
       goto finish;
   default:
     i--;//decreases counter to correct number of entries.
            tracker--;
            cout<<"\t\t----------------------------\n";
            cout<<"\t\t>>invalid entry!Try again.<<\n";
            cout<<"\t\t----------------------------";
        continue;//exits and jumps to block under the "finish" label for showing output.
}//checks every case for shape type selected and assigns shape and area accordingly.
 switch(types){
     case '1':
        type[i]="Laminate";
        cost[i]=12.5*area[i];
        break;
    case '2':
        type[i]="Oak";
        cost[i]=22.5*area[i];
        break;
    default:
        cout<<"\t----------------------------------------------------------------------------\n";
            cout<<"\t\t>>invalid entry(You have entered a non-numerical character)!Try again.<<\n";
            cout<<"\t-----------------------------------------------------------------------------";
            cout<<"\n\t What type of material of do you want to use?\n\t 1. Laminate (12.5 Birr per square inches)\n \t 2. Oak (22.5 Birr per square inches)\n";
            cout<<"enter menu entry: ";
            cin>>types;

    }//assigns value for type and cost based on chosen type.
    total_cost=total_cost+cost[i];
    if(total_cost>8000)
        {
        discount=total_cost*0.05;
        }
    if(total_cost>24000){
         discount=total_cost*0.1;
        }//calculates and assigns discount value if any.
 }
finish:
    system("cls");//for clearing the screen for a cleaner output.
          cout<<"\n\t\tWall Mart Table Estimation Report\n";
          cout<<"\t\t--------------------------------\n";
          cout<<"\t\tCustomer name: "<<first_name<<" "<<last_name<<endl;
          for(i=0;i<tracker;i++){
            cout<<"\n table "<<i+1<<"\n";
           cout<<"\n\tThe area of the "<<shape[i]<<" table is "<< area[i]<<" square inches";
	cout<<"\n\tThe table will be made of "<<type[i];
	cout<<"\n\tThe cost of this table is "<< cost[i]<<" Birr\n"<<endl;
	cout<<"\t\t--------------------------------\n";
	}//displays shape type cost and what number table
	switch(tracker){
      case 0:
          system("cls");//clearing screen for cleaner output.
           cout<<"\n\t\tWall Mart Table Estimation Report\n";
		cout<<"\t\t--------------------------------";
		cout<<"\n\t\tCustomer name: "<<first_name<<" "<<last_name;
        cout<<"\n\n\tNo estimations done,Because no input was detected.";
        break;
      case 1://runs if only one input is detected.
          system("cls");
          cout<<"\n\t\tWall Mart Table Estimation Report\n";
		cout<<"\t\t--------------------------------";
		cout<<"\n\t\tCustomer name: "<<first_name<<" "<<last_name;
		cout<<"\n\n\tThe area of the "<<shape[0]<<" table is "<< area[0]<<" square inches";
	cout<<"\n\tThe table will be made of "<<type[0];
	cout<<"\n\tThe cost of this table is "<< cost[0]<<" Birr\n";
	break;
  }//runs if either no input is given or only 1 is given.
    if(tracker>1){
        cout<<"\tTotal cost of the "<<i<<" tables you estimated is: "<<total_cost<<"Birr";
    }//displays number of tables estimated if more than 1 is estimated.
    if(discount>0){
    cout<<"\n\tYour discount is "<<discount<<" Birr\n";
    total_cost=total_cost-discount;
     cout<<"\n\tYour final total is "<< total_cost<<" Birr\n";

}//displays discount if there is one.
cout<<"\n\tThank you for using the table cost estimation program!\nGoodbye!!";
return 0;
}



