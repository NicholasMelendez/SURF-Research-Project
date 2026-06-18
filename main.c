#include <stdio.h>
#include <stdlib.h>
#include <strings.h>





//struct to hold image width, height, max_value in pixels, array of data, and type. Correct type for binary pgm is "P5"

typedef struct{                      
    double width;                      
    double height;                    
    double max_value;                  
    unsigned char *image_array;        
    char type[3];
}Pgm;

unsigned char* ReadPGM(char file_name[], Pgm*image);

double height_calculation(Pgm* image);


//currently experimenting with test pgm
int main(void){
    Pgm current_image;
    ReadPGM("test_pgm.pgm", &current_image);
    printf("%lf %lf %lf\n", current_image.width, current_image.height, current_image.max_value);
    height_calculation(&current_image);

    return 0;
}







//ensures file type is correct, reads values from pgm to allocate enough memory, puts data into array
unsigned char* ReadPGM(char filename[], Pgm *image){
    char c;
    char *type = (image->type); //poitner to type string
    int index = 0;
    FILE *current_pgm = fopen(filename, "rb");
    


    if(current_pgm == NULL){                            //Make sure file successfully opened
        printf("Error opening file\n");
        return NULL;
    }
    fread(type, sizeof(char), 3, current_pgm);
    type[2] = '\0';     //include null terminator


    if(!(type[0] == 'P' && type[1] =='5')){             //make sure we have correct file type
         printf("Not a binary PGM File!\n");
    }

    fscanf(current_pgm, "%lf %lf %lf",&(image->width), &(image->height), &(image->max_value));    //Obtain pgm width, height, and maximum value
    image -> image_array = malloc((image-> height)* ( image -> width)*sizeof(char));
    fread(image->image_array, sizeof(char), (image->height) * (image->width), current_pgm);

}
double height_calculation(Pgm *image){
    int items = image->height * image->width;
    printf("%d", items);
    for(int i = 0; i<items; i++){
        printf("%c\n", image ->image_array[i]);
    }
}
