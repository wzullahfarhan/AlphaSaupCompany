#include<iostream>
using namespace std;
class Employee{
        private:
        int id;
        string name;
        double payment;
        public:
            Employee(){
                //cout<<"Employee Default"<<endl;
            }
            Employee(int i,string na,double pa){
                id=i;
                name=na;
                payment=pa;
            }
            void SetId(int i){
                id=i;
            }
            int GetId(){
                return id;
            }
            void SetName(string na){
                name=na;
            }
            string GetName(){
                return name;
            } 
            void SetPayment(double pa){
                payment=pa;
            }
            double GetPayment(){
                return payment;
            }
            void showInfo(){
            cout<<"\t Name is: "<<name<<endl;
            cout<<"\t ID is: "<<id<<endl;
            cout<<"\t Payment Amount is: "<<payment<<endl;
            }
};

class Worker:public Employee{
    private:
        float Extra_Hours;
    public:
        Worker(){
           // cout<<"Worker Default"<<endl;
        }
        Worker(int i,string na,double pa,float h):Employee(i,na,pa){
            Extra_Hours=h;
    }
    void SetExtraHour(int a){
        Extra_Hours=a;
    }
    float GetExtraHour(){
        return Extra_Hours;
    }
    double TotalIncome(){
        double a=0;
        a=(Extra_Hours*200);
        return a;    }
    void ShowWorkerInfo(){
        cout<<"The Info Of Worker"<<endl;
        showInfo();
        cout<<"\tTotal Income:"<<GetPayment()+TotalIncome()<<endl;
        cout<<endl;
    }
};
class Vendor:public Employee{
    private:
        float Deduction_Percentage;
    public:
        Vendor(){
           // cout<<"vendor default"<<endl;
        }
        Vendor(int i,string na,double pa,float a):Employee(i,na,pa){
            Deduction_Percentage=a;
        }
        void SetDeductionPer(float p){
            Deduction_Percentage=p;
        }
        float GetDeductionPer(){
        return Deduction_Percentage;
        }
        double TotalINcome(){
            
            double a=0;
            a=((GetPayment()*Deduction_Percentage))/100;
            return a;
        }
       // double income(){
          //  return a;
      //  }
        void ShowVendorInfo(){
            cout<<"The info of Vendor"<<endl;
            showInfo();
            cout<<"\tTotal Income:"<<GetPayment()-TotalINcome()<<endl;
            cout<<endl;
        }
};
int main(){
    cout<<"***********************************************************************"<<endl;
    cout<<" \t\t\t  ALPHA SOAP COMPANY \t\t"<<endl;
    cout<<"|======================================================================|"<<endl;
    cout<<"|\t\t\t**********************                         |"<<endl;
    int a,b,c;
    string Name;
    int ID;
    double Payment;
    char ch,bh;
    float d,e;
    cout<<"\t\tHow many Employee Has In this Company: ";
    cin>>a;
    cout<<"\tHow many have Works: ";
    cin>>b;
    cout<<"\tHow many have vendors: ";
    cin>>c;
    cout<<endl;
    cout<<endl;
    Employee A[b];
    Employee B[c];
    Worker W[b];
    Vendor V[c];
    if(a==(b+c)){
        cout<<"-------Enter Worker Details "<<endl;
        for (int i = 0; i < b; i++)
        {
            cout<<"Enter "<<i+1<<" Worker name: ";
            cin.ignore ();
            getline(cin,Name);
            cout<<"Enter "<<i+1<<" Worker ID: ";
            cin>>ID;
            cout<<"Enter "<<i+1<<" Worker Payment: ";
            cin>>Payment;
            cout<<endl;
            cout<<"\t\tDoes the Worker Do Over Time??";
            cout<<endl;
            cout<<"\tIf 'Yes' Type 'y' If 'No' type 'n'---= ";
            cin>>ch;
            if (ch=='y')
            {
                cout<<"Enter "<<i+1<<" Worker Extra Hours: ";
                cin>>d;
                W[i].SetName(Name);
                W[i].SetId(ID);
                W[i].SetPayment(Payment);
                W[i].SetExtraHour(d);
                W[i].TotalIncome();
            }
            else if(ch=='n'){
                W[i].SetName(Name);
                W[i].SetId(ID);
                W[i].SetPayment(Payment);
                W[i].SetExtraHour(0);
                W[i].TotalIncome();

            }else{
                cout<<"User Input Wrong for "<<i+1<<" Number workers"<<endl;
                A[i].SetName(Name);
                A[i].SetId(ID);
                A[i].SetPayment(Payment);
                A[i].showInfo();
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        cout<<"-------Enter Vendor Details: "<<endl;
        for (int j = 0; j < c; j++)
        {
            cout<<"Enter "<<j+1<<" Vendor name: ";
            cin.ignore();
            getline(cin,Name);
            cout<<"Enter "<<j+1<<" Vendor ID: ";
            cin>>ID;
            cout<<"Enter "<<j+1<<" Vendor Payment: ";
            cin>>Payment;
            cout<<endl;
            cout<<"\t\tDoes The Vendor Have Any Deduction Percentage??"<<endl;
            cout<<"\tIf 'Yes' Type 'y' If 'No' type 'n'---= ";
            cin>>bh;
            if(bh=='y'){
                cout<<"Enter The deduction Percentage For Vendor "<<j+1<<" ::";
                cin>>e;
                V[j].SetName(Name);
                V[j].SetId(ID);
                V[j].SetPayment(Payment);
                V[j].SetDeductionPer(e);
                V[j].TotalINcome();
            }
            else if(bh=='n'){
                V[j].SetName(Name);
                V[j].SetId(ID);
                V[j].SetPayment(Payment);
                V[j].SetDeductionPer(0);
                V[j].TotalINcome();

            
            }else{
                cout<<"User Input Wrong for "<<j+1<<" Number Vendor"<<endl;
                B[j].SetName(Name);
                B[j].SetId(ID);
                B[j].SetPayment(Payment);
                B[j].showInfo();
            }
            cout<<endl;
        }
        for (int i = 0; i < b; i++){
            W[i].ShowWorkerInfo();
        }
        for (int i = 0; i < c; i++){
            V[i].ShowVendorInfo();
        }
    }else{
        cout<<"\t\t-----Check Your Input Again-----\n"<<endl;
        cout<<"\t---Workers And Vendors Must be Equal to Employee---"<<endl;
        cout<<"\t\t\tThank you"<<endl;
    }
    cout<<"-----------THANK YOU------------"<<endl;
    return 0;
}