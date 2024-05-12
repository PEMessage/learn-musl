#include <stdio.h>
#include <string.h>

void test_header(const char *funcname) {
    printf("=========================\n");
    printf("FUNCNAME: %s\n",funcname);
    printf("=========================\n");
}



int test_strtok() {
    // THIS NOT WORK: segmentation-fault
    //      char *str = "Hello World, this is a test" ;
    //
    // The problem is that you're attempting to modify a string literal.
    // Doing so causes your program's behavior to be undefined.
    // See: https://stackoverflow.com/questions/8957829/strtok-segmentation-fault
    //
    // Note: 
    //      if using :
    //      `char *str = "XXX"` is equal to `char const *str = "XXX"`
    //      could easily reproduce this problem by add const to char[]
    //      `const char str[] = "Hello World, this is a test" ;`
    test_header(__func__);

    char str[] = "Hello World, this is a test" ;
    printf("This is arg1: %s\n",str);
    printf("This is arg2: \" \"\n");


    char *cmd = strtok((char *)str, " ");
    printf("This is retrun: %s\n",cmd);
    // >>> x/29c cmd
    // 0x7fffffffdab0: 72 'H'  101 'e' 108 'l' 108 'l' 111 'o' 0 '\000'        87 'W'  111 'o'
    // 0x7fffffffdab8: 114 'r' 108 'l' 100 'd' 44 ','  32 ' '  116 't' 104 'h' 105 'i'
    // 0x7fffffffdac0: 115 's' 32 ' '  105 'i' 115 's' 32 ' '  97 'a'  32 ' '  116 't'
    // 0x7fffffffdac8: 101 'e' 115 's' 116 't' 0 '\000'        -1 '\377'

    if ( cmd == NULL ) return 1;
    return 0;

}

void test_strspn(void) {
    test_header(__func__);
    char *a = "1";
    char *b = "12";
    char *a1 = "2";
    char *b1 = "21";
    char *c = "123456789";

    printf("strcspn '%s' '%s' = %lu\n",c,a,strcspn(c,a) );
    printf("strcspn '%s' '%s' = %lu\n",c,b,strcspn(c,b) );
    printf("strcspn '%s' '%s' = %lu\n",c,a1,strcspn(c,a1) );
    printf("strcspn '%s' '%s' = %lu\n",c,b1,strcspn(c,b1) );

    printf("strspn '%s' '%s' = %lu\n",c,a,strspn(c,a) );
    printf("strspn '%s' '%s' = %lu\n",c,b,strspn(c,b) );
    printf("strspn '%s' '%s' = %lu\n",c,a1,strspn(c,a1) );
    printf("strspn '%s' '%s' = %lu\n",c,b1,strspn(c,b1) );

    char *d = "7";
    char *f = "78";
    char *g = "789";
    printf("strcspn '%s' '%s' = %lu\n",c,d,strcspn(c,d) );
    printf("strcspn '%s' '%s' = %lu\n",c,f,strcspn(c,f) );
    printf("strcspn '%s' '%s' = %lu\n",c,g,strcspn(c,g) );

    printf("strspn '%s' '%s' = %lu\n",c,d,strspn(c,d) );
    printf("strspn '%s' '%s' = %lu\n",c,f,strspn(c,f) );
    printf("strspn '%s' '%s' = %lu\n",c,g,strspn(c,g) );
}

int main()
{
    test_strtok();
    test_strspn();
    return 0;
}
