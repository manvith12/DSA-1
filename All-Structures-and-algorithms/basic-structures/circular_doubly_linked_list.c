#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct CD_List
{
    Node *head;
} CD_List;

CD_List *create_list()
{
    CD_List *list = (CD_List *)malloc(sizeof(CD_List));
    list->head = NULL;
    return list;
}

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node;
    new_node->prev = new_node;
    return new_node;
}

void insert(CD_List *list)
{
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    Node *new_node = create_node(data);

    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        Node *tail = list->head->prev;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = list->head;
        list->head->prev = new_node;
    }
}

int locate(CD_List *list, int data)
{
    if (list->head == NULL)
        return -1;

    Node *temp = list->head;
    int index = 0;
    do
    {
        if (temp->data == data)
            return index;
        temp = temp->next;
        index++;
    } while (temp != list->head);

    return -1;
}

int retrieve(CD_List *list, int index)
{
    if (list->head == NULL)
        return -1;

    Node *temp = list->head;
    int count = 0;
    do
    {
        if (count == index)
            return temp->data;
        temp = temp->next;
        count++;
    } while (temp != list->head);

    return -1;
}

void delete_index(CD_List *list, int index)
{
    if (list->head == NULL)
        return;

    Node *temp = list->head;
    int count = 0;
    do
    {
        if (count == index)
        {
            if (temp->next == temp)
            { // Single node case
                free(temp);
                list->head = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == list->head)
                    list->head = temp->next;
                free(temp);
            }
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != list->head);
}

void print_list(CD_List *list)
{
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = list->head;
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(HEAD)\n");
}

void destroy_list(CD_List *list)
{
    if (list->head == NULL)
    {
        free(list);
        return;
    }

    Node *temp = list->head;
    Node *next_node;
    do
    {
        next_node = temp->next;
        free(temp);
        temp = next_node;
    } while (temp != list->head);

    free(list);
}

int main()
{
    int choice, index, value;
    CD_List *list = NULL;

    while (1)
    {
        printf("1. Create List\n");
        printf("2. Insert\n");
        printf("3. Locate\n");
        printf("4. Retrieve\n");
        printf("5. Delete by Index\n");
        printf("6. Print List\n");
        printf("7. Destroy List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (list != NULL)
            {
                destroy_list(list);
            }
            list = create_list();
            printf("List created.\n");
            break;
        case 2:
            if (list == NULL)
            {
                printf("Create a list first.\n");
                break;
            }
            insert(list);
            break;
        case 3:
            if (list == NULL)
            {
                printf("Create a list first.\n");
                break;
            }
            printf("Enter value to locate: ");
            scanf("%d", &value);
            index = locate(list, value);
            if (index == -1)
            {
                printf("Value not found.\n");
            }
            else
            {
                printf("Value found at index %d.\n", index);
            }
            break;
        case 4:
            if (list == NULL)
            {
                printf("Create a list first.\n");
                break;
            }
            printf("Enter index to retrieve: ");
            scanf("%d", &index);
            value = retrieve(list, index);
            if (value == -1)
            {
                printf("Invalid index.\n");
            }
            else
            {
                printf("Value at index %d is %d.\n", index, value);
            }
            break;
        case 5:
            if (list == NULL)
            {
                printf("Create a list first.\n");
                break;
            }
            printf("Enter index to delete: ");
            scanf("%d", &index);
            delete_index(list, index);
            printf("Deleted element at index %d.\n", index);
            break;
        case 6:
            if (list == NULL)
            {
                printf("Create a list first.\n");
                break;
            }
            print_list(list);
            break;
        case 7:
            if (list == NULL)
            {
                printf("No list to destroy.\n");
                break;
            }
            destroy_list(list);
            list = NULL;
            printf("List destroyed.\n");
            break;
        case 8:
            if (list != NULL)
            {
                destroy_list(list);
            }
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}