#include <iostream>
using namespace std;
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <queue>
#include<stdio.h>
#include<string.h>
#include <cstdlib>

/*STRCMPI DEFINED ,FOR THOSE WHO IT DOESN'T WORK FOR.....
int strcmpi(char *s1, char *s2){
    int i,conti=1;
    for (i = 0; s1[i] && s2[i] && conti==1; ++i){
        if ( s1[i] == s2[i] || (s1[i]+32) == s2[i] || (s1[i]-32) == s2[i] )
           conti=1;
        else
           conti=0;
    }
    if (s1[i] == s2[i])
        return 0;
    return -1;
}
*/


/*STRNICMP FOR PEOPLE WHO IT DOESN'T WORK FOR
int strnicmp(char *s1, char *s2,int n){
    int i,conti=1;
    for (i = 0; s1[i] && s2[i] && conti==1 && i<n; ++i){
        if ( s1[i] == s2[i] || (s1[i]+32) == s2[i] || (s1[i]-32) == s2[i] )
           conti=1;
        else
           conti=0;
    }
    if (s1[i] == s2[i])
        return 0;
    return -1;
}
*/

class Route{
char from[30];
char to[30];
public:
    void accept();
    char* getFrom();
    char* getTo();
    void display();
};
void Route::accept(){
cout<<"\nEnter the starting city(from)"<<endl;
cin.get();
cin.getline(from,30);
cout<<"Enter the final stopping city(to)"<<endl;
cin.getline(to,30);
}
char* Route::getFrom(){
    return from;
}
char* Route::getTo(){
    return to;
}
void Route::display(){
cout<<"From : "<<from<<"To : "<<to<<endl;
}

void AddRoute(){
fstream fio("Routes.dat",ios::binary|ios::app);
Route r;
cout<<"Enter the Route"<<endl;
r.accept();
fio.write((char*)&r,sizeof(Route));
cout<<"Successfully added"<<endl;
fio.close();
}

int CheckRoute(char from[30],char to[30]){
fstream fio("Routes.dat",ios::binary|ios::in|ios::out);
Route r;int found=0;
while(fio.read((char*)&r,sizeof(Route))){
    if(strcmpi(r.getFrom(),from)==0 && strcmpi(r.getTo(),to)==0){
        found=1;
    }
}
fio.close();
return found;
}

void viewRoutes(){
fstream fio("Routes.dat",ios::binary|ios::app);
Route r;
while(fio.read((char*)&r,sizeof(Route))){
    r.display();
    cout<<endl;
    }
fio.close();
}

//-------------------------------------------------------------------------------------------------------------------------------------


class Flight{
    char fno[5];
    char fname[50];
    char from[30];
    char to[30];
    int totalseats;
    int seatbusiness;
    int seateconomy;
    int bookedeco;
    int bookedbusi;
    char ftype[20];
    char via[30];
    double fare;
    int deptime;
    int arrtime;
    int viatime;
    char fclass[20];
    long int datedep;
    long int datearr;
    long int datevia;
public:
    Flight();
    void acceptfno();
    void accept();
    void acceptchange();
    char* getfno();
    char* getVia();
    char* getTo();
    char* getFrom();
    int getseatseco();
    int getseatsbusi();
    int getbookedeco();
    int getbookedbusi();
    int getPrice();
    int getViatime();
    void setFno(char a[]);
    void setTo(char a[]);
    void setFrom(char b[]);
    void setVia(char a[]);
    void setDatedep(long int a);
    void setDatearr(long int a);
    void setDatevia(long int a);
    void setdepTime(int a);
    void setarrTime(int a);
    void setviaTime(int a);
    void setFtype(char a[]);
    void setbookedeco(int x);
    void setbookedbusi(int x);
    int getDate();
    int getStop_Date();
    char* getfType();
    void display();
};
Flight::Flight(){
fno[0]='\0';
fname[0]='\0';
from[0]='\0';
to[0]='\0';
ftype[0]='\0';
via[0]='\0';
fare=0.0;
deptime=0;
arrtime=0;
viatime=0;
fclass[0]='\0';
datedep=0;
datearr=0;
datevia=0;
totalseats=0;
seatbusiness=0;
seateconomy=0;
bookedeco=0;
bookedbusi=0;
}


void Flight::acceptfno(){
cout<<"Enter the flight number"<<endl;
cin>>fno;
while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>fno;
    }
}

void Flight :: accept(){
 int m,d,y1,y2,y3;
 cout<<"Enter the Flight name"<<endl;
 cin.get();
 cin.getline(fname,50);
 do{

    cout<<"Enter the arrival location"<<endl;
    cin.getline(to,30);
    cout<<"Enter the departure location"<<endl;
    cin.getline(from,30);

 }while(strcmp(to,from)==0);
 do{
    cout<<"Enter the classes available : Business,Economy or Both"<<endl;
    cin.getline(fclass,20);

 }while((strcmpi(fclass,"business") && strcmpi(fclass,"economy") && strcmpi(fclass,"both"))!=0);

 cout<<"Enter the flight type :(One Stop/Direct)"<<endl;
 cin.getline(ftype,20);

 if(strcmpi(ftype,"One Stop")==0){

    cout<<"Enter the stopping destination for the flight"<<endl;
    cin.getline(via,30);
    }
 do{
    do{
        cout<<"Enter the date of departure (DDMMYYYY)"<<endl;
        cin>>datedep;
        while(cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"INCORRECT INPUT-Re-Enter"<<endl;
            cin>>datedep;
        }
        m=(datedep/10000)%100;
        d=(datedep/1000000);
        y1=(datedep%10000);
        y3=y1;
    }while(m>12 || ((m==4 || m==6 || m==9 || m==11) && d>30) || (m==2 && d>28 && ((y1%4)!=0)) ||  (m==2 && d>29 && (y1%4)==0) || ((m==1||m==3||m==5||m==7||m==8||m==10||m==12) && d>31) || d==0 || m==0 );

    do{
        cout<<"Enter the date of reaching destination (DDMMYYYY)"<<endl;
        cin>>datearr;
        while(cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"INCORRECT INPUT-Re-Enter"<<endl;
            cin>>datearr;
        }
        m=(datearr/10000)%100;
        d=(datearr/1000000);
        y2=(datearr%10000);
        y3=y2;
    }while(m>12 || ((m==4 || m==6 || m==9 || m==11) && d>30) || (m==2 && d>28 && ((y2%4)!=0)) ||  (m==2 && d>29 && (y2%4)==0) || ((m==1||m==3||m==5||m==7||m==8||m==10||m==12) && d>31) || d==0 || m==0 );

     if(strcmpi(ftype,"One Stop")==0){
        do{
            cout<<"Enter the date of reaching the stopping destination(DDMMYYYY)"<<endl;
            cin>>datevia;
            while(cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"INCORRECT INPUT-Re-Enter"<<endl;
            cin>>datevia;
        }
            m=(datevia/10000)%100;
            d=(datevia/1000000);
            y3=(datevia%10000);
        }while(m>12 || ((m==4 || m==6 || m==9 || m==11) && d>30) || (m==2 && d>28 && ((y3%4)!=0)) ||  (m==2 && d>29 && (y3%4)==0) || ((m==1||m==3||m==5||m==7||m==8||m==10||m==12) && d>31) || d==0 || m==0 );
    }
 }while(y1-y2!=0 && y2-y3!=0 && y3-y1!=0);

 do{
 cout<<"Enter the Arrival time(hhmm)"<<endl;
 cin>>arrtime;
 while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>arrtime;
    }
 cout<<"Enter the Departure time(hhmm)"<<endl;
 cin>>deptime;
 while(cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"INCORRECT INPUT-Re-Enter"<<endl;
            cin>>deptime;
    }
 viatime=arrtime;
  if(strcmpi(ftype,"One Stop")==0){
            cout<<"Enter the Time of reaching the stopping destination"<<endl;
            cin>>viatime;
            while(cin.fail()){
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"INCORRECT INPUT-Re-Enter"<<endl;
                cin>>viatime;
            }
  }
 }while(((arrtime-deptime<=0 && datearr==datedep) ||(arrtime-viatime<=0 && datearr==datevia)||(viatime-deptime<=0 && datedep==datevia)|| double(arrtime)/1000.0>=2.4 || arrtime%100>=60 || deptime%100>=60 || double(deptime)/1000.0>=2.4 || viatime%100>=60 || double(viatime)/1000.0>=2.4)==1);

 cout<<"Enter the flight capacity"<<endl;
 cin>>totalseats;
 while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>totalseats;
    }
 if(strcmpi(fclass,"Both")==0){
    cout<<"Enter the seat division"<<endl;
    cout<<"Enter seats in business class"<<endl;
    cin>>seatbusiness;
    while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>seatbusiness;
    }
    bookedbusi=seatbusiness;
    seateconomy=totalseats-seatbusiness;
    bookedeco=seateconomy;
 }
 if(strcmpi(fclass,"Economy")==0){
    seateconomy=totalseats;
    bookedeco=seateconomy;
    seatbusiness=0;
    bookedbusi=0;
 }
 if(strcmpi(fclass,"business")==0){
    seatbusiness=totalseats;
    bookedbusi=seatbusiness;
    seateconomy=0;
    bookedeco=0;
 }
 cout<<"\nEnter the fare for an adult passenger in an economy flight"<<endl;
 cin>>fare;
 while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>fare;
    }

 }


