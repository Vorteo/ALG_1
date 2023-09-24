#include "Header.h"

/// Funkce k vytvoreni noveho uzlu.
/// Dynamicka alokace *node.
/// Ulozeni cisla do node->data.
/// nastaveni leveho a praveho uzlu na NULL.
/// Inspiroval jsem se z https://www.geeksforgeeks.org/binary-tree-set-1-introduction/
struct Node* newNode(int data)			
{
	Node* node = new Node;	
	node->data = data;
	node->left = node->right = NULL;		

	return (node);
}

///  Funkce, ktera vklada cisla do binarniho vyhledavaciho stromu.
/// Kdyz je strom prazdny tak na prvni misto ulozi prvni cislo ze souboru.
/// Nasledne pokud je dalsi nacitane cislo do stromu mensi jako predchoziho uzlu, tak ulozi cislo do leve vetve.
/// A pokud je vetsi tak ulozi cislo do prave vetve.
/// Citace: https://cs.wikipedia.org/wiki/Bin%C3%A1rn%C3%AD_vyhled%C3%A1vac%C3%AD_strom
Node* InsertNode(int data, Node* node)				
{
	if (node == NULL)							
	{
		return newNode(data);
	}
	else if (data <= node->data)					
	{
		node->left = InsertNode(data, node->left);
	}
	else											
	{
		node->right = InsertNode(data, node->right);
	}

	return (node);
};
///Funkce, ktera kontroluje jestli je leva a prava strana stromu symetricka.
/// Kdyz je leava a prava strana nulova tak vraci True.
/// Kdyz vsak obsahuji obe strany stromu data, tak se znova zavola v returnu funkce Symmetric pro dalsi uroven stromu a vola se tak dlouho dokud neprojde vsechny urovne stromu.
/// kdyz zjisti, ze nejsou vetse soumerne, tak vraci funkce False.

bool Symmetric(Node* nodeA, Node* nodeB)			
{
	if (nodeA == NULL && nodeB == NULL)				
	{
		return true;
	}
	if (nodeA && nodeB)				
	{
		return Symmetric(nodeA->left, nodeB->right) && Symmetric(nodeA->right, nodeB->left);
	}

	return false;
}
/// Pomocna funkce pro overeni symetrie.
/// Kdyz je strom nulovy vraci True, jinak vraci vysledek z funkce Symmetric, ktera overuje, zda je strom zrcadlove soumerny.
bool isSymmetric(node* root)
{
	if (root == nullptr)			
	{
		return true;
	}

	return Symmetric(root->left, root->right);			
}