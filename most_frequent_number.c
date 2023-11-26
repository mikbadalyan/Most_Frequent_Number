#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <errno.h>
#include <ctype.h> 
// #include "binary_search_tree.c"
#define N 1000

int insert();
int print_tree();
int most_frequent_number();

int main(){
    //1. For reading the file.
    char buf[N];
    int fd = open("nums.txt", O_RDONLY);
    if (-1 == fd) {
        perror("Cannot open file");
        return errno;
    }
    ssize_t bytes = read(fd, buf, N);
    if (-1 == bytes) {
        perror("Cannot read file");
        return errno;
    }
    buf[bytes] = '\0';
    close(fd);
    //1.

    //2. Getting strings from the file and changing the type to integer.
    int num[bytes];
    int k = -1;
  
    if(isdigit(buf[0])){
        num[0] = atoi(&buf[0]);
        k = 0;
    }
    
    for(int i = 0; i < bytes; ++i){
        if(isdigit(buf[i])){
            continue;
        }else if(isdigit(buf[i+1])){
            k = k + 1;
            buf[i] = '\0';
            num[k] = atoi(&buf[i+1]);
        }
    }

    for(int g = k+1; g < bytes; ++g){
        num[g] = '\0';
    }
    //2.

    //3. This part of the code insert it in binary search tree while counting the quantity of numbers
    int most_num = 0;
    struct Node * root = 0;
    for(int ins = 0; ins < k + 1; ++ins){
        int sd = insert(&root, num[ins]);
        if (-1 == sd) {
        perror("Cannot insert the function.");
        return errno;
    }
    }
    int mk = print_tree(&root);
    if (-1 == mk) {
        perror("Cannot show the result: Check the file, its content");
        return errno;
    }
    
    int rt = most_frequent_number(most_num);
    if (-1 == rt) {
        perror("Cannot show the most frequent number: Check the file, its content");
        return errno;
    }
    //3.
    return 0;
}