void Flight::acceptchange(){
int m,d,y1,y2;
do{
    do{
        cout<<"Enter the date of departure (DDMMYYYY)"<<endl;
        cin>>datedep;
        while(cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"INCORRECT INPUT-Re-Enter"<<endl;
            cin>>datedep;
        }
        m=(datedep/10000)%100;
        d=(datedep/1000000);
        y1=(datedep%10000);
    }while(m>12 || ((m==4 || m==6 || m==9 || m==11) && d>30) || (m==2 && d>28 && ((y1%4)!=0)) ||  (m==2 && d>29 && (y1%4)==0) || ((m==1||m==3||m==5||m==7||m==8||m==10||m==12) && d>31) || d==0 || m==0 );
    do{
        cout<<"Enter the date of arrival (DDMMYYYY)"<<endl;
        cin>>datearr;
        while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>datearr;
    }
        m=(datearr/10000)%100;
        d=(datearr/1000000);
        y2=(datearr%10000);
    }while(m>12 || ((m==4 || m==6 || m==9 || m==11) && d>30) || (m==2 && d>28 && ((y2%4)!=0)) ||  (m==2 && d>29 && (y2%4)==0) || ((m==1||m==3||m==5||m==7||m==8||m==10||m==12) && d>31) || d==0 || m==0 );
}while((y1-y2)!=0);
do{
 cout<<"\nEnter the Arrival time(hhmm)"<<endl;
 cin>>arrtime;
 while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>arrtime;
    }
 cout<<"\nEnter the Departure time(hhmm)"<<endl;
 cin>>deptime;
 while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>deptime;
    }
}while(((arrtime-deptime<=0 && datearr==datedep) || double(arrtime)/1000.0>=2.4 || arrtime%100>=60 || deptime%100>=60 || double(deptime)/1000.0>=2.4)==1);
cout<<"Enter the new fare"<<endl;
cin>>fare;
while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>fare;
    }
}

char* Flight::getfno(){
    return fno;
}
char* Flight::getTo(){
    return to;
}
char* Flight::getFrom(){
    return from;
}
char* Flight::getVia(){
    return via;
}
int Flight::getDate(){
    return datedep;
}
int Flight::getStop_Date(){
    return datevia;
}
int Flight::getseatsbusi(){
    return seatbusiness;
}
int Flight::getseatseco(){
    return seateconomy;
}
int Flight::getbookedeco(){
    return bookedeco;
}
int Flight::getbookedbusi(){
    return bookedbusi;
}
int Flight::getPrice(){
    return fare;
}
char* Flight::getfType(){
    return ftype;
}
void Flight::setFrom(char a[30]){
    strcpy(from,a);
}
void Flight::setTo(char a[30]){
    strcpy(to,a);
}
void Flight::setVia(char a[30]){
    strcpy(via,a);
}
void Flight::setDatearr(long int a){
    datearr=a;
}
void Flight::setDatedep(long int a){
    datedep=a;
}
void Flight::setDatevia(long int a){
    datevia=a;
}
void Flight::setdepTime(int a){
    deptime=a;
}
void Flight::setarrTime(int a){
    arrtime=a;
}
void Flight::setviaTime(int a){
    viatime=a;
}
void Flight::setFtype(char a[10]){
    strcpy(ftype,a);
}
void Flight::setFno(char a[5]){
    strcpy(fno,a);
}
void Flight::setbookedeco(int x){
    bookedeco=x;
}
void Flight::setbookedbusi(int x){
    bookedbusi=x;
}

void Flight::display(){
    int hrs=0,minu=0;
    cout<<"\nFlight number : "<<endl<<fno<<endl<<fname<<endl<<from<<'\t'<<to<<endl<<datedep<<'\t'<<datearr<<endl<<setfill('0')<<setw(4)<<deptime<<'\t'<<setfill('0')<<setw(4)<<arrtime<<endl<<"The classes available are : "<<'\t'<<fclass;
    cout<<"\nThe Flight duration is "<<endl;
    if(datedep==datearr){
            hrs=arrtime/100-deptime/100;
            minu=arrtime%100-deptime%100;
            if(minu<0){
                hrs=hrs-1;minu=minu+60;}
            cout<<hrs<<" Hours "<<minu<<" Minutes";
    }
    else{
            hrs=arrtime/100-deptime/100;
            minu=arrtime%100-deptime%100;
            if(minu<0){
                minu=minu+60;
                hrs=hrs-1;
            }
    cout<<(((datearr/1000000)-(datedep/1000000))*24+hrs)<<" Hours "<<minu<<" Minutes";
    }
    cout<<"\nThe fare for a general ticket is : "<<endl<<fare;
    cout<<"\nThe seats available are : "<<endl;
    cout<<bookedbusi+bookedeco<<endl;
    cout<<"\n-------------------------------------------------------"<<endl;
}

void addFlight(){
 system("cls");
 char fno[5];
 cout<<"Would you like to add a flight,MR ADMIN"<<endl;
 ifstream fin("Flight.dat",ios::binary);
 ofstream fout("Flight.dat",ios::binary|ios::app);
 if(!fout || !fin)
        cout<<"No space on file"<<endl;
 else{
    Flight f,fa,fb,fc;int found=0;long int y;
    do{
    f.acceptfno();
    strcpy(fno,f.getfno());
    fin.seekg(0L,ios::end);
    y=fin.tellg();
    fin.seekg(0L);
    while(found==0 && fin.tellg()<y){
        fin.read((char*)&f,sizeof(Flight));
        if(!strcmp(f.getfno(),fno))
            found=1;
    }
    if(found==1){
        cout<<"Flight number already exists,Reenter"<<endl;
    }
    else{
    cout<<"--PLEASE ENSURE TO ADD A ROUTE BEFORE CREATING A FLIGHT--"<<endl;
    cout<<"\n**FOR CREATING A ONE STOP FLIGHT, ROUTES SHOULD EXIST FROM THE STOPPING LOCATION AS WELL**"<<endl;
     f.accept();
     if(strcmpi(f.getfType(),"Direct")==0){
        if((CheckRoute(f.getFrom(),f.getTo())==1)){
            fout.write((char*)&f,sizeof(Flight));
            cout<<"Success"<<endl;
        }
        else{
            cout<<"Route doesn't exist"<<endl;
        }
     }
    else{
        if((CheckRoute(f.getFrom(),f.getVia())==1) && (CheckRoute(f.getVia(),f.getTo())==1) && (CheckRoute(f.getFrom(),f.getTo()))==1){
            fa=f;//From Via-To
            fa.setFno(strcat(f.getfno(),"a"));
            fa.setFrom(f.getVia());
            fa.setVia('\0');
            fa.setviaTime(0);
            fa.setDatevia(0);
            fa.setFtype("Direct");
            fb=f;//From From-Via
            fb.setFno(strcat(f.getfno(),"b"));
            fb.setTo(f.getVia());
            fb.setVia('\0');
            fb.setviaTime(0);
            fb.setDatevia(0);
            fb.setFtype("Direct");
            fc=f;//From From-To
            fc.setFno(strcat(f.getfno(),"c"));
            fc.setVia('\0');
            fc.setviaTime(0);
            fc.setDatevia(0);
            fc.setFtype("Direct");
            fout.write((char*)&fa,sizeof(Flight));
            fout.write((char*)&fb,sizeof(Flight));
            fout.write((char*)&fc,sizeof(Flight));
            cout<<"Success"<<endl;
        }
        else{
            cout<<"Stopping Destination Wrong,Route doesn't exist"<<endl;
        }
    }
    }
  }while(found==1);
 }
 fin.close();
 fout.close();
}


