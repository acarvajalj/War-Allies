#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node for the linked list
typedef struct node {
    char* country;
    struct node* best_ally;
    struct node* next;
}Node;


int main() {
    Node* head = NULL;
    Node* current = NULL;

    // Get input of country names and create nodes for them
    char input[50];
    printf("Enter nation name : ");
    fgets(input, sizeof(input), stdin);
    
    //Allocate memory for new node and name of the country inside said node 
    while (input[0] != '\n') {// Termination condition is enter key
        
        Node* new_node = malloc(sizeof(Node));
        char* country_name = malloc(strlen(input));
        strcpy(country_name, input);
        country_name[strlen(input) - 1] = '\0'; // makes sure the last character of the string is a null
        new_node->country = country_name;
        new_node->best_ally = NULL;
        new_node->next = NULL;

        // Add new node to linked list
        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }

        // Get next country name
        printf("Enter nation name : ");
        fgets(input, sizeof(input), stdin);
    }

    // Get input for best allies and set pointers in nodes
    current = head;
    while (current != NULL) {
        char best_ally[50];
        printf("Enter best ally name for %s : ", current->country);
        fgets(best_ally, sizeof(best_ally), stdin);
        best_ally[strlen(best_ally) - 1] = '\0';

        // Find node for best ally
        Node* ally_node = head;
        while (ally_node != NULL && strcmp(ally_node->country, best_ally) != 0) {
            ally_node = ally_node->next;
        }

        if (ally_node == NULL) {
            printf("Could not find country %s. Please try again.\n", best_ally);
        } else {
            current->best_ally = ally_node;
            current = current->next;
        }
    }

    // Print out best allies for each country
    current = head;
    while (current != NULL) {
        printf("The best ally of %s is %s\n", current->country, current->best_ally->country);
        current = current->next;
    }

    // Free malloced memory
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->country);
        free(temp);
    }

    return 0;
}

