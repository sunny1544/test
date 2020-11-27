#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;

class MinStack {
public:
	stack < int > mainStack, minStack;

	MinStack() {
		
	}

	void push(int x) {		//minstack���̤p��>x,�hpush
		mainStack.push(x);
		if (minStack.empty() || minStack.top() > x) {
			minStack.push(x);
		}
	}

	void pop() {
		int num = mainStack.top();
		if (num == minStack.top()) {
			minStack.pop();
		}
		mainStack.pop();
	}

	int top() {
		return mainStack.top();
	}

	int getMin() {		//minstack�̤W�����Ƭ��̤p��
		return minStack.top();
	}
};

int main() {
	string s;
	string value;
	cin >> s;
	cin >> value;

	s.erase(0, 2);	//�R���A���B"
	s.erase(s.size() - 1, s.size());	//�R����A��
	value.erase(0, 1);
	value.erase(value.size() - 1, value.size());

	int v[8];
	for (int i = 0;i < 8;i++) {		//���[]�̭����Ȱ����A�ഫ�s�_��
		int left = value.find("[");
		int right = value.find("]");
		stringstream ss;
		ss << value.substr(left + 1, right);
		ss >> v[i];
		value.erase(0, right + 2);
	}
	cout << "[";
	int k = 0;	//�ƲĴX�ӫ��O
	MinStack mystack;
	for (int i = 0;i < 8;i++) {	
		int pos = s.find('"');
		string x = s.substr(0, pos);
		s.erase(0, pos + 3);	
		if (x == "MinStack") {
			cout << "null";
			k++;
		}
		else if (x == "push") {
			mystack.push(v[k]);
			cout << "null";
			k++;
		}
		else if (x == "getMin") {
			cout << mystack.getMin();
			k++;
		}
		else if (x == "pop") {
			mystack.pop();
			cout << "null";
			k++;
		}
		else if (x == "top") {
			cout << mystack.top();
			k++;
		}
		if (i != 7)
			cout << ",";
	}
	cout << "]" << endl;
}