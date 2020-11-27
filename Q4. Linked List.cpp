#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Node {        //每個node有data,ptr
public:
    int data;
    Node(int d) {
        data = d;
    }
    Node* ptr;
};
bool Palindrome(Node* head) {

    Node* slow = head;

    stack <int> s;
    while (slow != NULL) {  //將list放入stack
        s.push(slow->data);
        slow = slow->ptr;
    }

    while (head != NULL) {  //pop出來為reverse結果,與原本的list比較

        int i = s.top();
        s.pop();

        if (head->data != i) {
            return false;
        }

        head = head->ptr;
    }


    return true;
}
int main() {
    Node one = Node(1);
    Node two = Node(2);

    one.ptr = &two;
    two.ptr = NULL;

    if (Palindrome(&one) == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    Node three = Node(1);
    Node four = Node(2);
    Node five = Node(2);
    Node six = Node(1);

    three.ptr = &four;
    four.ptr = &five;
    five.ptr = &six;
    six.ptr = NULL;

    if (Palindrome(&three) == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}