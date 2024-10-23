#include <stdio.h>

#define MINNUM -1000000000000000000.0
#define MAXNUM 1000000000000000000.0

// Validation function
int validate_input(double *input) 
{
    int result = scanf("%lf", input);

    if (result == EOF)
        return 0; // EOF reached
    if (result == 0) 
    {
        while (getchar() != '\n'); // Consume invalid input
        return 1; // Invalid input
    }
    return 2; // Valid input
}

int main()
{
    double left, right;
    while (1) 
    {
        printf("Please enter the cost of going left: ");
        int res = validate_input(&left);
        
        if (res == 0) 
        {
            printf("0\n");
            return 0; // Exit if EOF
        } 
        else if (res == 1) 
        {
            printf("1\n");
            return 0; // invalid input
        }

        printf("Please enter the cost of going right: ");
        res = validate_input(&right);
        if (res == 0) 
        {
            printf("0\n");
            return 0; // Exit if EOF
        } 
        else if (res == 1) 
        {
            printf("1\n");
            return 0; // Retry on invalid input
        }

        // Check if input is within bounds
        if (left < MINNUM || right < MINNUM) 
            printf("Number out of lower bound\n");
        
        else if (left > MAXNUM || right > MAXNUM)
            printf("Number out of upper bound\n");
        
        else 
        {
            // Compare and provide directions
            if (left <= right)
                printf("Go left\n");
            else
                printf("Go right\n");
        }
    }

    return 0;
}
