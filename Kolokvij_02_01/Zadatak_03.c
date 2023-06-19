



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsValidIP(char ip[] )
{
    char temp[15];                 // samo zbog ispisa
                                   // samo zbog ispisa
    if (strlen(ip) > 15)           // samo zbog ispisa
    {                              // samo zbog ispisa
        return 0;                  // samo zbog ispisa
    }                              // samo zbog ispisa
                                   // samo zbog ispisa
    strcpy(temp, ip);              // samo zbog ispisa

    char* token = strtok(temp, ".");
    int splitCount = 1;

    while (1)
    {
        if (splitCount > 4)
        {
            return 0;
        }

        int num = atoi(token);
        if (num < 0 || num > 255)
        {
            return 0;
        }

        token = strtok(NULL, ".");

        if (token == NULL)
        {
            if (splitCount < 4)
            {
                return 0;
            }
            break;
        }
        splitCount++;
    }

    return 1;
}


int main(void)
{
    //char ipAddresses[][15] = { "192.168.0.1", "278.168.0.1", "0.0.0.0.", "192.-1.0.1", "192.168.120.1", "32.43.0.1", "17.125.0.1", "742.168.0.1", "1.1.0.1.1.1", "192.168.100" };
    //for (int i = 0; i < 10; i++)
    //{
    //    printf("%s : %d\n", ipAddresses[i], IsValidIP(ipAddresses[i]));
    //}


    char ip[15] = "192.168.0.1";
    printf("%s : %d\n", ip, IsValidIP(ip));
}
