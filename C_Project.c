#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct student{
char name[50];
int id;
char gender;
int academic_year;
float gpa;
};

void AddStudent(struct student students[]){
    char added_name[50],added_gender;
    int count=0,added_id, added_academic_year,empty_position, empty=0;
    float added_gpa;

//check if there is an empty position
    for(int j=0; j<50;j++)
    {
        if(students[j].id==0)
        {
            empty_position=j;
            empty=1;
            break;
        }
    }
    if (empty==1)
    {
//check the new student name validity
    puts("Enter the first and last name only for the student you want to add");
    getchar();
    gets(added_name);
    for(int i=0;i<strlen(added_name);i++)
  {
      if(added_name[i]==' ')
      {
          count++;
      }
  }
  if(count!=1)
  {
      printf("Invalid name length\n\n");
      return;
  }
//Add the new student name
strcpy(students[empty_position].name,added_name);

//check the student's ID validity
    printf("Enter the student's 7 digits ID\n");
    scanf("%d",&added_id);
    if(added_id<1000000 || added_id>9999999)
    {
        printf("Invalid input, the ID must be 7 digits\n\n");
        return;
    }
    for(int i=0;i<50;i++)
    {
        if(students[i].id==added_id)
        {
            printf("Entered ID already exists\n\n");
            return;
        }
    }
//add the ID
    students[empty_position].id=added_id;

//Check the student's gender
    printf("Enter 'M' or 'm' for male and 'F' or 'f' for female student\n");
    getchar();
    scanf("%c",&added_gender);
    if(added_gender=='M' || added_gender=='m'|| added_gender=='F' || added_gender=='f')
    {
        printf("Valid gender input\n");
//add the student's gender
        students[empty_position].gender=added_gender;
    }
    else
    {
         printf("Invalid gender input\n\n");
         return;
    }

//check the academic year validity
 printf("Enter the student's academic year\n");
        scanf("%d",&added_academic_year);
        if(added_academic_year>5 || added_academic_year<1)
        {
            printf("Invalid input, academic year must be between 1 and 5\n\n");
            return;
        }
//add the academic year
        students[empty_position].academic_year=added_academic_year;

//check the student's GPA validity
 printf("Enter the student's GPA\n");
        scanf("%f", &added_gpa);
        if(added_gpa>4 || added_gpa<0)
        {
            printf("Invalid input, GPA must be between 0.0 and 4.0\n\n");
            return;
        }
//add the GPA
        students[empty_position].gpa=added_gpa;

        printf("New student added successfully\n\n");
    }
    else
    {
        printf("No empty position\n\n");
        return;
    }
}

void RemoveStudent(struct student students[]){
    int removed_id,id_found=0;

    printf("Enter the 7 digits ID of the student you want to remove\n");
    scanf("%d",&removed_id);
//checking the ID validity
    if(removed_id<1000000 || removed_id>9999999)
    {
        printf("Invalid ID, the ID must be 7 digits\n\n");
        return;
    }
//searching for the ID entered by the user and removing it by setting it's values by zero
    for(int i=0;i<50;i++)
            {
                if(students[i].id==removed_id)
                {
                    printf("ID found successfully and student's data will be removed\n\n");
                    strcpy(students[i].name,"0");
                    students[i].id=0;
                    students[i].gender='0';
                    students[i].academic_year=0;
                    students[i].gpa=0;
                    id_found=1;
                    break;
                }
            }
            if(id_found==0)
            {
                printf("ID not found\n\n");
                return;
            }
}

void RetrieveStudent(struct student students[]){
    int search_choice, id_search,id_found=0, name_found=0, count=0, count_gpa=1;
    char name[50];

    printf("1.Search by name\n2.Search by ID\n");
    scanf("%d",&search_choice);
//giving the user the choice between searching by name or ID
    switch (search_choice){
    case 1:
        puts("Enter the student first and last name");
        getchar();
        gets(name);
//checking if entered name is valid
        for(int j=0;j<50;j++)
        {
            if(name[j]==' ')
            {
                count++;
            }
        }
        if(count!=1)
        {
            printf("Invalid name length\n\n");
            return;
        }
//searching for the name
        for(int i=0; i<50;i++)
        {
            if(strcmp(students[i].name,name)==0)
            {
                printf("Operation successful\n");
                printf("Student Name: %s\n", students[i].name);
                printf("Student ID: %d\n", students[i].id);
                printf("Student Gender: %c\n", students[i].gender);
                printf("Student Academic year: %d\n", students[i].academic_year);
                printf("Student GPA: %.2f\n", students[i].gpa);
                name_found=1;
//To find the student's GPA order
                for(int k=0;k<50;k++)
                {
                    if(students[k].gpa>students[i].gpa)
                    {
                        count_gpa++;
                    }
                }
                printf("Student GPA order is %d\n\n",count_gpa);
                break;
            }
        }
        if(name_found==0)
        {
            printf("Student name is not found\n\n");
        }
        break;
    case 2:
        printf("Enter the 7 digits id\n");
        scanf("%d",&id_search);
//checking the student's ID validity
        if(id_search<1000000 || id_search>9999999)
        {
            printf("Invalid input, the ID must be 7 digits\n\n");
            return;
        }
//searching for the ID
        for(int i=0;i<50;i++)
            {
                if(students[i].id==id_search)
                {
                    printf("Operation successful\n");
                    printf("Student Name: %s\n", students[i].name);
                    printf("Student ID: %d\n", students[i].id);
                    printf("Student Gender: %c\n", students[i].gender);
                    printf("Student Academic year: %d\n", students[i].academic_year);
                    printf("Student GPA: %.2f\n", students[i].gpa);
                    id_found=1;
//To find the student's GPA order
                    for(int k=0;k<50;k++)
                {
                    if(students[k].gpa>students[i].gpa)
                    {
                        count_gpa++;
                    }
                }
                    printf("Student GPA order is %d\n\n",count_gpa);
                    break;
                }
            }
        if(id_found==0)
        {
            printf("Student ID not found\n");
            return;
        }
        break;
    default:
        printf("Invalid input");
        break;
    }
}

