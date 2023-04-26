//haffman coding

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    char data;
    int freq;
    struct node *left;
    struct node *right;
};

struct node *newnode(char data, int freq)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


struct node *buildtree(char data[], int freq[], int size)
{
    struct node *left, *right, *top;
    struct node *arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = newnode(data[i], freq[i]);
    }
    while (size != 1)
    {
        left = arr[0];
        right = arr[1];
        top = newnode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        arr[0] = top;
        for (int i = 1; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j]->freq > arr[j + 1]->freq)
                {
                    struct node *temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    return arr[0];
}


void printcode(struct node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printcode(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printcode(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL)
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
        {
            printf("%d", arr[i]);
        }
        printf(" ");
    }
}

void haffmancoding(char data[], int freq[], int size)
{
    struct node *root = buildtree(data, freq, size);
    int arr[100], top = 0;
    printcode(root, arr, top);
}

int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    haffmancoding(data, freq, size);
    return 0;
}

