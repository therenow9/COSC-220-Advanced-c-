#include <iostream>
#include <queue>

using namespace std;
class Bill
{
public:
    string due_date="";
    string pay_to="";
    double amount=0;
};
void input_bill(Bill &my_bill)
{
    cout<<"Who is the bill to be paid too?"<<endl;
    cin>>my_bill.pay_to;
    cout<<"What is the amount of the bill?"<<endl;
    cin>>my_bill.amount;
    cout<<"When is this bill due"<<endl;
    cin>>my_bill.due_date;
    //get info about bill object
}
Bill find_next_due(queue <Bill> my_queue){
    queue <Bill> temp=my_queue;
    Bill temp_bill.due_date="0/0/0000";

    while(temp.empty()==false)
    {
        if (temp.front().due_date>temp_bill.due_date){
            //compare dates using string operator
            temp_bill=temp.front();
        }
            temp.pop();
    }
    return temp_bill;
}
void pay_queue(queue <Bill> &my_queue)
{
    Bill temp=find_next_due(my_queue);
    queue <Bill> temp=my_queue;
       while(temp.empty()==false)
    {
        if (temp.front().due_date==temp_bill.due_date&&temp.front().pay_to==temp_bill.pay_to&&temp.front().amount==temp_bill.amount){
            //compare dates using string operator
            my_queue.pop();
            //get rid of the paid bill
        }
    }
}
int main()
{
//typically other bills would be stored in a text file and brought into the program here
    queue <Bill> bill_queue;
    bool done=false;
    int choice=4;
    char pay_bill;
    while (done==false)
    {

        cout<<"1:input new bill into system"<<endl;
        cout<<"2:Pay bill"<<endl;
        cout<<"3:Exit"<<endl;
        cin>>choice;
        Bill temp;
        Bill temp_2;
        switch  (choice)

        {
        case 1:
            input_bill(temp);
            bill_queue.push(temp);
            break;
        case 2:
            temp_2=find_next_due(bill_queue);
            cout<<"Due date:"<<temp_2.due_date<<"  Pay to:"<<temp_2.pay_to<<"  Amount:  "<<temp_2.amount<<endl;
            cout<<"Are you paying this bill now?"<<endl;
            cin>>pay_bill;

            if (pay_bill=='y')
            {
                pay_queue(bill_queue);
                //set to true
            }
            if (pay_bill=='n')
            {
                //do nothing
            }

            break;
        case 3:
            done=true;
            break;

        }
        cout<<endl;
    }
    return 0;
}

