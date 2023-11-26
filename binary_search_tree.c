#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <errno.h>
#include <ctype.h> 

struct Node {
    int value; 
    int count;
    struct Node *left, *right; 
};

int most = 1;
int most_num = -1;


int insert(struct Node** root, int value){
    if (0 == *root){
        *root = malloc(sizeof(struct Node));
        (*root)->value = value;
        (*root)->count = 1;
        (*root)->left = 0;
        (*root)->right = 0;
        
    }
    else if(value < (*root)->value){
        insert(&((*root)->left), value);
        
    }
    else if (value > (*root)->value){
        insert(&((*root)->right), value);
        
    }
    else if (value == (*root)->value){
        (*root)->count++;
        if((*root)->count > most){
            most = (*root)->count;
            most_num = (*root)->value;
        }
        
    }else{
        return -1;
    }
    return 0;
}

/**
 * @brief This functions shows all paretns and child of the binary search tree, its values and quantities.
 * 
 * @param root is a parent and child sometimes.
 * @return int returns values if the code work properly. 
 */
int print_tree(struct Node** root){
    if (0 != (*root)){
        print_tree(&((*root)->left));
        printf("%d - ", (*root)->value);
        printf("%d times |||| \n\n", (*root)->count);
        
        print_tree(&((*root)->right));
        
    }else{
        return -1;
    }
    return 0;
}


int most_frequent_number(int most_n){
    if(most_num != -1){
        most_n = most_num;
        printf("Most Frequent Number is %d\n", most_num);
    }else{
        return -1;
    }
    return 0;
}
