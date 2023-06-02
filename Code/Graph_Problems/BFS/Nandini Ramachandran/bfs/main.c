//
//  main.c
//  helloWorld
//
//  Created by Nandini Ramachandran on 5/31/23.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>

const char* printHelloWorld(void){
    char *name = "Hello World!";
    return name;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%s", printHelloWorld());
    printf("\n");
    // test hello world print
    int result = strcmp(printHelloWorld(), "Hello World!");
    assert(result == 0);
    return 0;
}



