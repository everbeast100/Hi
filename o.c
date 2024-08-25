#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
int info; 
struct node *next; 
} *start; 
struct node* create_node(int); 
void insert_begin(); 
void insert_last(); 
void insert_pos(); 
void delete_begin(); 
void delete_last(); 
void delete_pos(); 
void search(); 
void display(); 
int main() 
{ 
int choice; 
start = NULL; 
do 
{ 
printf("---------------------------------\n"); 
printf("Operations on singly linked list\n"); 
printf("---------------------------------\n"); 
printf("1. Insert at first\n"); 
printf("2. Insert at last\n"); 
printf("3. Insert at position\n"); 
printf("4. Delete at first\n"); 
printf("5. Delete at Last\n"); 
printf("6. Delete at position\n"); 
printf("7. Search\n"); 
printf("8. Display\n"); 
printf("9. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) 
{
case 1: 
insert_begin(); 
display(); 
break; 
case 2: 
insert_last(); 
display(); 
break; 
case 3: 
insert_pos(); 
display(); 
break; 
case 4: 
delete_begin(); 
display(); 
break; 
case 5: 
delete_last(); 
display(); 
break; 
case 6: 
delete_pos(); 
display(); 
break; 
case 7: 
search(); 
display(); 
break; 
case 8:
display(); 
break; 
case 9: 
exit(0); 
break; 
default:printf("Wrong choice...???\n"); 
 break; 
} 
} while (choice != 9); 
return 0; 
} 
struct node* create_node(int value) 
{ 
struct node *temp; 
temp = (struct node*)malloc(sizeof(struct node)); 
if (temp == NULL) 
{ 
printf("Memory not allocated\n"); 
return NULL; 
} 
else 
{ 
temp->info = value; 
temp->next = NULL; 
return temp; 
} 
} 
void insert_begin() 
{ 
int value; 
printf("Enter the value to be inserted: "); 
scanf("%d", &value); 
struct node *temp, *s; 
temp = create_node(value); 
if (start == NULL) 
{ 
start = temp; 
start->next = NULL; 
printf("%d is inserted at first in the empty list\n", temp->info); 
} 
else 
{ 
s = start; 
start = temp; 
start->next = s; 
printf("%d is inserted at first\n", temp->info); 
} 
} 
void insert_last() 
{ 
int value; 
printf("Enter the value to be inserted: "); 
scanf("%d", &value); 
struct node *temp, *s; 
temp = create_node(value); 
if (start == NULL) 
{ 
start = temp; 
start->next = NULL; 
printf("%d is inserted at last in the empty list\n", temp->info); 
} 
else 
{ 
s = start; 
while (s->next != NULL) 
{ 
s = s->next; 
}
temp->next = NULL; 
s->next = temp; 
printf("%d is inserted at last\n", temp->info); 
} 
} 
void insert_pos() 
{ 
int value, pos, counter = 0, loc = 1; 
struct node *temp, *s, *ptr; 
s = start; 
while (s != NULL) 
{ 
s = s->next; 
counter++; 
} 
if (counter == 0) 
{ 
printf("List is empty\n"); 
} 
else 
{ 
printf("Enter the position from %d to %d: ", loc, counter + 1); 
scanf("%d", &pos); 
s = start; 
if (pos == 1) 
{ 
printf("Enter the value to be inserted: "); 
scanf("%d", &value); 
temp = create_node(value); 
start = temp; 
start->next = s; 
printf("%d is inserted at first\n", temp->info); 
} 
else if (pos > 1 && pos <= counter) 
{ 
printf("Enter the value to be inserted: "); 
scanf("%d", &value); 
temp = create_node(value); 
for (int i = 1; i < pos; i++) 
{ 
ptr = s; 
s = s->next; 
} 
ptr->next = temp; 
temp->next = s; 
printf("%d is inserted at position %d\n", temp->info, pos); 
} 
else if (pos == counter + 1) 
{ 
printf("Enter the value to be inserted: "); 
scanf("%d", &value); 
temp = create_node(value); 
while (s->next != NULL) 
{ 
s = s->next; 
} 
temp->next = NULL; 
s->next = temp; 
printf("%d is inserted at last\n", temp->info); 
} 
else 
{ 
printf("Position out of range...!!!\n"); 
} 
} 
} 
void delete_begin() 
{ 
if (start == NULL) 
{ 
printf("List is empty\n"); 
} 
else 
{ 
struct node *s; 
s = start; 
start = s->next; 
printf("%d deleted from first\n", s->info); 
free(s); 
} 
}
void delete_last() 
{ 
int i, counter = 0; 
struct node *s, *ptr; 
if (start == NULL) 
{ 
printf("List is empty\n"); 
} 
else 
{ 
s = start; 
while (s != NULL) 
{ 
s = s->next; 
counter++; 
} 
s = start; 
if (counter == 1) 
{ 
start = s->next; 
printf("%d deleted from last\n", s->info); 
free(s); 
} 
else 
{ 
for (i = 1; i < counter; i++) 
{ 
ptr = s; 
s = s->next; 
} 
ptr->next = s->next; 
printf("%d deleted from last\n", s->info); 
free(s); 
} 
} 
} 
void delete_pos() 
{ 
int pos, i, counter = 0, loc = 1; 
struct node *s, *ptr; 
s = start; 
while (s != NULL) 
{ 
s = s->next; 
counter++; 
} 
if (counter == 0) 
{ 
printf("List is empty\n"); 
} 
else 
{ 
printf("Enter the position from %d to %d: ", loc, counter); 
scanf("%d", &pos); 
s = start; 
if (pos == 1) 
{ 
start = s->next; 
printf("%d deleted from first\n", s->info); 
free(s); 
} 
else if (pos > 1 && pos <= counter) 
{ 
for (i = 1; i < pos; i++) 
{ 
ptr = s; 
s = s->next; 
} 
ptr->next = s->next; 
if (pos == counter) 
{ 
printf("%d deleted from last\n", s->info); 
free(s); 
} 
else 
{ 
printf("%d deleted from position %d\n", s->info, pos); 
free(s); 
 } 
} 
else 
{ 
printf("Position out of range...!!!\n"); 
} 
} 
} 
void search() 
{ 
int value, loc = 0, pos = 0, counter = 0; 
struct node *s; 
s = start; 
while (s != NULL) 
{ 
s = s->next; 
counter++; 
} 
if (start == NULL) 
{ 
printf("List is empty\n"); 
} 
else 
{ 
printf("Enter the value to be searched: "); 
scanf("%d", &value); 
s = start; 
while (s != NULL) 
{ 
pos++; 
if (s->info == value) 
{ 
loc++; 
if (loc == 1) 
 { 
 printf("Element %d is found at position %d", 
value, pos);
} 
else if (loc <= counter) 
{ 
printf(" , %d", pos); 
} 
}
s = s->next; 
} 
printf("\n"); 
if (loc == 0) 
{ 
printf("Element %d not found in the list\n", value); 
} 
} 
} 
void display() 
{ 
struct node *temp; 
if (start == NULL) 
{ 
printf("Linked list is empty...!!!\n"); 
} 
else 
{ 
printf("Linked list contains: "); 
temp = start; 
while (temp != NULL) 
{ 
printf("%d ", temp->info); 
temp = temp->next; 
} 
printf("\n"); 
} 
}