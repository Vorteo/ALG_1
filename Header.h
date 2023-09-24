#pragma once

#include <iostream>
#include <string.h>
#include <fstream>


/// Struktura Node - uzel, obsahuje 3 atributy - data, left, right.
typedef struct Node {					

	int data;		/**< Promenna data typu int pro ulozeni cisla ze souboru do uzlu.   */					
	Node* left;		/**< ukazatel na levy uzel. Slouzi k propojeni mezi uzly.  */					
	Node* right;	/**< ukazatel na pravy uzel. Slouzi k propojeni mezi uzly.  */						

}node;


struct Node* newNode(int data);
Node* InsertNode(int data, Node* node);
bool Symmetric(Node* nodeA, Node* nodeB);
bool isSymmetric(node* root);