int Search(){
    int m,d,found=0;
    char fromBook[100];
    char toBook[100];
    int datego;
    int dateret;
    cin.get();
     cout<<"Enter the Departure location"<<endl;
     cin.getline(fromBook,100);
     cout<<"\nEnter the arrival location "<<endl;
     cin.getline(toBook,100);
    do{
    cout<<"Enter the date of departure (DDMMYYYY)"<<endl;
    cin>>datego;
    m=(datego/10000)%100;
    d=(datego/1000000);
    }while(m>12 || ((m==4 || m==6 || m==9 || m==11) && d>30) || (m==2 && d>29) || ((m==1||m==3||m==5||m==7||m==8||m==10||m==12) && d>31) || d==0 || m==0 );
fstream fio("Flight.dat",ios::binary|ios::in|ios::out);
    if(!fio)
        cout<<"Error!";
    else{
    Flight f;
    fio.seekg(0L,ios::end);
    long int y=fio.tellg();
    fio.seekg(0L);
        while(fio.read((char*)&f,sizeof(Flight))){
            if((strcmpi(f.getTo(),toBook)==0 && strcmpi(f.getFrom(),fromBook)==0 && datego==f.getDate()) || (strcmpi(f.getVia(),fromBook)==0
            && strcmpi(f.getTo(),toBook)==0 && datego==f.getStop_Date()) || (strcmpi(f.getVia(),toBook)==0 && strcmpi(f.getFrom(),fromBook)==0 && datego==f.getDate()) ){
                f.display();
                found=1;
            }
        }
    }
    fio.close();
    return found;
}
//--------------------------------------------------------------------------------------------

class Person{
int uno;
char fno[5];
int age;
int seatno;
char gender;
char name[50];
char date[100];
char classe[20];
int status;
double fare;
public:
    Person(){
        fno[0]='\0';
        uno=0;
        seatno=0;
        age=0;
        gender='N';
        name[0]='\0';
        classe[0]='\0';
        date[0]='\0';
        fare=0.0;
        status=0;   /* STATUS: 0-Canceled;
                               1-Confirmed;
                               2-Waiting List
                               3-Flight Canceled
                               4-Flight Modified
    */}
    void accept(char fno[5],int uno);
    void display();
    char* getDate(){
        return date;
    }
    void setseatno(int x){
        seatno=x;
    }
    int getseatno(){
        return seatno;
    }
    char getGender(){
        return gender;
    }
    int getUno(){
        return uno;
    }
    char* getFno(){
        return fno;
    }
    char* getclass(){
        return classe;
    }
    int getAge(){
        return age;
    }
    void setstatus(int x){
        status=x;
    }
    void setDate(char a[100]){
        strcpy(date,a);
    }
    int getStatus(){
        return status;
    }
    char* getName(){
        return name;
    }
    void setfare(double x){
        fare=x;
    }
    double getFare(){
        return fare;
    }
};

void Person::accept(char x[5],int y){
strcpy(fno,x);
uno=y;
cout<<"Enter the name : "<<endl;
cin.get();
cin.getline(name,50);
do{
    cout<<"Enter the gender : "<<endl;
    cin>>gender;

}while(((gender!='m')||(gender!='f')||(gender!='F')||(gender!='M'))==0);
cout<<"Enter the age : "<<endl;
cin>>age;
while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>age;
}
cout<<"Enter the choice of class : "<<endl;
cin.get();
cin.getline(classe,20);
time_t now=time(0);
strcpy(date,ctime(&now));
cout<<"\n--------------------"<<endl;
}


void Person::display(){
cout<<"\nThe name of the person is : ";
cout<<name;
cout<<"\nThe Flight in which seat has been booked : ";
cout<<fno;
cout<<"\nThe gender is : ";
cout<<gender;
cout<<"\nThe age is : ";
cout<<age<<endl;
cout<<"The Seat Number is : "<<endl;
cout<<seatno<<endl;
cout<<"Choice of class"<<endl;
cout<<classe<<endl;
cout<<"Ticket STATUS : "<<endl;
if(status==0)
    cout<<"CANCELLED"<<endl;
else if(status==1)
    cout<<"CONFIRMED"<<endl;
else if(status==2)
    cout<<"WAITING LIST"<<endl;
else if(status==3)
    cout<<"YOUR FLIGHT HAS BEEN CANCELLED,SORRY FOR THE INCONVENIENCE"<<endl;
else if(status==4)
    cout<<"CHANGES HAVE BEEN MADE TO YOUR FLIGHT,SORRY FOR THE INCONVENIENCE"<<endl;
else if(status==5)
    cout<<"FLIGHT TRIP COMPLETED"<<endl;
else;
cout<<"\n-------------------------------------"<<endl;
}


queue<Person> cancel1;
queue<Person> bill;


void Billing(){
double total=0.0;
double tax=0.0;
double discount=0.0;
double fare;
Person p;
int qsize=bill.size();
cout<<"Generating Bill......."<<endl;
Sleep(500);
cout<<"----------------------------------------"<<endl;
for(int i=0;i<qsize;i++){
    p=bill.front();
    fare=p.getFare();
    bill.pop();
    toupper(p.getName()[0]);
    toupper(p.getGender());
    toupper(p.getclass()[0]);
    total=total+p.getFare();
    cout<<"Name : "<<'\t'<<"Gender : "<<'\t'<<"Age : "<<'\t'<<"Flight Number : "<<'\t'<<"Class Chosen"<<'\t'<<"Ticket Price : "<<endl<<"Discount : "<<endl;
    cout<<p.getName()<<'\t'<<p.getGender()<<'\t'<<p.getAge()<<'\t'<<p.getFno()<<'\t'<<p.getclass()<<'\t'<<p.getFare()<<endl<<discount<<endl;
    cout<<"---------------------------"<<endl;
    }
tax=total*0.18;
cout<<"TRAVEL FARE : "<<endl<<total<<" Rs."<<endl;
cout<<"TAX APPLICABLE(18%) : "<<tax<<" Rs."<<endl;
cout<<"TOTAL : "<<tax+total<<" Rs."<<endl;
cout<<"--------------------------------"<<endl<<endl<<endl;
}

