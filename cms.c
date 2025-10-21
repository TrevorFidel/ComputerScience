#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Struct > its a user defined data types that allows one to combine different types of variables under a single name.
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
    /* data */
};

// Void functions > functions that dont return any value, no input parameters or fixed type.
// USAGE: 1. Action-only functions(void saveData())
//        2. Callback functions (used in event handling, e.g., button click events in GUI applications)

void addContact();
void viewContact();
void searchContact();

int main() {

    int choice;
    int running = 1;
   // while (1) > creates an infinite loop that keeps the programr running and showing the menu
   // again after the action only stops when either exit(0) or a break that ends a loop is used.
   // Switch(choice) > decides what action to take based on the user input in refer to the menu options.
   // case  blocks > each case corresponds to a menu option and calls the appropriate function(add, view, search)
   // break > exits that case and returns to the main menu.
   // exit(0) > terminates the program when the user chooses to exit.
   //  # While loop runs indefinetely until you manually break or exit the program.
   //  # Forloop Usually runs a specific number of times(Has a condition/counter)
    while(running){
        printf("--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar(); // to consume the newline character left by scanf; ensures 1. user input aint skipped
        // 2. Program waits for user input properly before redrawing the main menu.
        switch (choice){
            case 1:
                addContact();
                break;
            case 2:
                viewContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                running = 0;
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;

        }
        

    }
    

    return 0;
}




// Function to add a new contact
// 1. Prompts the user to enter contact details(name, phone, email).
// 2. Stores the entered details in a binary file(contacts.dat) for persistent storage
void addContact(){
    struct Contact c; // create a contact variable c of type struct Contact.
    FILE *fp = fopen("contacts.dat","ab"); // Opens or creates  a  binary file named contacts.dat in append-binary mode.
    // 'ab' mode allows new contact data to be added at the end of the file without overwriting existing data.
    if (fp == NULL) // Error handling for file opening
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter name:");
    fgets(c.name,50,stdin);// reads line of text from standard input preventing buffer overflow by limiting input to size of c.name
    c.name[strcspn(c.name,"\n")] = '\0';
    
    printf("Enter phone number:");
    fgets(c.phone,20,stdin);
    c.phone[strcspn(c.phone,"\n")] = '\0';

    printf("Enter email:");
    fgets(c.email,50,stdin);
    c.email[strcspn(c.email,"\n")] = '\0';

    fwrite(&c,sizeof(struct Contact),1,fp); // writes the contact struct c to the file pointed by fp.
    fclose(fp); // closes the file to ensure data is saved and resources are freed.
    printf("Contact added successfully!\n");
    
}
void viewContact(){
    struct Contact c;
    FILE *fp = fopen("contacts.dat","rb"); // Opens the contacts.dat file in read-binary mode.
    if (fp == NULL){
        printf("No contact found!\n");
        return;
    }
    
    printf("--- Contact List ---\n");
    while (fread(&c,sizeof(struct Contact),1,fp)){ // reads each contact from the file until EOF
        printf("Name: %s\n",c.name);
        printf("Phone: %s\n",c.phone);
        printf("Email: %s\n",c.email);
        printf("-------------------\n");
    }
    fclose(fp); // closes the file after reading all contacts.

}
void searchContact(){
    char name[50];
    struct Contact c;
    FILE *fp = fopen("contacts.dat","rb"); // Opens the contacts.dat file in read-binary mode.
    if (fp == NULL){
        printf("No contact found!\n");
        return;
    }

    printf("Enter name to search: ");
    fgets(name,50,stdin);
    name[strcspn(name,"\n")] = '\0';

    int found = 0;
    while (fread(&c,sizeof(struct Contact),1,fp)){ // reads each contact from the file until EOF
        if (strcmp(c.name,name) == 0){ // compares the input name with the contact's name
            printf("Contact Found:\n");
            printf("Name: %s\n",c.name);
            printf("Phone: %s\n",c.phone);
            printf("Email: %s\n",c.email);
            found = 1;
            break;
        }
    }
    if (!found){
        printf("Contact not found!\n");
    }
    fclose(fp); // closes the file after searching.
}