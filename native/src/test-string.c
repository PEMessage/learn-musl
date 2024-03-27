#include <stdio.h>
#include <string.h>


char *str = "Hello World, this is a test" ;

int test_strtok() {
    char *cmd = strtok(str, " ");
    if ( cmd == NULL ) return 1;
    return 0;

}

void test_strspn(void) {
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
