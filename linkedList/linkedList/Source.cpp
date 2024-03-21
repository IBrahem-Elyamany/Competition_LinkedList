#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main() {
	//Input list by consol
	LinkedList<int> list1, list2, list3;
	int val;
	int num, size;
	cout << "Enter num of list element : ";
	cin >> size;
	cout << "Enter element of list : ";
	for (int i = 0; i < size; i++) {
		cin >> num;
		list1.Insert(num);
	}
	cout << "\n# # The list after sort \n";
	cout << "list: ";
	list1.Display();
	cout << endl;
	cout << "\n# # The min of list after use <getMin()> \n";
	cout << "min of list: ";
	cout << list1.getMin() << endl;
	cout << "\n# # Insert in list by use <Insert(val)> \n";
	cout << "Enter val to insert in list :";
	cin >> val;
	list1.Insert(val);
	cout << "list after add \"" << val << "\": ";
	list1.Display();
	cout << endl;
	cout << "\n# # Merge two list by use <Merge(list)\n";
	cout << "# make new list to merge withe current list \n";
	cout << "Enter num of list element : ";
	cin >> size;
	cout << "Enter element of list : ";
	for (int i = 0; i < size; i++) {
		cin >> num;
		list2.Insert(num);
	}
	list1.Merge(list2);
	cout << "list after marge: ";
	list1.Display();
	cout << endl;
	cout << "\n# # show intersection in two list by use <Intersection(list)\n";
	cout << "# make new list to show intersection withe current list \n";
	cout << "Enter num of list element : ";
	cin >> size;
	cout << "Enter element of list : ";
	for (int i = 0; i < size; i++) {
		cin >> num;
		list3.Insert(num);
	}
	cout << "Intersection is: ";
	for (int i = 0; i < list1.Intersection(list3).Length(); i++)
		cout << list1.Intersection(list3).At(i) << " ";
	cout << endl;
	cout << endl;
	cout << "Thank you\n";
	cout << "IB";

	return 0;
}
//int main()
//{
//	LinkedList<int> L,L1;
//	L.Insert(9);
//	L.Insert(7);
//	L.Insert(11);
//	L.Insert(6);
//	L.Insert(3);
//
//
//	L1.Insert(4);
//	L1.Insert(0);
//	L1.Insert(9);
//	L1.Insert(11);
//	/*for (int i = 0; i < L1.Length(); i++) {
//
//		L.Insert(L1.At(i));
//
//	}*/
//	//L.Merge(L1);
//	/*L.InsertAt(1, 100 );
//	L.DeleteAt(3);*/
//	//L.Display();
//	for (int i = 0; i< L.Intersection(L1).Length(); i++)
//		cout << L.Intersection(L1).At(i) << endl;
//	return 0;
//}