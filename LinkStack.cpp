#include<iostream>

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

using namespace std;

template <class T>
class node
{
public:
    T value;
    node<T> *next;
};

template <class T>
class Stack {
private:
    node<T> top;

public:

    bool isEmpty(){
        if (top == NULL){
            cout << "\n!>> Stack is Empty!";
            return true;
        }
    return false;
    }

    void push(T item) {
        node<T> newPtr;
        newPtr.value = item;
        newPtr.next = top;
        top = newPtr;
        cout << "\n!>> Pushed Value : " << item;
        display();   
    }

    T peak(){
        if (!isEmpty()){
            cout << "The top Value is : " << top.value << endl;
        }
    }

    
    T pop() {
        T top_value;

        if (!isEmpty()){
            top_value = top.value;
            node<T> *temp = top;
            top = top.next;
            cout << "\n!>> Popped Value : " << top_value;
            display();
        }
        return top_value;
    }

    void display() {
        node<T> *temp = top;
        cout << "\n -------------------------------" << endl;
        while (temp != NULL)
        {
            cout << " | " << temp.value;
            temp = temp.next;
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