int Bookchoose(int uno,int num){
    char fno[5];
    int found=0,ecotot,busitot,eco,busi,total,ret=0,no,canceleco=0,cancelbusi=0,x=0,seatno;
    long int y;
    Flight f;
    double fare;
    Person p,p1;
    char pro='y',opt;
    fstream fio("Flight.dat",ios::binary|ios::in|ios::out);
    fstream fgo("Report.dat",ios::binary|ios::in|ios::out);
    if(!fio || !fgo ){
        cout<<"Error!"<<endl;
        ret=0;
        }
    else{
        fio.seekg(0L,ios::end);
        y=fio.tellg();
        fio.seekg(0L);
        if(!fio.read((char*)&f,sizeof(f))){
            cout<<"Invalid!"<<endl;
            ret=0;
        }
        else{
        if(Search()==0){
            cout<<"No Flight found"<<endl;
            ret=0;
        }
        else{
        cout<<"From the above list,Enter the flight's number you want to book"<<endl;
        cin>>fno;
        fio.seekg(0L);
        while((fio.tellg()<y && fio.tellg()>=0) && found==0){
            fio.read((char*)&f,sizeof(f));
            if(!strcmp(f.getfno(),fno)){
                found=1;
            }
        }
        if(found==0){
            cout<<"Invalid Operation"<<endl;
            ret=0;
        }
        else{
            f.display();
            cout<<"\nIs this the Flight you want to book? (Y/N)"<<endl;
            ecotot=f.getseatseco();
            busitot=f.getseatsbusi();
            eco=f.getbookedeco();
            busi=f.getbookedbusi();
            fgo.seekg(0L,ios::end);
            y=fgo.tellg();
            fgo.seekg(0L);
            while((fgo.tellg()<y && fgo.tellg()>=0)){
                fgo.read((char*)&p,sizeof(Person));
                if(p.getStatus()==0 && strcmpi(p.getclass(),"Business")==0)
                    ++cancelbusi;
                else if(p.getStatus()==0 && strcmpi(p.getclass(),"Economy")==0)
                    ++canceleco;
                else;
            }
            total=eco+busi+cancelbusi+canceleco;
            cout<<"Seats available are : "<<total<<endl;
            cin>>opt;
            if(opt!='Y' && opt!='y')
                    ret=0;
            else{
                fare=f.getPrice();
                cout<<"Fare for an adult passenger on the flight is : "<<endl<<fare;
                if(num==0){
                    cout<<"\nEnter the number of seats wanted(max-5)"<<endl;
                    do{
                        cin>>no;
                    }while(no>5);
                }
                else{
                    no=num;
                }
                    Person a[no],p;
                    system("cls");
                    cout<<"Please Enter the passengers details"<<endl;
                    for(int i=0;i<no &&( pro=='y'|| pro=='Y');){
                      cout<<"Passenger : "<<i+1<<endl;
                      a[i].accept(fno,uno);
                      if(a[i].getAge()>=65){
                            a[i].setfare(fare*0.5);
                      }
                      else if(a[i].getAge()<=6 && a[i].getAge()>=2){
                        a[i].setfare(fare*0.1);
                      }
                      else
                        a[i].setfare(fare);
                      if(strcmpi(a[i].getclass(),"business")==0)
                        a[i].setfare(a[i].getFare()*3.6);
                      a[i].setstatus(2);
                      cancel1.push(a[i]);
                      bill.push(a[i]);
                      if(strcmpi(a[i].getclass(),"Economy")==0){
                        x=0;
                        if(ecotot==0){
                            cout<<"\nSorry this flight does not have Economy class"<<endl;
                            cancel1.pop();
                            bill.pop();
                            cout<<"Do you want to proceed (Y/N)? "<<endl;
                            cin>>pro;
                        }
                        else if(eco>0 && canceleco==0){
                            p=cancel1.front();
                            p.setseatno(ecotot-eco+1);
                            p.setstatus(1);
                            cancel1.pop();
                            fgo.seekg(0L,ios::end);
                            fgo.write((char*)&p,sizeof(Person));
                            eco=eco-1;
                            f.setbookedeco(eco);
                            i++;
                            cout<<"Do you want to proceed (Y/N)? "<<endl;
                            cin>>pro;
                        }
                        else if(canceleco>0){
                            i++;
                            p=cancel1.front();
                            cancel1.pop();
                            fgo.seekg(0L,ios::end);
                            y=fgo.tellg();
                            fgo.seekg(0L);
                            while((fgo.tellg()<y && fgo.tellg()>=0) && found==0){
                                fgo.read((char*)&p1,sizeof(Person));
                                if(p1.getStatus()==0 && !strcmp(p1.getFno(),p.getFno()) && p.getclass()==p1.getclass()){
                                    found=1;
                                }
                            }
                            if(found==1){
                                seatno=p1.getseatno();
                                fgo.seekp((long)-sizeof(Person));
                                p.setstatus(1);
                                p.setseatno(seatno);
                                fgo.write((char*)&p,sizeof(Person));
                            }
                            else{
                                fgo.seekg(0L,ios::end);
                                fgo.write((char*)&p,sizeof(Person));
                                eco=eco-1;
                                f.setbookedeco(eco);
                                i++;
                                cout<<"Do you want to proceed (Y/N)? "<<endl;
                                cin>>pro;
                            }
                            cout<<"Do you want to proceed (Y/N)? "<<endl;
                            cin>>pro;
                        }
                        else{
                            i++;
                            cout<<"\nSeats full ,We have put you on the waiting list"<<endl;
                            cout<<"Do you want to proceed (Y/N)? "<<endl;
                            cin>>pro;
                        }
                      }
                      else if(strcmpi(a[i].getclass(),"Business")==0){
                        x=0;
                        if(busitot==0){
                            cout<<"\nSorry Business class is unavailable on this flight"<<endl;
                            cancel1.pop();
                            bill.pop();
                            cout<<"Do you want to proceed (Y/N)? "<<endl;
                            cin>>pro;
                        }
                        else if(busi>0 && cancelbusi==0){
                            p=cancel1.front();
                            p.setseatno(busitot-busi+1);
                            p.setstatus(1);
                            cancel1.pop();
                            fgo.write((char*)&p,sizeof(Person));
                            busi=busi-1;
                            f.setbookedbusi(busi);
                            i++;
                            cout<<"Do you want to proceed (Y/N)? "<<endl;
                            cin>>pro;
                        }
                        else if(cancelbusi>0){
                            i++;
                            p=cancel1.front();
                            cancel1.pop();
                            fgo.seekg(0L,ios::end);
                            y=fgo.tellg();
                            fgo.seekg(0L);
                            while((fgo.tellg()<y && fgo.tellg()>=0) && found==0){
                                fgo.read((char*)&p1,sizeof(Person));
                                if(p1.getStatus()==0 && !strcmp(p1.getFno(),p.getFno()) && p.getclass()==p1.getclass()){
                                    found=1;
                                }
                            }
                            if(found==1){
                                seatno=p1.getseatno();
                                fgo.seekp((long)-sizeof(Person));
                                p.setseatno(seatno);
                                p.setstatus(1);
                                fgo.write((char*)&p,sizeof(Person));
                            }
                            else{
                                fgo.seekg(0L,ios::end);
                                fgo.write((char*)&p,sizeof(Person));
                                busi=busi-1;
                                f.setbookedbusi(busi);
                                i++;
                                cout<<"Do you want to proceed (Y/N)? "<<endl;
                                cin>>pro;
                            }
                            cout<<"Do you want to proceed (Y/N)? "<<endl;
                            cin>>pro;
                        }
                        else{
                            i++;
                            cout<<"\nSeats full ,We have put you on the waiting list"<<endl;
                            cout<<"Do you want to proceed (Y/N)? "<<endl;
                            cin>>pro;
                        }
                      }
                    else{
                    cancel1.pop();
                    bill.pop();
                    cout<<"Invalid Class entered"<<endl;
                    x=1;
                    }
                }
                if(num==0 && x!=1)
                    Billing();
                fio.seekp((long)-sizeof(Flight),ios::cur);
                fio.write((char*)&f,sizeof(f));
                ret=1;
                }
            }
        }
    }
}
    fio.close();
    fgo.close();
    return ret;
}

int BookCancel(int uno){
    long int y;char fno[5];int seatno;char name[50],classe[20];int cancel=0,found=0;Person p,p1;int qsize=0;Flight f;int ret=0;
    fstream fio("Report.dat",ios::binary|ios::in|ios::out);
if(!fio){
    cout<<"Error opening file"<<endl;
    ret=0;
    }
else{
    if(!fio.read((char*)&p,sizeof(Person))){
       cout<<"Error,File Empty!"<<endl;
       ret=0;
    }
    else{
        fio.seekg(0L,ios::end);
        y=fio.tellg();
        fio.seekg(0L);
        while(fio.tellg()<y){
        fio.read((char*)&p,sizeof(Person));
            if(p.getUno()==uno)
                p.display();
                found=1;
            }
        if(!found){
            cout<<"Booking history Empty"<<endl;
            ret=0;
        }
        else{
            found=0;
            fio.seekg(0L);
            cout<<"\nWhich ticket would you like to cancel"<<endl;
            cout<<"Enter flight number"<<endl;
            cin>>fno;
            while(cin.fail()){
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"INCORRECT INPUT-Re-Enter"<<endl;
                cin>>fno;
            }
            cout<<"Enter the person's name"<<endl;
            cin.get();
            cin.getline(name,50);
            cout<<"Enter the Seat number"<<endl;
            cin>>seatno;
            while(cin.fail()){
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"INCORRECT INPUT-Re-Enter"<<endl;
                cin>>seatno;
            }
            cout<<"Enter the Class"<<endl;
            cin.get();
            cin.getline(classe,20);
            while(fio.read((char*)&p,sizeof(p)) && cancel==0){
                if(!strcmp(p.getFno(),fno) && p.getUno()==uno && strcmpi(p.getName(),name)==0 && p.getseatno()==seatno && strcmpi(p.getclass(),classe)==0){
                    cancel=1;
                    p.setstatus(0);
                    time_t now=time(0);
                    p.setDate(ctime(&now));
                    fio.seekp((long)-sizeof(Person),ios::cur);
                    fio.write((char*)&p,sizeof(Person));
                    if(!cancel1.empty()){
                        qsize=cancel1.size();
                        for(int i=0;i<qsize;i++){
                            p1=cancel1.front();
                            cancel1.pop();
                            if(!strcmp(p1.getFno(),fno) && strcmpi(p1.getclass(),classe)==0 && found==0){
                                found=1;
                                p1.setseatno(seatno);
                                p1.setstatus(1);
                                fio.seekp(0L,ios::end);
                                fio.write((char*)&p1,sizeof(Person));
                            }
                            else{
                                cancel1.push(p1);
                            }
                        }
                    }
                    else{
                        cancel=1;
                    }
                }
            }
        }
    }
}
fio.close();
    if(cancel==1){
        cout<<"Successfully cancelled"<<endl;
        ret=1;
        }
    else{
        cout<<"Invalid Entry"<<endl;
        ret=0;
    }
return ret;
}


