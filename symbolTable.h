//Symbol table header
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include "AST.h"

struct Entry
{
	int itemID;
	char itemName[50];  //the name of the identifier
	char itemKind[20];  //is it a function or a variable?
	char itemType[20];  // Is it int, char, etc.?
	int arrayLength;
	char scope[50];     // global, or the name of the function
};

struct Entry symTabItems[100];
int symTabIndex = 0;
int SYMTAB_SIZE = 20;

void addItem(char *itemName, char *itemKind, char *itemType, int arrayLength, char *scope){
	

		// what about scope? should you add scope to this function?
		symTabItems[symTabIndex].itemID = symTabIndex;
		strcpy(symTabItems[symTabIndex].itemName, itemName);
		strcpy(symTabItems[symTabIndex].itemKind, itemKind);
		strcpy(symTabItems[symTabIndex].itemType, itemType);
		symTabItems[symTabIndex].arrayLength = arrayLength;
		strcpy(symTabItems[symTabIndex].scope, scope);
		symTabIndex++;
	
}

void showSymTable(){
	printf("itemID    itemName    itemKind    itemType     ArrayLength    itemSCope\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i=0; i<symTabIndex; i++){
		printf("%5d %15s  %7s  %7s %6d %15s \n",symTabItems[i].itemID, symTabItems[i].itemName, symTabItems[i].itemKind, symTabItems[i].itemType, symTabItems[i].arrayLength, symTabItems[i].scope);
	}
	

	printf("-----------------------------------------------------------------------\n");
}

int found(char itemName[50], char scope[50]){
	// Lookup an identifier in the symbol table
	// what about scope?
	// return TRUE or FALSE
	// Later on, you may want to return additional information

	// Dirty loop, becuase it counts SYMTAB_SIZE times, no matter the size of the symbol table
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return 1; // found the ID in the table
		}
	}
	return 0;
}

const char* getVariableType(char itemName[50], char scope[50]){
	//char *name = "int";
	//return name;

	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return symTabItems[i].itemType; // found the ID in the table
		}
	}
	return NULL;
}

int compareTypes(char itemName1[50], char itemName2[50],char scope[50]){
	const char* idType1 = getVariableType(itemName1, scope);
	const char* idType2 = getVariableType(itemName2, scope);
	
	printf("%s = %s\n", idType1, idType2);
	
	int typeMatch = strcmp(idType1, idType2);
	if(typeMatch == 0){
		return 1; // types are matching
	}
	else return 0;
}

// Function to find the parameters of a function based on its name and scope
int findFunctionParameters(const char* functionName, const char* scope){
	int count = 0;

	// Loop through the symbol table to find parameters of the specified function
	for (int i = 0; i < symTabIndex; i++){
		if(strcmp(symTabItems[i].itemName, functionName) == 0 && 
		   strcmp(symTabItems[i].itemKind, "Param") == 0 && 
		   strcmp(symTabItems[i].scope, scope) == 0){
			count++;
		}
	}

	return count;
}

// Function to count the number of arguments in a function call
int countArguments(const char* functionName, const char* scope){
	int count = 0;

	// Loop through the symbol table to find function calls with matching names and scope
	for (int i = 0; i < symTabIndex; i++){
		if(strcmp(symTabItems[i].itemName, functionName) == 0 && 
		   strcmp(symTabItems[i].itemKind, "Funct") == 0 && 
		   strcmp(symTabItems[i].scope, scope) == 0){
			count++;
		}
	}

	return count;
}

int countParameters(const char* functionName, const char* scope){
	int count = 0;

	for (int i = 0; i < symTabIndex; i++){
		if(strcmp(symTabItems[i].itemName, functionName) == 0 && 
		   strcmp(symTabItems[i].itemKind, "Param") == 0 && 
		   strcmp(symTabItems[i].scope, scope) == 0){
			count++;
		}
	}

	return count;
}

int areTypesCompatible(char* type1, char* type2){
	if(strcmp(type1, type2) == 0){
		// Types match exactly
		return 1;
	} else if ((strcmp(type1, "INT") == 0 && strcmp(type2, "CHAR") == 0) ||
	            strcmp(type1, "CHAR") == 0 && strcmp(type2, "INT") == 0){
					// INT and CHAR are considered compatible
					return 1;
				}
	// Types are not compatible
	return 0;
}

// int validateFunctionArgs(char* functionName, node* arguments){

// 	node* arg = arguments;
// 	node* param = expectedParams;

// 	// Look up function's expected parameter list by functionName
// 	node* expectedParams = findFunctionParameters(functionName, currentScope);


// 	// Check if the number or arguments matches number of expected parameters
// 	if(countArguments(arguments, currentScope) != countParameters(expectedParams)){
// 		printf("SEMANTIC ERROR: Argument count mismatch in function call %s\n", functionName);
// 		return 0; // Validation failed
// 	}

// 	while (arg != NULL && param != NULL){
// 		if(!areTypesCompatible(arg->type, param->type)){
// 			printf("SEMANTIC ERROR: Argument type mismatch in function call %s\n", functionName);
// 			return 0;
// 		}
// 	}

// 	// If all checks passed, the arguments are valid
// 	return 1;
// }