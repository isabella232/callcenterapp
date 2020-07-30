#### **Welcome to Part 2. In this part, we will be just finishing up our logic app and uploading our files.**

Link your “blob” blocks to your storage account when prompted. The block names in the Part 1 image are explanatory about what each block does. The for-each loop iterates through each “value” in the form submission. You will find “value” and many other variables in the “Dynamic Content” Section. 
Below is a detailed explanation of the major blocks:

1. 
![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p3images/23.png)

Your container may have a different name. Under “Connected to”, connect to the container that you created previously to receive form data (not the one with your HTML and CSS code). 

2.
![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p3images/24.png)

For sending the email, you need an outlook account. For testing purposes, try sending the email to yourself. “compare1” and “compare2” are extra parameters I have passed; you don’t need them to send the email. 

3.
![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p3images/25.png)

This block gets the files in your container ready at your logic app’s disposal. 

4.
![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p3images/26.png)

For the for-each loop, you want to iterate through each value (that is the file identifier) in your container. You can get the “value” from “Dynamic Content”. 

5.
![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p3images/27.png)

You want to use dynamic content “Id” for getting the form data. 

6.
![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p3images/28.png)

You need to get the elements of your form and set them to variables that the logic app can use. Parse the json form data using the following sample payload schema:
```` JSON
{
    "properties": {
        "formdata": {
            "properties": {
                "abandoned": {
                    "type": "string"
                },
                "aftercallwork": {
                    "type": "string"
                },
                "blocked": {
                    "type": "string"
                },
                "calltime": {
                    "type": "string"
                },
                "country": {
                    "type": "string"
                },
                "issueresolved": {
                    "type": "string"
                },
                "lname": {
                    "type": "string"
                },
                "problemarea": {
                    "type": "string"
                },
                "resolvetime": {
                    "type": "string"
                },
                "subject": {
                    "type": "string"
                },
                "waitingtime": {
                    "type": "string"
                }
            },
            "type": "object"
        }
    },
    "type": "object"
}
````
7.
![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p3images/29.png)

Output your processing data into another container. 

Use the condition within the for-each loop to do whatever data processing you want with your data. 
To send your processed data you could do something like this:

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p3images/30.png)

Click “Save” and “Run” in the top menu of the logic app. The app won’t do anything until you upload something in the blob you specified. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p3images/31.png)
 
Go to your blob. You can manually upload some json files that are in line with the previously detailed schema, or use the following C code if you have a C compiler (clang, gcc, etc.). 
```` C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FILES 50
#define SIZE sizeof(int) + 1

void *choice(void *, int);
static char * choice2( char [][25], int);
int choice3 (int);

int main() {
  char yesno [2][4] = {{"Yes"}, {"No"}};
  char problemarea [5][11] = {{"Problem 1"}, {"Problem 2"}, {"Problem 3"}, {"Problem 4"}, {"Other"}};
  char callcenter [5][13] = {{"CallCenter 1"}, {"Callcenter 2"}, {"Callcenter 3"}, {"Callcenter 4"}, {"Other"}};
  char lastname [6][6] = {{"Mitra"}, {"Sam"}, {"Tom"}, {"Ann"}, {"Mary"}, {"Todd"}};
  char comment [4][22] = {{"The call went great!"}, {"The call was boring."}, {"The call was annoying."}, {"The call was bad."}};

  FILE *fp;
  char prefix [10] = {"data"};

    for (int file_index = 0; file_index < FILES; file_index++){
      char suffix [SIZE + 5];
      sprintf(suffix, "%d", file_index);
      strcat(suffix, ".txt");
      strcat(prefix, suffix);
      printf("Now creating ");
      printf("%s\n", prefix);
      fp = fopen(prefix, "w+");
      fprintf(fp,"{\n \"formdata\": {\n\t\"blocked\": \"%s\",\n\t\"abandoned\": \"%s\",\n\t\"waitingtime\": \"%d\",\n\t\"problemarea\": \"%s\",\n\t\"issueresolved\": \"%s\",\n\t\"resolvetime\": \"%d\",\n\t\"calltime\": \"%d\",\n\t\"aftercallwork\": \"%d\",\n\t\"lname\": \"%s\",\n\t\"country\": \"%s\",\n\t\"subject\": \"%s\",\n},\n}",
      (yesno[choice3(2)]),
      (yesno[choice3(2)]),
      1 + rand()%10,
      (problemarea[choice3(5)]),
      (yesno[choice3(2)]),
      1 + rand()%10,
      1 + rand()%10,
      1 + rand()%10,
      (lastname[choice3(6)]),
      (callcenter[choice3(6)]),
      (comment[choice3(4)])
    );
      fclose(fp);
      strcpy(prefix, "data");

    }

}

int choice3 (int size){
  srand(time(0));
  return rand()%(size-1);
}
````

The code will create folders in your local directory. Upload these folders to the Azure Blob Storage container you are using to receive the form data. 

See the results, enjoy, and customize to your needs!

Possible Add-ons:
1.	Try to send an HTML graph or chart with the data in the Outlook Email. 
2.	Do text analytics on form data
