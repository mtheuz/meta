#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
    int fd, bytes;
    unsigned char data[3];

    const char *pDevice = "/dev/input/mice";

    // Open Mouse
    fd = open(pDevice, O_RDWR);
    if(fd == -1)
    {
        printf("ERROR Opening %s\n", pDevice);
        return -1;
    }

    int left, middle, right;
    int cord_X = 0;
    int cord_Y = 0;
    signed char x, y;
    while(1)
    {
        // Read Mouse     
        bytes = read(fd, data, sizeof(data));

        if(bytes > 0)
        {
            left = data[0] & 0x1;
            right = data[0] & 0x2;
            middle = data[0] & 0x4;

            x = data[1];
            y = data[2];
            //printf("x=%d, y=%d, btn_esqueda=%d, btn_meio=%d, btn_direito=%d\n", x, y, left, middle, right);
            if ( (cord_X+1 < 300 && cord_X-1 > 0)){
                 if (x > 0){
                        cord_X += 1;}
                 if (x < 0){
                        cord_X -= 1;}
            }

            printf("Coordenada X: %d\n", cord_X);
            system("clear");
        }   
    }
    return 0; 
}
