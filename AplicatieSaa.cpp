// AplicatieSaa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

using namespace std;
int Size = 0;

struct Nod {
	string data;
	string Titleofthebook;
	string Author;
	string Language;
	string Typeofthebook;
	int Year;
	int Numberpages;
	string Publisher;
	Nod* next;
	Nod* previous;
}*inceput = NULL, * sfarsit = NULL;

Nod* newNode(string data, int _Year, string _Author, string _Language, string _Titleofthebook, string _Publisher, int _Numberpages) {
	Nod* nodNou = new Nod();
	nodNou->data = data;
	nodNou->Year = _Year;
	nodNou->Author = _Author;
	nodNou->Language = _Language;
	nodNou->Titleofthebook = _Titleofthebook;
	nodNou->Publisher = _Publisher;
	nodNou->Numberpages = _Numberpages;
	nodNou->previous = nodNou->next = NULL;

	return nodNou;
}



bool isEmpty()
{
	return (inceput == NULL);
}

int size()
{

	return Size;
}

//Insert Front

void insertInceput()
{
	cout << "--------------------------------------\n";
	
	string data;
	int _Year;
	string _Author;
	string _Language;
	string _Titleofthebook;
	string _Publisher;
	int _Numberpages;
	cout << "Data: ";
	cin >> data;

	cout << "Year: ";
	cin >> _Year;

	cout << "Autor: ";
	cin >> _Author;

	cout << "Language:";
	cin >> _Language;

	cout << "Tilteofthebook:";
	cin >> _Titleofthebook;

	cout << "Publisher:";
	cin >> _Publisher;

	cout << "_Numerpages:";
	cin >> _Numberpages;

	Nod* nodNou = newNode(data, _Year, _Author, _Language, _Titleofthebook, _Publisher, _Numberpages);
	// If true then new element cannot be added 
	// and it is an 'Overflow' condition 
	if (nodNou == NULL)
		cout << "Nu merge\n";
	else
	{
		// If deque is empty 
		if (inceput == NULL)
			sfarsit = inceput = nodNou;

		// Inserts node at the front end 
		else
		{
			nodNou->next = inceput;
			inceput->previous = nodNou;
			inceput = nodNou;
		}

		// Increments count of elements by 1 
		Size++;
	}
	cout << "\nThe node was added successfully!\n";
	cout << "--------------------------------------";
}

void insertSfarsit()
{
	cout << "--------------------------------------\n";
	
	// If true then new element cannot be added 
	// and it is an 'Overflow' condition 
	string data;
	int _Year;
	string _Author;
	string _Language;
	string _Titleofthebook;
	string _Publisher;
	int _Numberpages;
	cout << "Data: ";
	cin >> data;

	cout << "Year: ";
	cin >> _Year;

	cout << "Autor: ";
	cin >> _Author;

	cout << "Language:";
	cin >> _Language;

	cout << "Tilteofthebook:";
	cin >> _Titleofthebook;

	cout << "Publisher:";
	cin >> _Publisher;
	
	cout << "_Numerpages:";
	cin >> _Numberpages;

	Nod* nouNod = newNode(data, _Year, _Author, _Language, _Titleofthebook, _Publisher, _Numberpages);

	if (nouNod == NULL)
		cout << "OverFlow\n";
	else
	{
		// If deque is empty 
		if (inceput == NULL)
			inceput = sfarsit = nouNod;

		// Inserts node at the rear end 
		else
		{
			nouNod->previous = sfarsit;
			sfarsit->next = nouNod;
			sfarsit = nouNod;
		}

		Size++;
	}
	cout << "\nThe node was added successfully!\n";
	cout << "--------------------------------------";
}
// Function to delete the element 
// from the front end 
void deleteInceput()
{
	cout << "--------------------------------------\n";
	// If deque is empty then 
	// 'Underflow' condition 
	if (isEmpty())
	cout << "Nu se poate\n";
	
	// Deletes the node from the front end and makes 
	// the adjustment in the links 
	else
	{
		Nod* temp = inceput;
		inceput = inceput->next;

		// If only one element was present 
		if (inceput == NULL)
		{
			sfarsit = NULL;
			Size--;
		}
			
		
		else {
			inceput->previous = NULL;
			free(temp);

			// Decrements count of elements by 1 
			Size--;
			cout << "\nThe node was removed successfully!\n";
			cout << "--------------------------------------";
		}
	}



}

void Display()
{
	//trebuie sa numar cate noduri sunt si sa afisez toata stiva
	if (inceput == NULL)
	{
		cout << "\nThe stack is empty !\n";
	}
	else 
		cout << "--------------------------------------";
		cout << "\nThe stack size is: " << Size << endl;
	

	cout << "\nThe stack is: \n";
	Nod* aux = inceput;
	while (inceput)
	{
		cout << "Name of the author:" << inceput->Author << '\n';
		cout << "Language:" << inceput->Language << '\n';
		cout << "Type of the book:" << inceput->Titleofthebook << '\n';
		cout << "Number of pages:" << inceput->Numberpages << '\n';
		cout << "Publisher:" << inceput->Publisher << '\n';
		cout << "Data:" << inceput->data << '\n';
		cout << "Year of publishing: " << inceput->Year << "\n\n";

		inceput = inceput->next;
	}
	inceput = aux;
	cout << "--------------------------------------";

}



void deleteSfarsit()
{
	cout << "--------------------------------------\n";
	// If deque is empty then 
	// 'Underflow' condition 
	if (isEmpty())
	{
		cout << "UnderFlow\n";
	}
	// Deletes the node from the rear end and makes 
	// the adjustment in the links 
	else
	{
		Nod* temp = sfarsit;
		sfarsit = sfarsit->previous;

		// If only one element was present 
		if (sfarsit == NULL)
			inceput = NULL;
		else
		{
			sfarsit->next = NULL;
			free(temp);

			// Decrements count of elements by 1 
			

			
		}
		Size--;
	}

	
}



int main()
{



	int choice;
	while (1) {
		cout << "\n What do you want to do?\n";
		cout << "1. Add node at the beginning\n";
		cout << "2. Add node at the end\n";
		cout << "3. Remove beginning node\n";
		cout << "4. Remove end node\n";
		cout << "5. Display the number of nodes and the stack\n";
		cout << "7. Exit\n";

		cout << "\nchoice = "; cin >> choice;

		switch (choice)
		{
		case 1: insertInceput();
			break;
		case 2: insertSfarsit();
			break;
		case 3: deleteInceput();
			break;
		case 4: deleteSfarsit();
			break;
		case 5: Display();
			break;
		case 7: return 0;
		default: return 0;
		}
	}
}