void UpdateStudent(struct student students[]){
    int id_search, id_found=0, id_iteration,choice, new_academic_year;
    float new_gpa;

    printf("Enter the 7 digits ID of the student\n");
    scanf("%d",&id_search);
//checking the student's ID validity
    if(id_search<1000000 || id_search>9999999)
    {
        printf("Invalid input, the ID must be 7 digits\n\n");
        return;
    }
//searching for the ID
    for(int i=0;i<50;i++)
            {
                if(students[i].id==id_search)
                {
                    printf("ID found successfully\n");
                    printf("Student's data:\n");
                    printf("Student Name: %s\n", students[i].name);
                    printf("Student ID: %d\n", students[i].id);
                    printf("Student Gender: %c\n", students[i].gender);
                    printf("Student Academic year: %d\n", students[i].academic_year);
                    printf("Student GPA: %.2f\n\n", students[i].gpa);
                    id_iteration=i;
                    id_found=1;
                    break;
                }
            }
//In case of finding the id, user choose between updating the academic year or GPA
    if(id_found==1)
    {
        printf("Choose the operation:\n");
        printf("1.Update the academic year\n");
        printf("2.Update the GPA\n");
        scanf("%d",&choice);
        switch (choice){
    case 1:
        printf("Enter the new academic year value\n");
        scanf("%d",&new_academic_year);
//checking the entered academic year validity
        if(new_academic_year>5 || new_academic_year<1)
        {
            printf("Invalid input, academic year must be between 1 and 5\n\n");
            return;
        }
//updating the student's academic year in case user entered a valid input
        students[id_iteration].academic_year = new_academic_year;
        printf("Student's academic year updated successfully\n\n");
        break;
    case 2:
        printf("Enter the new GPA value\n");
        scanf("%f", &new_gpa);
//checking the entered GPA validity
        if(new_gpa>4 || new_gpa<0)
        {
            printf("Invalid input, GPA must be between 0.0 and 4.0\n\n");
            return;
        }
//updating the student's GPA in case user entered a valid input
        students[id_iteration].gpa = new_gpa;
        printf("Student's GPA updated successfully\n\n");
        break;
    default:
        printf("Invalid input\n\n");
        break;
        }
    }

    if(id_found==0)
        {
            printf("Student ID not found\n\n");
            return;
        }
}

int main()
{
    int operation, Exit=0;
    srand(time(NULL));
    //creating an array of structs
    struct student students[50];
    //Assigning random values to the array
    char rand_gender[]={'M','F'};
    for (int i = 0; i < 50; i++) {
        // Initialize each field separately
        snprintf(students[i].name, sizeof(students[i].name), "Student %d", i);
        students[i].id = (rand() % 9000000)+1000000;
        students[i].gender = rand_gender[rand()%2];
        students[i].academic_year = (rand() % 5) + 1;
        students[i].gpa = ((float)rand()/(float)(RAND_MAX)) * 4;
    }

    while(Exit==0){
//opening a file and checking that it is opened correctly
//The student's data are exported in the while loop to update it when a change is done
    FILE *outfile;
    outfile=fopen("Student's data.txt","w");
    if(outfile==NULL)
    {
        printf("Error opening the output file\n");
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            fprintf(outfile,"Student %d:\n", i);
            fprintf(outfile,"Name: %s\n",students[i].name);
            fprintf(outfile,"ID: %d\n",students[i].id);
            fprintf(outfile,"Gender: %c\n",students[i].gender);
            fprintf(outfile,"Academic Year: %d\n",students[i].academic_year);
            fprintf(outfile,"GPA: %.2f\n\n",students[i].gpa);
        }
    }
    fclose(outfile);
//Choosing between the different operations:
    printf("Please choose the operation:\n");
    printf("1.Add Student \n");
    printf("2.Remove Student \n");
    printf("3.Retrieve Student's data\n");
    printf("4.Update Student's data\n");
    printf("5.Exit the program\n");
    scanf(" %d",&operation);

    switch (operation){
        case 1:
            AddStudent(students);
            break;
        case 2:
            RemoveStudent(students);
            break;
        case 3:
            RetrieveStudent(students);
            break;
        case 4:
            UpdateStudent(students);
            break;
        case 5:
            printf("Exiting the program\n");
            Exit=1;
            break;
        default:
            printf("Invalid input. Please try again\n\n");
    }
    }
return 0;
}
