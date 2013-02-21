#include <stdio.h>
#include <string.h>

static int counter = 0;
extern char Here, Start, End;

int main()
{
        asm volatile( "Here:" );
        printf("/* Program invoked.\n");
        printf("Hello World!\n");
        memcpy(&Here, &Start, (int) &End - (int) &Start);
        printf("  #%d */\n", ++counter);
        return 0;
}

void dummyCodeContext()
{
        int (*callPrintf)( const char *format, ... );

        asm volatile( "Start:" );
        (*(callPrintf = &printf))( "/* Dummy code context invoked.\n");
        asm volatile( "End:" );
}