void InitialProtocol(int uno){
    fstream fio("Report.dat",ios::binary|ios::in|ios::out);
    fstream fgo("Flight.dat",ios::binary|ios::in|ios::out);
    Person p;int status;long int y;int found=0;Flight f;char accept='n';int rebook=0;
    if(!fio && !fgo){
        cout<<"Error Accessing File"<<endl;
    }
    else{
      while(fio.read((char*)&p,sizeof(Person))){
        if(p.getUno()==uno){
                found=0;
            if(p.getStatus()==4){//Status 4-Flight has been modified
                cout<<p.getName()<<endl;
                cout<<"Flight timings have been rescheduled"<<endl;
                fgo.seekg(0L,ios::end);
                y=fgo.tellg();
                fgo.seekg(0L);
                while(fgo.tellg()<y && found==0){
                    fgo.read((char*)&f,sizeof(Flight));
                    if(!strcmp(f.getfno(),p.getFno())){
                        f.display();
                        found=1;
                    }
                }
                cout<<"Do you Accept the changes?(Y/N)"<<endl;
                cin>>accept;
                if(accept!='y' && accept!='Y'){
                    if(strcmpi(p.getclass(),"business")==0)
                        f.setbookedbusi(f.getbookedbusi()-1);
                    else{
                        f.setbookedeco(f.getbookedeco()-1);
                    }
                    fgo.seekp((long)-sizeof(Flight));
                    fgo.write((char*)&f,sizeof(Flight));
                    cout<<"\nDo you want to rebook (Y/N)"<<endl;
                    cin>>accept;
                    if(accept=='y' || accept=='Y'){
                        rebook=rebook+1;
                        p.setstatus(0);
                    }
                    else{
                        cout<<"You are entitled to a REFUND of Rs. ";
                        cout<<p.getFare()<<endl;
                        p.setstatus(0);
                    }
                }
                else{
                    p.setstatus(1);
                }
            fio.seekp((long)-sizeof(p),ios::cur);
            fio.write((char*)&p,sizeof(Person));
            }
            else if(p.getStatus()==3){//Status 3-Flight was deleted
                cout<<p.getName()<<endl;
                cout<<"Flight has been canceled"<<endl;
                cout<<"Do you want to Re-Book(Y/N)"<<endl;
                cin>>accept;
                if(accept=='y' || accept=='Y'){
                    rebook=rebook+1;
                    p.setstatus(0);
                }
                else{
                    cout<<"You are entitled to a REFUND"<<endl;
                    cout<<p.getFare()<<endl;;
                    p.setstatus(0);
                }
                fio.seekp((long)-sizeof(Person),ios::cur);
                fio.write((char*)&p,sizeof(Person));
            }
            else;
        }
      }
            fgo.seekg(0L);
            if(rebook!=0 && fgo.read((char*)&f,sizeof(f))){
                cout<<"You can now rebook your seats"<<endl;
                Bookchoose(uno,rebook);
            }
            else if(rebook!=0 && !fgo.read((char*)&f,sizeof(f))){
                cout<<"You will be REFUNDED soon"<<endl;
            }
            else;
    }
    fio.close();
    fgo.close();
}


void viewBookingStatus(int uno){
int m;Person p;
fstream fio("Report.dat",ios::binary|ios::in|ios::out);
    if(!fio){
        cout<<"Error opening file"<<endl;
    }
    else{
        while(fio.read((char*)&p,sizeof(p))){
            if(p.getUno()==uno){
                p.display();
            }
        }
    }
m=cancel1.size();
for(int i=0;i<m;i++){
    p=cancel1.front();
    cancel1.pop();
    if(p.getUno()==uno){
        p.display();
    }
    cancel1.push(p);
}
fio.close();
}

int deleteFlight(){
cout<<"Welcome to flight deletion module"<<endl;
int cancel=0;char x[5];Flight f;long int y;Person p;int ret=0;
fstream fio("Flight.dat",ios::binary|ios::out|ios::in);
fstream fgo("Report.dat",ios::binary|ios::out|ios::in);
if(!fio && !fgo){
    cout<<"Error accessing file"<<endl;
    ret=0;
}
else{
    cout<<"Enter Flight number to be deleted"<<endl;
    cin>>x;
    while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>x;
    }
    fio.seekg(0L,ios::end);
    y=fio.tellg();
    fio.seekg(0L);
    Flight f1;
    while(fio.read((char*)&f,sizeof(Flight)) && cancel==0){
            if(!strcmp(f.getfno(),x)){
                fio.seekp((long)-sizeof(Flight),ios::cur);
                fio.write((char*)&f1,sizeof(Flight));
                cancel=1;
            }
        }
    while(fgo.read((char*)&p,sizeof(p))){
        if(!strcmp(p.getFno(),x) && p.getStatus()!=0){
            cout<<"Sending Intimation to User : "<<p.getName()<<endl;
            p.setstatus(3);
            fgo.seekp((long)-sizeof(p),ios::cur);
            fgo.write((char*)&p,sizeof(p));
        }
    }
}
    if(cancel==1){
        ret=1;
    }
    else
        ret=0;
return ret;
fgo.close();
fio.close();
}

int modifyFlight(){
 char x[5];Flight f;long int y;int modify=0;Person p;int ret=0;
 cout<<"WELCOME TO THE FLIGHT MODIFICATION INTERFACE"<<endl;
 fstream fio("Flight.dat",ios::binary|ios::in|ios::out);
 fstream fgo("Report.dat",ios::binary|ios::in|ios::out);
 if(!fio && !fgo){
    cout<<"Error opening file"<<endl;
    ret=0;
 }
 else{
    cout<<"\nEnter flight number"<<endl;
    cin>>x;
    while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>x;
    }
    fio.seekg(0L,ios::end);
    y=fio.tellg();
    fio.seekg(0L);
    Flight f1;
    cout<<"CHANGES CAN ONLY BE MADE IN FLIGHT ARRIVAL,DEPARTURE TIMES AND FARES"<<endl;
    while(fio.read((char*)&f,sizeof(Flight)) && modify==0){
            if(!strcmp(f.getfno(),x)){
                fio.seekp((long)-sizeof(Flight),ios::cur);
                f.acceptchange();
                fio.write((char*)&f,sizeof(Flight));
                modify=1;
            }
        }
     while(fgo.read((char*)&p,sizeof(p))){
        if(!strcmp(p.getFno(),x) && p.getStatus()!=0){
            fgo.seekp((long)-sizeof(p),ios::cur);
            cout<<"Intimating User : "<<p.getName()<<endl;
            p.setstatus(4);
            fgo.write((char*)&p,sizeof(p));
            }
        }
    }
    if(modify==1){
        ret=1;
    }
    else
        ret=0;
fio.close();
fgo.close();
return ret;
}

void dailyReport(){
    Person p;int ticket =0;double revenue=0;
    time_t now=time(0);
	char date[100];
	strcpy(date,ctime(&now));
    fstream fio("Report.dat",ios::binary|ios::out|ios::in);
    while(fio.read((char*)&p,sizeof(Person))){
        if(strnicmp(p.getDate(),date,11)==0){
            ticket=ticket+1;
            revenue=revenue+p.getFare();
        }
    }
    cout<<"Total tickets booked for the day"<<ticket<<endl;
    cout<<"Total revenue generated for the day"<<revenue<<endl;
    fio.close();
}

