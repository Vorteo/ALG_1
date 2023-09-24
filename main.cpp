#include "Header.h"

using namespace std;

/// Main obsahuje otevreni souboru, ktery zada uzivatel.
/// Textovy soubor se musi nachazet v adresari se zdrojovymi kody, aby ho slo otevrit a nacist z nej data.
/// Kontrola jestli soubor existuje.
/// Postupne nacteni cisel ze souboru a vlozeni do struktury pomoci cyklu While.
/// Vypis jestli je dany strom symetricky nebo asymetricky.
int main()
{
	string filename;							

	cout << " Enter filename:" << endl;				
	cin >> filename;

	ifstream file;								
	file.open(filename);	

	if (!file)							
	{
		cout << "Unable to open File";
		exit(1);
	}

	int number;	
	Node* root;			
	root = nullptr;		

	while (file >> number)				
	{
		root = InsertNode(number, root);		
	}

	if (isSymmetric(root))						
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}

	file.close();
	free(root);		
	return 0;
}
