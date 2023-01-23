#include<iostream>

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

using namespace std;

template <class T>
class LinkStack {
public:
    struct node 
    {
        T value;
        node *next;
    };

    node* top;

    LinkStack() {
        top = NULL;
    }

    bool isEmpty(){
        if (top == NULL){
            cout << "\n!>> Stack Underflow!";
            return true;
        }
    return false;
    }

    void push(int item) {
        node* newPtr = new node;
        newPtr->value = item;
        newPtr->next = top;
        top = newPtr;
        cout << "\n!>> Pushed Value : " << item;
        display();   
    }

    int peak(){
        if (!isEmpty()){
            cout << "The top Value is : " << top->value << endl;
        }
        return top->value;
    }

    
    int pop() {
        T top_value;

        if (!isEmpty()){
            top_value = top->value;
            node *temp = top;
            top = top->next;
            cout << "\n!>> Popped Value : " << top_value;
            display();
        }
        return top_value;
    }

    void display() {
        node *temp = top;
        int count = 0;
        cout << "\n -------------------------------" << endl;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        for (int i = count; i > 0 ; i--)
        {
            temp = top;
            for (int j = 1; j < i; j++){
                temp = temp->next;
            }
            cout << " | " << temp->value;
        }
            cout << "\n -------------------------------" << endl;
    }
};

string reverse2() {
    LinkStack<char> obj;

    string str;
    cout << "\nEnter the String to be reversed : ";
    cin>>str;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        obj.push(str[i]);
    }
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = obj.pop();
    }
    cout << "\n!>> Reversed String : " << str;

    return str;
}


void LinkStackMenu() {
    int choice, exit_p = 1, item;
    string str;
    LinkStack<int> obj;
    do {
        cout << "\n\n lINKED Based Stack Menu";

        cout << "\n1.Push \n2.Pop \n3.Display \n4.IsEmpty? \n5.Peak \n6.Reverse String \n0.Back";
        cout << "\n>> Enter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                cout << "\nEnter the Value to be pushed : ";
                cin>>item;
                obj.push(item);
                break;
            case 2:
                obj.pop();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                if (!obj.isEmpty()){
                    cout << "\n!>> Stack is NOT Empty!";
                }
                break;
            case 5:
                obj.peak();
                break;
            case 6:
                reverse2();
                break;
            default:
                exit_p = 0;
                break;
        }
    } while (exit_p);

}

int main(){
    int choice;
    do {
        cout << "\n\n Stack Menu";

        cout << "\n1.Array Based \n2.LinkedList Based \n3.Reverse String \n0.Back";
        cout << "\n>> Enter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                // ArrayStack();
                break;
            case 2:
                LinkStackMenu();
                break;
            case 3:
                reverse2();
                break;
            default:
                break;
            }
        }while(choice != 0);

    return 0;
}