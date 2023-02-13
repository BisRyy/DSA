#include<iostream>

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stack>

#define MAX_SIZE 100

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
            cout << "\n!>> Stack Underflow!";
            return true;
        }
    
    return false;
    }

    bool isFull(){
        if (top == MAX_SIZE){
            cout << "\n!>> Stack Overflow!";
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
            cout << endl <<"The top Value is : " << arr_stack[top-1];
        }
        return arr_stack[top-1];
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
        // cout << "\n!>> Stack Size : " << top << "  Max Size : " << MAX_SIZE;;
        //     cout << "\n -------------------------------" << endl;
        // for (i = 0; i < top; i++){
        //     cout << " | " << arr_stack[i];
        // }
            cout << "\n -------------------------------" << endl;
    }
};

string reverse(string str) {
    Stack<char> obj;

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

void ArrayStack() {
    int choice, exit_p = 1, item;
    string str;

    Stack<int> obj;
    do {
        cout << "\n\n Array Based Stack Menu";

        cout << "\n1.Push \n2.Pop \n3.Display \n4.IsEmpty? \n5.Peak \n6.Reverse String \n0.Back";
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
                cout << "\nEnter The String to be reversed : ";
                cin>>str;
                reverse(str);
                break;
            default:
                exit_p = 0;
                break;
        }
    } while (exit_p);

}


// ------------------------------------


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

    void push(T item) {
        node* newPtr = new node;
        newPtr->value = item;
        newPtr->next = top;
        top = newPtr;
        cout << "\n!>> Pushed Value : " << item;
        display();   
    }

    T peak(){
        if (!isEmpty()){
            cout << "The top Value is : " << top->value << endl;
        }
        return top->value;
    }

    
    T pop() {
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
                cout << "\nEnter The String to be reversed : ";
                cin>>str;
                reverse(str);
                break;
            default:
                exit_p = 0;
                break;
        }
    } while (exit_p);

}

//  ------------------------

void decimalToBinary(int number){
    LinkStack<char> obj;
    int remainder;
    while (number > 0){
        remainder = number % 2;
        obj.push(char(remainder + '0'));
        number = number / 2;
    }
    cout << "\n!>> Binary Values Stack : ";
    obj.display();
    
    string answer = "";
    while(!obj.isEmpty()){
        answer += to_string(obj.pop()-'0');
    }

    cout << "\n\n!>> Binary Value : " << answer;
}

void palindrome(){
    string str;
    cout << "\nEnter the String to be checked : ";
    cin>>str;
    if (reverse(str) == str){
        cout << "\n!>> String is Palindrome!";
    }
    else{
        cout << "\n!>> String is NOT Palindrome!";
    }
}

int precedence(char ch){
    if (ch == '+' || ch == '-'){
        return 1;
    }
    else if (ch == '*' || ch == '/'){
        return 2;
    }
    else if (ch == '^'){
        return 3;
    }
    else{
        return 0;
    }
}

void convert_infix_to_postfix(string infix){
    LinkStack<char> obj;
    string postfix = "";
    int i;
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '('){
            obj.push(infix[i]);
        }
        else if (infix[i] == ')'){
            while (obj.top->value != '('){
                postfix += obj.pop();
            }
            obj.pop();
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
            while (!obj.isEmpty() && obj.top->value != '(' && precedence(infix[i]) <= precedence(obj.top->value)){
                postfix += obj.pop();
            }
            obj.push(infix[i]);
        }
        else{
            postfix += infix[i];
        }
    }
    while (!obj.isEmpty()){
        postfix += obj.pop();
    }
    cout << "\n!>> Postfix Expression : " << postfix;
}

void postfixEvaluation(string postfix){
    Stack<float> obj;
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'){
            float a = obj.pop();
            float b = obj.pop();
            if (postfix[i] == '+'){
                obj.push(a + b);
            }
            else if (postfix[i] == '-'){
                obj.push(b - a);
            }
            else if (postfix[i] == '*'){
                obj.push(a * b);
            }
            else if (postfix[i] == '/'){
                obj.push(b / a);
            }
            else if (postfix[i] == '^'){
                obj.push(pow(b, a));
            }
        }
        else{
            obj.push(postfix[i] - '0');
        }
    }

    cout << "!>> Result : ";

    cout << obj.pop();
}


int main(){
    int choice, num;
    string infix, postfix;
    do {
        cout << "\n\n Stack Menu";

        cout << "\n1.Array Based \n2.LinkedList Based \n3.Reverse String \n4.Decimal to Binary\n5.Check Palindrome \n6.Evaluate Postfix \n7.Infix to Postfix\n0.Back";
        cout << "\n>> Enter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                ArrayStack();
                break;
            case 2:
                LinkStackMenu();
                break;
            case 3:
                reverse2();
                break;
            case 4:
                cout << "\nEnter a number to convert: ";
                cin>>num;
                decimalToBinary(num);
                break;
            case 5:
                palindrome();
                break;
            case 6:
                cout << "\nEnter the Postfix Expression : ";
                cin>>postfix;
                postfixEvaluation(postfix);
                break;
            case 7:
                cout << "\nEnter the Infix Expression : ";
                cin>>infix;
                convert_infix_to_postfix(infix);
                break;
            default:
                break;
            }
        }while(choice != 0);

    return 0;
}