void FlightChart(){
    fstream fio("Flight.dat",ios::binary|ios::out|ios::in);
    char a[5];long int y;int found =0;Flight p;
    if(!fio){
        cout<<"Error reading file"<<endl;
    }
    else{
        cout<<"Enter Flight number for which report has to be generated"<<endl;
        cin>>a;
        while(cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"INCORRECT INPUT-Re-Enter"<<endl;
            cin>>a;
        }
        fio.seekg(0L,ios::end);
        y=fio.tellg();
        fio.seekg(0L);
        while(fio.tellg()<y && found==0){
        fio.read((char*)&p,sizeof(Person));
            if(!strcmp(p.getfno(),a))
                p.display();
                cout<<"Seats booked in business class are: "<<endl;
                cout<<p.getbookedbusi();
                cout<<"\nSeats booked in economy class are:"<<endl;
                cout<<p.getbookedeco();
                found=1;
        }
    }
}

void UpdateFlight(){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int day = now->tm_mday;
    int month = now->tm_mon + 1;
    int year = now->tm_year + 1900;
    fstream fio("Report.dat",ios::binary|ios::in|ios::out);
    fstream fgo("Flight.dat",ios::binary|ios::in|ios::out);
    if(!fio || !fgo){
        cout<<"Error reading file"<<endl;
    }
    else{
    Person p;Flight f;char fno[5];int tday,tmonth,tyear;
    fio.seekg(0L,ios::end);
    int found=0;int date;
    long int y=fio.tellg();
    fio.seekg(0L);
    fgo.seekg(0L,ios::end);
    long int x=fgo.tellg();
    fgo.seekg(0L);
    while((fio.tellg()<y && fio.tellg()>=0)){
        fio.read((char*)&p,sizeof(Person));
        if(p.getStatus()==1){
            strcpy(fno,p.getFno());
            fgo.seekg(0L);
            found=0;
            while((fgo.tellg()<x && fgo.tellg()>=0) && found==0){
                fgo.read((char*)&f,sizeof(Flight));
                if(!strcmp(f.getfno(),fno))
                    found=1;
            }
            date=f.getDate();
            tyear=date%10000;
            tmonth=(date/10000)%100;
            tday=date/1000000;
            if(tyear<year || (tmonth<month && tyear==year) || (tmonth==month && year==tyear && tday<day) ){
                p.setstatus(5);
                fio.seekp((long)-sizeof(Person),ios::cur);
                fio.write((char*)&p,sizeof(Person));
            }
        }
    }
    int qsize=cancel1.size();
    for(int i=0;i<qsize;i++){
        p=cancel1.front();
        strcpy(fno,p.getFno());
        cancel1.pop();
        fgo.seekg(0L);
        found=0;
        while((fgo.tellg()<x && fgo.tellg()>=0) && found==0){
            fio.read((char*)&f,sizeof(Flight));
            if(!strcmp(f.getfno(),fno))
                found=1;
        }
        date=f.getDate();
        tyear=date%10000;
        tmonth=(date/10000)%100;
        tday=date/1000000;
        if(tyear<year || (tmonth<month && tyear==year) || (tmonth==month && year==tyear && tday<day ));
        else{
             cancel1.push(p);
        }
    }
    }
}

//-----------------------------------------------------------------------------------------------------------
class User{
    int Uno;
    char name[100];
    int age;
    char usertype[100];
    char *date;
    char contno[11];
    char email[100];
    public:
        User();
        void accept();
        void acceptUno(int x);
        int getUno();
        char* getUsertype();
        void display();
        int getLength(char a[256]);
};
User::User(){
    Uno=0;
    name[0]='\0';
    strcpy(usertype,"Passenger");
    age=0;
}
void User::accept(){
    do{
    cout<<"Passenger or Employee?"<<endl;
    cin>>usertype;
    usertype[0]=toupper(usertype[0]);
    }while(((strcmpi(usertype,"passenger"))&&(strcmpi(usertype,"employee")))!=0);
    cout<<"Enter your name : "<<endl;
    cin.get();
    cin.getline(name,100);
    cout<<"Enter your age : "<<endl;
    cin>>age;
    while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>age;
    }
    cout<<"Enter your 10-digit contact number"<<endl;
    cin>>contno;
    while(strlen(contno)!=10){
        cout<<"Invalid-Re-enter"<<endl;
        cin>>contno;
    }
    cout<<"Enter your E-mail ID"<<endl;
    cin>>email;
}

void User::acceptUno(int x){
    Uno=x;
}

int User::getUno(){
    return Uno;
}

char* User::getUsertype(){
    return usertype;
}

int User:: getLength(char a[256]){
    int x;
    x=strlen(a);
    return x;
}

void User::display(){

cout<<"Hello "<<usertype<<'\t'<<name<<endl<<"Your Unique Identification number is : "<<Uno<<endl<<"Age : "<<age<<endl<<"Email-ID"<<email<<endl
<<"Contact Number"<<contno;
}

int generateUID(){
    int Uid;
    fstream fin("Users.dat",ios::binary|ios::in);
    fin.seekg((long)-sizeof(User),ios::end);
    User u;
    fin.read((char*)&u,sizeof(u));
    Uid=u.getUno()+1;
    fin.close();
    return Uid;
}


int addUser(){
    fstream fout("Users.dat",ios::binary|ios::app);
    fstream fleave("password.txt",ios::app);
    User u;int pro=1;int ret=0;char con[20];char c;int pos=0;
    if(!fout || !fleave){
        cerr<<"Space unavailable to add member !"<<endl;
        ret=0;
    }
    else{
        u.accept();
        if(strcmpi(u.getUsertype(),"Employee")==0){
            cout<<"Enter Admin LOGIN Password to confirm identity"<<endl;
            c=getch();
            while(c!=13 && pos<24){
                if(c==8){
                    cout<<"\b \b";
                    if(pos!=0){
                    con[pos]='\0';
                    pos--;
                    }
                }
                else if(c==13);
                else{
                    cout<<"*";
                    con[pos]=c;
                    pos++;
                    con[pos]='\0';
                }
                c=getch();
                }
            cout<<endl;
            if(strcmpi(con,"psschool1!")!=0){
                cout<<"ACCESS DENIED"<<endl;
                pro=0;
            }
        }
        if(pro!=0){
        u.acceptUno(generateUID());
            cout<<"Your Unique Identification number is "<<endl;
            cout<<u.getUno()<<endl;
            char pass[256],check[256];
            cout<<"Enter your new password (Maximum character limit is 24)"<<endl;
            pos=0;
            c=getch();
            while(c!=13 && pos<24){
                if(c==8){
                    cout<<"\b \b";
                    if(pos!=0){
                    pass[pos]='\0';
                    pos--;
                    }
                }
                else if(c==13);
                else{
                    cout<<"*";
                    pass[pos]=c;
                    pos++;
                    pass[pos]='\0';
                }
                c=getch();
                }
            cout<<endl;
            cout<<"Kindly Confirm your password"<<endl;
            pos=0;
            c=getch();
            while(c!=13 && pos<24){
                if(c==8){
                    cout<<"\b \b";
                    if(pos!=0){
                    check[pos]='\0';
                    pos--;
                    }
                }
                else if(c==13);
                else{
                    cout<<"*";
                    check[pos]=c;
                    pos++;
                    check[pos]='\0';
                    }
                c=getch();
                }
            if(strcmp(check,pass)==0){
                ret=1;
                time_t now=time(0);
                char date[100];
                strcpy(date,ctime(&now));
                int d[24],f,len;
                f=u.getUno();
                fleave<<f<<endl;
                fleave<<date;
                fleave<<pos<<endl;
                for(int i=0;i<pos;i++){
                    d[i]=int(pass[i])+int(date[i]);
                    fleave<<d[i]<<endl;
                }
                fout.write((char*)&u,sizeof(u));
                cout<<"\nPASSWORD GENERATION WAS A SUCCESS"<<endl;
            }
            else{
                ret=0;
            }
        }
    }
    fleave.close();
    fout.close();
    return ret;
}

