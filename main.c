#include <stdio.h>

typedef struct{                        //struct to hold PGM data and specifications
    double width;                      //side to side psixel count 
    double height;                     //top to bottom pixel count 
    double max_value;                  //max pixel value
    unsigned char *image_array;        //array to store pgm data
    char type[3];
}Pgm;

unsigned char* ReadPGM(char file_name[], Pgm*image);

double height_calculation(void* pgm_array);

int main(void){
    Pgm current_image;
    ReadPGM("test_pgm.pgm", &current_image);
    printf("%lf %lf %lf", current_image.width, current_image.height, current_image.max_value);
    
    return 0;
}

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
   
    



}
