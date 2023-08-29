#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree = NULL;
struct node *insert(struct node * ,int);
void pretrav(struct node *);
void intrav(struct node *);
void postrav(struct node *);
struct node *small(struct node *);
struct node *large(struct node *);
void del(struct node * , int);
int total(struct node *);
int internal(struct node *);
int external(struct node *);
int height(struct node *);
void image(struct node *);
void deltree(struct node *);
int main()
{
    int ch , num;
    struct node *ptr = NULL;
    do
    {
        printf("\n1.Insert a node.");
        printf("\n2.Pre-order traversal. ");
        printf("\n3.Post-order traversal");
        printf("\n4.In-order traversal.");
        printf("\n5.Find the smallest node.");
        printf("\n6.Find the largest node.");
        printf("\n7.Delete a node.");
        printf("\n8.Total number of nodes.");
        printf("\n9.Total number of internal nodes.");
        printf("\n10.Total number of external nodes");
        printf("\n11.Height of the Tree.");
        printf("\n12.Mirror image of the Tree.");
        printf("\n13.Delete the Tree.");
        printf("\n14.Exit");
        printf("\n\t\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("\nenter the value to be added :");
                     scanf("%d",&num);
                     tree = insert(tree , num);
                     break;
            case 2 : if(tree == NULL)
                        printf("\ntree is empty .");
                     else
                     {
                         printf("\nelments in the tree are :");
                         pretrav(tree);
                     }
                     break;
            case 3 : if(tree == NULL)
                        printf("\ntree is empty .");
                     else
                     {
                         printf("\nelments in the tree are :");
                         intrav(tree);
                     }
                     break;
            case 4 : if(tree == NULL)
                        printf("\ntree is empty .");
                     else
                     {
                         printf("\nelments in the tree are :");
                         postrav(tree);
                     }
                     break;
            case 5 : if(tree == NULL)
                        printf("\ntree is empty .");
                     else
                     {
                         ptr = large(tree);
                         printf("\nlargest element in the tree is : %d",ptr -> data);
                     }
                     break;
            case 6 : if(tree == NULL)
                        printf("\ntree is empty .");
                     else
                     {
                         ptr = large(tree);
                         printf("\nlargest element in the tree is : %d",ptr -> data);
                     }
                     break;
            case 7 : printf("\nenter the number to be deleted : ");
                     scanf("%d",&num);
                     if(tree == NULL)
                        printf("\ntree is empty .");
                     else
                     {
                        del(tree , num);
                        printf("\ntree updated successfully .");
                     }
                     break;
            case 8 : printf("\ntotal nodes present in the tree are : %d",total(tree));
                     break;
            case 9 : printf("\ntotal number of internal nodes present are : %d",internal(tree));
                     break;
            case 10 : printf("\ntoal number of external nodes present are : %d",external(tree));
                      break;
            case 11 : printf("\nheight of the tree is : %d",height(tree));
                      break;
            case 12 : image(tree);
                      break;
            case 13 : deltree(tree);
                      printf("\ntask completed successfully .");
                      break;
            case 14 : break;
            default : printf("\nInvalid choice !!! . choose again - ");
                      break;
        }
    }while(ch!=14);
}
struct node *insert(struct node *tree , int num)
{
    struct node *ptr , *nodeptr , *parent ;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr -> data = num;
    ptr -> left = NULL;
    ptr -> right = NULL;
    if(tree == NULL)
    {
        tree = ptr;
        tree -> data = num;
        tree -> left = tree -> right = NULL;
    }
    else
    {
        parent = NULL;
        nodeptr = tree;
        while(nodeptr !=NULL)
        {
            parent = nodeptr;
            if(num < nodeptr -> data)
                nodeptr = nodeptr -> left;
            else
                nodeptr = nodeptr -> right;
        }
        if(num < parent -> data)
            parent -> left = ptr;
        else
            parent -> right = ptr;
    }
    return tree;
}
void pretrav(struct node *tree)
{
    if(tree != NULL)
    {
        printf("%d ",tree -> data);
        pretrav(tree ->  left);
        pretrav(tree -> right);
    }
}
void intrav(struct node *tree)
{
    if(tree != NULL)
    {
        intrav(tree ->left);
        printf("%d",tree -> data);
        intrav(tree -> right);
    }
}
void postrav(struct node *tree)
{
    if(tree !=NULL)
    {
        postrav(tree -> left);
        postrav(tree -> right);
        printf("%d",tree -> data);
    }
}
struct node *small(struct node *tree)
{
    if(tree -> left == NULL || tree == NULL)
        return tree;
    else
    {
        small(tree -> left);
    }
}
struct node *large(struct node *tree)
{
    if(tree -> right == NULL || tree == NULL)
        return tree;
    else
    {
        large(tree -> right);
    }
}
void del(struct node *tree , int num)
{
    if(tree == NULL)
        printf("\noops element not found !");
    else if(num < tree -> data)
    {
        del(tree -> left , num);
    }
    else if (num > tree -> data)
    {
        del(tree -> right , num);
    }
    else
    {
        if(tree -> left == NULL && tree -> right != NULL)
        {
            struct node *ptr = tree ;
            tree = tree -> right;
            free(ptr);
        }
        else if(tree -> left != NULL && tree -> right == NULL)
        {
            struct node *ptr = tree;
            tree =  tree -> left;
            free(ptr);
        }
        else if(tree -> left != NULL && tree -> right != NULL)
        {
            struct node * temp = large(tree -> left);
            tree -> data = temp -> data;
            free(temp);
        }
        else
        {
            free(tree);
        }
    }
}
int total(struct node *tree)
{
    if(tree == NULL)
        return 0;
    else
        return total(tree -> left) + total(tree -> right) + 1;
}
int internal(struct node *tree)
{
    if(tree == NULL)
        return 0;
    else if(tree -> left == NULL && tree -> right == NULL)
        return 0;
    else
    {
        return internal(tree -> left) + internal(tree -> right) +1 ;
    }
}
int external(struct node *tree)
{
    if(tree == NULL)
        return 0;
    else if(tree -> left == NULL && tree -> right == NULL)
        return 1;
    else
    {
        return external(tree -> left) + external(tree -> right);
    }
}
int height(struct node *tree)
{
    if(tree == NULL)
        return 0;
    else
    {
        int lefthght = height(tree -> left);
        int righthght = height(tree -> right);
        if(lefthght >= righthght)
            return lefthght +1;
        else
            return righthght +1;
    }
}
void image(struct node *tree)
{
    if(tree == NULL)
        printf("\noops tree is empty.");
    else
    {
        image(tree -> left);
        image(tree -> right);
        struct node * temp;
        temp = tree -> left;
        tree -> left = tree -> right;
        tree -> right = temp;
        free(temp);
    }
}
void deltree(struct node *tree)
{
    if(tree != NULL)
    {
        deltree(tree -> left);
        deltree(tree -> right);
        free(tree);
    }
}