int pass_Check(int p){
    char passTC[256];int limit=0;char trial='n';char c;int pos;int ret=0;
    char key[100];int x,y,z,found=0,m;
    ifstream fin("password.txt");
    while(fin>>y && found==0){
        if(y==p){
            found=1;
            m=y;
            }
        fin.get();
        fin.getline(key,100);
        fin>>x;
        for(int i=0;i<x;i++)
            fin>>z;
    }
    if(m!=p){
        ret=0;
    }
    else{
    found=0;
    int e[x];char a[x];
        int i=0;
        fin.close();
        fin.open("password.txt");
        while(fin>>y && found==0){
            if(y==p){
                found=1;
                m=y;
            }
            fin.get();
            fin.getline(key,100);
            fin>>x;
            for(i=0;i<x;i++)
                fin>>e[i];
        }
        for(i=0;i<x;i++){
            a[i]=char(e[i]-int(key[i]));
        }
        a[i]='\0';
    while(limit<3 && !(trial=='y'||trial=='Y')){
        pos=0;
        cout<<"Enter your login password"<<endl;
        c=getch();
        while(c!=13 && pos<24){
        if(c==8){
            cout<<"\b \b";
            if(pos!=0){
            passTC[pos]='\0';
            pos--;
            }
        }
        else if(c==13);
        else{
            cout<<"*";
            passTC[pos]=c;
            pos++;
            passTC[pos]='\0';
            }
        c=getch();
        }
        if(strcmp(passTC,a)==0){
            cout<<endl<<"Correct entry"<<endl;
            trial='y';
        }
        else{
            limit++;
            cout<<"Incorrect entry ! "<<'\t'<<"Attempts remaining : "<<'\t'<<3-limit<<endl;
        }
    }
    fin.close();
    if(limit==3){
      ret=0;
    }
    else{
        ret=1;
    }
}
return ret;
}

int pass_Change(){
int uno;int x,y,z,m,found=0;char date[100],key[100];int d[24];
fstream fio("password.txt",ios::in|ios::out);
if(!fio){
    cout<<"Error Opening file"<<endl;
    found=0;
}
cout<<"Enter your Unique Membership Number"<<endl;
cin>>uno;
while(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"INCORRECT INPUT-Re-Enter"<<endl;
        cin>>uno;
    }
char c;
int pos=0;
char pass[256];
    if(pass_Check(uno)==1){
    cout<<"Enter your new password (Maximum character limit is 24)"<<endl;
    c=getch();
    while(c!=13 && pos<24){
        if(c==8){
            cout<<"\b \b";
            if(pos!=0){
            pass[pos]='\0';
            pos--;
            }
        }
        else if(c==13);
        else{
            cout<<"*";
            pass[pos]=c;
            pos++;
            pass[pos]='\0';
            }
        c=getch();
        }
    cout<<endl;

    time_t now=time(0);
	strcpy(date,ctime(&now));
while(fio>>y && found==0){
    if(y==uno){
        found=1;
        }
    if(y!=uno){
        fio.get();
        fio.getline(key,100);
        fio>>x;
        for(int i=0;i<x;i++)
            fio>>z;
    }
    else{
        fio<<date;
        fio<<pos<<endl;
        for(int i=0;i<pos;i++){
            d[i]=int(pass[i])+int(date[i]);
            fio<<d[i]<<endl;
                }
            }
        }
    }
    fio.close();
    return found;
}

int modifyUser(){
    int x;int ret=0;
    fstream fio("Users.dat",ios::binary|ios::in|ios::out);
    if(!fio){
        cerr<<"\nError accessing the file"<<endl;
        ret=0;
    }
    else{
        User u;
        cout<<"Enter your Unique Membership number"<<endl;
        cin>>x;
        while(cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"INCORRECT INPUT-Re-Enter"<<endl;
            cin>>x;
        }
        fio.seekg((long)-sizeof(User),ios::end);
        fio.read((char*)&u,sizeof(User));
        if(x>u.getUno()){
            cout<<"Invalid input"<<endl;
            ret=0;
        }
        else{
            fio.seekg((long)((x-1)*sizeof(User)),ios::beg);
            fio.read((char*)&u,sizeof(User));
            if(u.getUno()==0){
                cout<<"Already deleted cannot be modified!"<<endl;
                ret=0;
            }
            else{
                if(pass_Check(x)!=0){
                cout<<"Enter the new details"<<endl;
                u.accept();
                u.acceptUno(x);
                fio.seekp((long)((x-1)*sizeof(User)),ios::beg);
                fio.write((char*)&u,sizeof(User));
                ret=1;
                }
                else{
                    cout<<"Invalid UID or Password"<<endl;
                }
            }
        }
    }
    fio.close();
    return ret;
}

int deleteUser(){
    int x;int ret=0;
    fstream fio("Users.dat",ios::binary|ios::in|ios::out);
    if(!fio){
        cerr<<"\nError accessing the file"<<endl;
        ret=0;
    }
    else{
        User u,u1;
        cout<<"Enter your Unique Membership number"<<endl;
        cin>>x;
        while(cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"INCORRECT INPUT-Re-Enter"<<endl;
            cin>>x;
        }
        fio.seekg((long)-sizeof(User),ios::end);
        fio.read((char*)&u,sizeof(User));
        if(x>u.getUno()){
            cout<<"Invalid input"<<endl;
            ret=0;
        }
        else{
            fio.seekg((long)((x-1)*sizeof(User)),ios::beg);
            fio.read((char*)&u,sizeof(User));
            if(u.getUno()==0){
                cout<<"Already deleted cannot be deleted again!"<<endl;
                ret=0;
            }
            else{
                if(pass_Check(x)!=0){
                fio.seekp((long)((x-1)*sizeof(User)),ios::beg);
                fio.write((char*)&u1,sizeof(User));
                ret=1;
                }
                else{
                    cout<<"Invalid UID or Password"<<endl;
                    ret=0;
                }
            }
        }
    }
    fio.close();
    return ret;
}


void SequenceFlight1(){
int opt;char pro='Y';
cout<<"Welcome Mr.Admin"<<endl;
do{
        cout<<"What would you like to do,Enter an option"<<endl<<"\n1-Add Route\n2- Add Flight\n3-Modify Flight\n4-Delete Flight\n5-Generate Daily Report\n6-Prepare a Flight Chart\n7-Modify Personal ID\n8-Delete ID\n9-Change Password\n10-Terminate"<<endl;
		cin>>opt;
		if(opt==1){
            cout<<"You are about to add a route,Do you want to proceed(Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y' || pro=='Y'){
                viewRoutes();
                cout<<endl;
                AddRoute();
            }
		}
		else if(opt==2){
            addFlight();
            pro='y';
		}
        else if(opt==3){
            system("cls");
            cout<<"You are about to MODIFY flight details. Do you want to proceed(Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y'||pro=='Y'){
                if(modifyFlight()==0){
                    cout<<"Modification failed"<<endl;
                    pro='y';
                }
                else{
                    cout<<"Modification was a success"<<endl;
                    pro='y';
                }
            }
            else{
                cout<<"PROCESS TERMINATED"<<endl;
                pro='y';
                }
        }
        else if(opt==4){
            system("cls");
            cout<<"You are about to DELETE flight details. Do you want to proceed(Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y'||pro=='Y'){
                if(deleteFlight()==0){
                    cout<<"Deletion failed"<<endl;
                    pro='y';
                }
                else{
                    cout<<"Deletion was a success"<<endl;
                    pro='y';
                }
            }
            else{
                cout<<"PROCESS TERMINATED"<<endl;
                pro='y';
                }
        }
        else if(opt==5){
            system("cls");
            cout<<"Generating Daily Report........."<<endl;
            cout<<"Do you want to proceed (Y/N)? "<<endl;
            cin>>pro;
            if(pro=='y' || pro=='Y')
                dailyReport();
            else{
                cout<<"Process Terminated"<<endl;
            }
            pro='y';
        }
        else if(opt==6){
            system("cls");
            cout<<"Generating Flight Report........."<<endl;
            cout<<"Do you want to proceed (Y/N)? "<<endl;
            cin>>pro;
            if(pro=='y' || pro=='Y')
                FlightChart();
            else{
                cout<<"Process Terminated"<<endl;
            }
            pro='y';

        }
        else if(opt==7){
            system("cls");
            cout<<"You are about to MODIFY your personal details. Do you want to proceed(Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y'||pro=='Y'){
                if(modifyUser()==0){
                    cout<<"Modification failed"<<endl;
                    pro='y';
                }
                else{
                    cout<<"Modification was a success"<<endl;
                    pro='y';
                }
            }
            else{
                cout<<"PROCESS TERMINATED"<<endl;
                pro='y';
            }
        }
        else if(opt==8){
            system("cls");
            cout<<"You are about to DELETE your details. Do you want to proceed(Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y'||pro=='Y'){
                if(deleteUser()==0){
                    cout<<"Deletion failed"<<endl;
                    pro='y';
                }
                else{
                    cout<<"Deletion was a success"<<endl;
                    pro='n';
                }
            }
            else{
                cout<<"PROCESS TERMINATED"<<endl;
                pro='y';
            }
        }
        else if(opt==9){
            system("cls");
            cout<<"You are about to Change your Password,Do you want to proceed(Y/N)"<<endl;
            cin>>pro;
            if(pro=='y' || pro=='Y'){
                if(pass_Change()==1){
                    cout<<"Password Modification was a success"<<endl;
                    pro='n';
                }
                else{
                    cout<<"Password Modification failed"<<endl;
                    pro='y';
                }
            }
            else{
                cout<<"Process Terminated"<<endl;
                pro='y';
            }
        }
        else if(opt==10){
            pro='n';
        }
        else{
            cout<<"Invalid Operation Entered!"<<endl;
            pro='y';
        }
    }while(pro=='y'||pro=='Y');
}

