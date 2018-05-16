//
// APS105 Lab 8 Lab8.c
//
// This is a program written to maintain a personal music library, 
// using a linked list to hold the songs in the library.
//
// Author: <Kexin Li>
// Student Number: <1003978984>
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// A node in the linked list

// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.

typedef struct node {
    char *artist ;
    char *songName ;
    char *genre ;
    struct node *nextNode ;
} Node;

// Declarations of linked list functions
//
// DECLARE YOUR LINKED-LIST FUNCTIONS HERE
Node * newNode (char inputSongName[], char inputArtist[], char inputGenre[], Node * nextNode);
Node * insertIntoOrderedList (Node * head, char song[], char artist[], char genre[]);
Node * deleteNode(Node * head, char valToDelete[]);
void printList(Node * head);
Node * searchNode (Node * head, char searchKey[]);

// Declarations of support functions
// See below the main function for descriptions of what these functions do

void inputStringFromUser( char prompt[], char s[], int arraySize ) ;
void songNameDuplicate( char songName[] ) ;
void songNameFound( char songName[] ) ;
void songNameNotFound( char songName[] ) ;
void songNameDeleted( char songName[] ) ;
void artistFound( char artist[] ) ;
void artistNotFound( char artist[] ) ;
void printMusicLibraryEmpty( void ) ;
void printMusicLibraryTitle( void ) ;


const int MAX_LENGTH = 1024;

int main( void ) {
    // Declare the head of the linked list.
    Node * head = NULL;
 
    // Announce the start of the program
    printf( "Personal Music Library.\n\n" ) ;
    printf( "%s", "Commands are I (insert), D (delete), S (search by song name),\n"
         "P (print), Q (quit).\n" ) ;
    
    char response ;
    char input[ MAX_LENGTH + 1 ] ;

	
    do {
        inputStringFromUser( "\nCommand", input, MAX_LENGTH ) ;

        // Response is the first character entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper( input[0] ) ;
		
		//When the user choses to insert
        if( response == 'I' ) {
			
            // Insert a song into the linked list.
			char songInput[MAX_LENGTH + 1];
			char artistInput[MAX_LENGTH + 1];
			char genreInput[MAX_LENGTH + 1];
			char *promptName = "Song name" ;
			inputStringFromUser( promptName, songInput, MAX_LENGTH );
			char *promptArtist =  "Artist" ;
			inputStringFromUser( promptArtist, artistInput, MAX_LENGTH );
			char *promptGenre = "Genre" ;
			inputStringFromUser( promptGenre, genreInput, MAX_LENGTH );
			
            // Maintain the list in alphabetical order by song name.
			head = insertIntoOrderedList (head, songInput, artistInput, genreInput);
		
        }
		
		//When the user choses to delete
        else if( response == 'D' ) {
            // Delete a song from the list.
			char *prompt = "\nEnter the name of the song to be deleted" ;
			char songToDelete[MAX_LENGTH + 1];
			inputStringFromUser( prompt, songToDelete, MAX_LENGTH );
			head = deleteNode(head, songToDelete);
        }
		
		//When the user choses to search
        else if( response == 'S' ) {
            // Search for a song by its name.
			char searchKey[MAX_LENGTH + 1];
			char *prompt = "\nEnter the name of the song to search for" ;
			bool exist = false;
			inputStringFromUser(prompt, searchKey, MAX_LENGTH);
			head = searchNode(head, searchKey);
        }
		
		//When the user choses to print out the list
        else if( response == 'P' ) {
			// Print the music library.
			printList(head);
        }
		
		//When the user choses to quit the program
        else if( response == 'Q' ) {
            // Delete the entire linked list.
			Node * np = head;
			while (np != NULL) {
				// Print the linked list to confirm deletion.
				head = deleteNode(head, np -> songName);
				np = np -> nextNode;
			}
			printMusicLibraryEmpty();	
        } else {
            // do this if no command matched ...
            printf( "\nInvalid command.\n" ) ;
        }
    } while( response != 'Q' ) ;
  
    return 0 ;
}

// Support Function Definitions

// Prompt the user for a string safely, without buffer overflow
void inputStringFromUser(char prompt[], char s[], int maxStrLength) {
    int i = 0;
    char c;
    
    printf( "%s --> ", prompt ) ;
    while( i < maxStrLength && (c = getchar()) != '\n' )
        s[i++] = c ;
    s[i] = '\0' ;
}

