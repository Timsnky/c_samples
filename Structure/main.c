/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
 char *str;
 int len;
};

int main(void) {
 struct node **strarray = NULL;
 int i = 0, count = 0;
 char line[1024];

 while(fgets(line, 1024, stdin) != NULL) {
  /* add ONE element to the array
  strarray = (struct node **)realloc(strarray, (count + 1) * sizeof(struct node *));

  /* allocate memory for one `struct node`
  strarray[count] = (struct node *)malloc(sizeof(struct node));

  /* copy the data into the new element (structure)
  strarray[count]->str = strdup(line);
  strarray[count]->len = strlen(line);
  count++;
 }

 /* print the array
 for(i = 0; i < count; i++) {
  printf("--\n");
  printf("[%d]->str: %s", i, strarray[i]->str);
  printf("[%d]->len: %d\n", i, strarray[i]->len);
 }

 /* free all strarray elements
 for(i = 0; i < count; i++) {
  free(strarray[i]->str);
  free(strarray[i]);
  i++;
 }
 free(strarray);

 return 0;
}



/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO: Avoid global variables.
struct data *struct_array;
int size = 0;

struct data {
    char inputA[20];
    char inputB[20];
};

/*
 * TODO: Try to avoid passing your structure (40 bytes + padding)
 * without pointer.

struct data get_data(void)
{
    struct data thisdata;

    printf("Please enter input A\n");

    /* TODO: Avoid using `scanf` for human inputs.
    scanf("%s", thisdata.inputA);

    printf("Please enter input B\n");
    scanf("%s", thisdata.inputB);

    return thisdata;
}

void Output(int n)
{
    size_t i;
    for (i = 0; i < n; i++) {
        printf("%s ", struct_array[i].inputA);
        printf("%s ", struct_array[i].inputB);
    }
}

void resizeArray(size_t n)
{
    /* TODO: Handle reallocations errors.
    struct_array = realloc(struct_array, n * sizeof *struct_array);
}

void mainMenu(void)
{
    size_t i, n;
    int p;

    /* TODO: Use a loop ?
    printf("Please select from the following options:\n");
    printf("1: Add new students to database\n");
    printf("2: Display current student database contents\n");
    printf("3: exit the program\n");
    scanf("%d", &p);

    switch (p) {
    case 1:
        printf("Please enter the number of students to register:\n");
        scanf("%u", &n);
        size += n;
        resizeArray(n);
        for (i = 0; i < n; i++)
            struct_array[i] = get_data();
        break;
    case 2:
        Output(size);
        break;
    }
}

int main(void)
{

    while(1){
        struct_array = malloc(2 * sizeof(int));
        mainMenu();
        free(struct_array);
    }

    return 0;
}*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LightComponent
{
    char name[30];
    int pin;
    int state;
    int intensity;
};
struct LightComponent lightDevice;
struct LightComponent *lightPointer = & lightDevice;;

int main()
{
    lightPointer->intensity = 1;
    strcpy(lightPointer->name,"Kitchen");
    lightPointer->pin = 52;
    lightPointer->state = 0;
    (lightPointer+1)->pin = 2;
    printf("%d \n",(lightPointer+0)->pin);
    printf("%d \n",(lightPointer+1)->pin);

    printf("%s\n",lightPointer->name  );
    printf("%d\n",lightPointer->intensity);
}