void SequenceFlight2(int uno){
int opt;char pro='Y';
InitialProtocol(uno);
UpdateFlight();
do{
        cout<<"What would you like to do,Enter an option"<<endl<<"\n1-Book Flight Ticket\n2-Cancel Flight Ticket\n3-Flight Booking history\n4-Modify Personal Details\n5-Delete ID\n6-Change ID Password\n7-Terminate"<<endl;
		cin>>opt;
		if(opt==1){
            system("cls");
            cout<<"Welcome to FLIGHT BOOKING INTERFACE"<<endl;
            cout<<"Do you want to proceed (Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y' || pro=='Y'){
                if(Bookchoose(uno,0)==1){
                    cout<<"Booking success"<<endl;
                    pro='y';
                }
                else{
                    cout<<"Booking failed"<<endl;
                    pro='y';
                }
            }
            else{
                cout<<"Process Terminated"<<endl;
                pro='y';
            }
        }
        else if(opt==2){
            cout<<"Welcome to the Ticket CANCELLATION INTERFACE"<<endl;
            cout<<"Do you want to proceed (Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y' || pro=='Y'){
                if(BookCancel(uno)==1){
                    pro='y';
                }
                else{
                    cout<<"Cancellation failed"<<endl;
                    pro='y';
                }
            }
            else{
                cout<<"Process terminated"<<endl;
                pro='y';
            }
        }
        else if(opt==3){
            cout<<"Let's view your booking history"<<endl;
            cout<<"Do you want to proceed (Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y' || pro=='Y'){
                viewBookingStatus(uno);
                pro='y';
            }
            else{
                cout<<"Process terminated"<<endl;
                pro='y';
            }
        }
         else if(opt==4){
            system("cls");
            cout<<"You are about to MODIFY your personal details. Do you want to proceed(Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y'||pro=='Y'){
                if(modifyUser()==0){
                    cout<<"Modification failed"<<endl;
                    pro='y';
                }
                else{
                    cout<<"Modification was a success"<<endl;
                    pro='y';
                }
            }
            else{
                cout<<"PROCESS TERMINATED"<<endl;
                pro='y';
            }
        }
        else if(opt==5){
            system("cls");
            cout<<"You are about to DELETE your details. Do you want to proceed(Y/N)?"<<endl;
            cin>>pro;
            if(pro=='y'||pro=='Y'){
                if(deleteUser()==0){
                    cout<<"Deletion failed"<<endl;
                    pro='y';
                }
                else{
                    cout<<"Deletion was a success"<<endl;
                    pro='n';
                }
            }
            else{
                cout<<"PROCESS TERMINATED"<<endl;
                pro='y';
            }
        }
        else if(opt==6){
            system("cls");
            cout<<"You are about to Change your Password,Do you want to proceed(Y/N)"<<endl;
            cin>>pro;
            if(pro=='y' || pro=='Y'){
                if(pass_Change()==1){
                    cout<<"Password Modification was a success"<<endl;
                    pro='n';
                }
                else{
                    cout<<"Password Modification failed"<<endl;
                    pro='y';
                }
            }
            else{
                cout<<"Process Terminated"<<endl;
                pro='y';
            }
        }
        else if(opt==7){
            cout<<"Process terminated"<<endl;
            pro='n';
        }
        else{
            cout<<"Process terminated"<<endl;
            pro='y';
        }
    }while(pro=='y' || pro=='Y');
}

void Login(){
    fstream fio("Users.dat",ios::binary|ios::in|ios::out);
    int uno,x; char a[]={"psschool1!"};
    if(!fio){
        cerr<<"File opening error"<<endl;
    }
    else{
        User u;
        system("cls");
        cout<<"Enter Unique Membership Number"<<endl;
        cin>>uno;
        fio.seekg((long)-sizeof(User),ios::end);
        fio.read((char*)&u,sizeof(User));
        if(uno>u.getUno()){
            cout<<"Invalid input"<<endl;
        }
        else{
            fio.seekg((long)((uno-1)*sizeof(User)),ios::beg);
            fio.read((char*)&u,sizeof(User));
            if(u.getUno()==0){
                cout<<"No such member, cannot login"<<endl;
            }
            else{
                if(pass_Check(uno)==0){
                    cout<<"Sorry invalid password,ACCESS DENIED"<<endl;
                }
                else{
                    cout<<"Let us proceed,Enter any number"<<endl;
                    cin>>x;
                    system("cls");
                    cout<<"WELCOME"<<endl;
                    fio.seekg((long)((uno-1)*sizeof(User)),ios::beg);
                    fio.read((char*)&u,sizeof(User));
                    if(strcmpi(u.getUsertype(),"Employee")==0)
                        SequenceFlight1();
                    else if(strcmpi(u.getUsertype(),"Passenger")==0)
                        SequenceFlight2(uno);
                    else;
                }
            }
        }
    }
}


void Sequence(){
int opt,x;char pro='Y';int uno;
do{
    cout<<"What would you like to do"<<endl<<"\n1-SIGN UP\n2-LOGIN to access all features\n3-Terminate"<<endl;
    cin>>opt;
    if(opt==1){
        system("cls");
        cout<<"Welcome to the USER ADDITION INTERFACE"<<endl;
        cout<<"Do you want to proceed(Y/N)?"<<endl;
        cin>>pro;
        if(pro=='y' || pro=='Y'){
            if(addUser()==1)
                cout<<"\nSuccessfully added"<<endl;
            else
                cout<<"\nUnsuccessful,was not added"<<endl;
        }
        else{
            cout<<"PROCESS TERMINATED"<<endl;
        }
        pro='y';
    }
    else if(opt==2){
        Login();
        pro='y';
    }
    else if(opt==3){
        pro='n';
    }
    else{
        cout<<"Invalid Operation Entered!"<<endl;
        pro='y';
            }
}while(pro=='y'||pro=='Y');

}

void qfinale(){
fstream fio("Qdetails.dat",ios::binary|ios::app);
Person p;
int qsize=cancel1.size();
for(int i=0;i<qsize;i++){
    p=cancel1.front();
    cancel1.pop();
    fio.write((char*)&p,sizeof(Person));
    }
}

void qupdate(){
fstream fio("Qdetails.dat",ios::binary|ios::out|ios::in);
Person p;
while(fio.read((char*)&p,sizeof(Person))){
    cancel1.push(p);
    }
fio.close();
fio.open("Qdetails.dat",ios::trunc);
fio.close();
}


void StatusBar(){
char a[50]="MADHAV'S C++ PROGRAM-FLIGHT RESERVATION SYSTEM---";
cout<<a<<endl;
Beep(500,1000);
for(int i=1;i<=100;i++){
    cout<<i<<"%";
    for(int j=0;j<i;j++){
        cout<<"|";
        }
    Sleep(i*1);
    if(i==0){
    cout<<endl;}
    cout<<'\r';
    }
cout<<endl;
}

int main(){
fstream fio("Report.dat",ios::binary|ios::out);
fstream fgo("Users.dat",ios::binary|ios::out);
fstream foo("Password.txt",ios::out);
fstream fko("Flight.dat",ios::out|ios::binary);
fstream fmo("Qdetails",ios::out|ios::binary);
fio.close();
fgo.close();
fko.close();
foo.close();
fmo.close();
system("mode 650");
system("Color 1F");
StatusBar();
qfinale();
Sequence();
qupdate();
}


