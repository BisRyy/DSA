#include<iostream>

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

using namespace std;

template <class T>
class Stack {
private:
    T item, i;
    T arr_stack[MAX_SIZE];
    int top;

public:

    Stack() {
        top = 0;
    }

    bool isEmpty(){
        if (top == 0){
            cout << "\n!>> Stack is Empty!";
            return true;
        }
    
    return false;
    }

    bool isFull(){
        if (top == MAX_SIZE){
            cout << "\n!>> Stack is Full!";
            return true;
        }
    
    return false;
    }

    void push(T item) {
        if (!isFull()){
            cout << "\n!>> Position : " << top << ", Pushed Value : " << item;
            arr_stack[top++] = item;
            display();
        }
    }

    T peak(){
        if (!isEmpty()){
            cout << "The top Value is : " << arr_stack[top-1] << endl;
        }
    }

    
    T pop() {
        
        if (!isEmpty()){
            --top;
            cout << "\n!>> Position : " << top << ", Popped Value : " << arr_stack[top];
            display();
        }
        return arr_stack[top];
    }

    void display() {
        cout << "\n!>> Stack Size : " << top << "  Max Size : " << MAX_SIZE;;
            cout << "\n -------------------------------" << endl;
        for (i = 0; i < top; i++){
            cout << " | " << arr_stack[i];
        }
            cout << "\n -------------------------------" << endl;
    }
};

string reverse() {
    Stack<char> obj;

    string str;
    cout << "\nEnter The String to be reversed : ";
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


int main() {
    int choice, exit_p = 1, item;
    Stack<int> obj;
    do {
        cout << "\n\nStack Main Menu";

        cout << "\n1.Push \n2.Pop \n3.Display \n4.IsEmpty? \n5.Peak \n6.Reverse String \n0.Exit";
        cout << "\n>> Enter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                cout << "\nEnter The Value to be pushed : ";
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
                reverse();
                break;
            default:
                exit_p = 0;
                break;
        }
    } while (exit_p);

    return 0;
}