// Function to call when the user is trying to insert a song name 
// that is already in the personal music library.
void songNameDuplicate( char songName[] ) {
    printf( "\nA song with the name '%s' is already in the music library.\n"
            "No new song entered.\n", songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound( char songName[] ) {
    printf( "\nThe song name '%s' was found in the music library.\n",
           songName ) ;
}

// Function to call when a song name was not found in the personal music library.
void songNameNotFound( char songName[] ) {
    printf( "\nThe song name '%s' was not found in the music library.\n",
           songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted( char songName[] ) {
    printf( "\nDeleting a song with name '%s' from the music library.\n",
           songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void) {
    printf( "\nThe music library is empty.\n" ) ;
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void) {
    printf( "\nMy Personal Music Library: \n" ) ;
}

// Add your functions below this line.
//Function of creating new node
Node * newNode (char inputSongName[], char inputArtist[], char inputGenre[], Node * nextNode) {
	char* song = (char*) malloc(strlen(inputSongName) * sizeof(inputSongName));
	char* artist = (char*) malloc(strlen(inputArtist) * sizeof(inputArtist));
	char* genre = (char*) malloc(strlen(inputGenre) * sizeof(inputGenre));

	
	for(int i = 0; i < strlen(inputSongName); i++){
		song[i] = inputSongName[i];
	}
	
	for(int i = 0; i < strlen(inputArtist); i++){
		artist[i] = inputArtist[i];
	}
	
	for(int i = 0; i < strlen(inputGenre); i++){
		genre[i] = inputGenre[i];
	}
	
	Node * np = (Node *) malloc(sizeof (Node));
	if (np == NULL) {
		exit(EXIT_FAILURE);
	}
	np -> songName = song;
	np -> artist = artist;
	np -> genre = genre;
	np -> nextNode = nextNode;
	return np;
}

//Function of searching for one specific node
Node * searchNode (Node * head, char searchKey[]) {
	
		Node *current = head;
		while (current != NULL) {
			if (strcmp (current ->songName, searchKey) == 0) {
				songNameFound( searchKey );
				printf ("\n");
				printf ("%s\n", current -> songName);
				printf ("%s\n", current -> artist);
				printf ("%s\n", current -> genre);
				return head;
			} else {
				current = current -> nextNode;
			}
		}
	songNameNotFound( searchKey );
	return head;
}

//Function to print
void printList(Node * head) {
	Node * np = head;

	if (head == NULL) {
		printMusicLibraryEmpty( );
	} else {
		printMusicLibraryTitle( );
		while (np != NULL) {
			printf ("%s\n", np -> songName);
			printf ("%s\n", np -> artist);
			printf ("%s\n", np -> genre);
			np = np -> nextNode;
		}
	}
}


//Function of deleting a node
Node * deleteNode(Node * head, char valToDelete[]) {	
	
	while (head != NULL && strcmp (head -> songName, valToDelete) == 0){
		Node * firstNode = head;
		head = head -> nextNode;
		printf( "\nDeleting a song with name '%s' from the music library.\n", valToDelete);
		free (firstNode);
	}
	
	if (head != NULL) {
		Node *current = head;
		while (current -> nextNode != NULL) {
			if (strcmp (current -> nextNode ->songName, valToDelete) == 0) {
				
				Node * nodeToRemove = current -> nextNode;
				current -> nextNode = current -> nextNode -> nextNode;
				printf( "\nDeleting a song with name '%s' from the music library.\n", valToDelete);
				free (nodeToRemove);
				
			} else {
				
				current = current -> nextNode;
			}
		}
	}
	
	return head;
	
	

}

//Function for insertion
Node * insertIntoOrderedList (Node * head, char song[], char artist[], char genre[]) {
	Node * np = head;
	
	//For the cases when list is empty or has one node
	if (head == NULL || strcmp(song, head -> songName) < 0 ) {
		return newNode(song, artist, genre, head);
	}

	//For the case if the node already exists
	if (head -> nextNode == NULL) {
		if (strcmp(song, head -> songName) == 0) {
			songNameDuplicate( song ) ;
			return head;
		} 
	}	
	
	//For the other cases
	while ((np -> nextNode != NULL) && (strcmp (song, np -> nextNode -> songName) >= 0)) {
		
		if ( strcmp (song, np -> nextNode-> songName) == 0) {
			songNameDuplicate( song ) ;
			return head;
		}
		np = np -> nextNode;
		
	}

	np -> nextNode = newNode(song, artist, genre, np -> nextNode);
	return head;
}

