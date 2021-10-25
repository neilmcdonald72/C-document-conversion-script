//Neil McDonald 2021-10-25
//A program that reads a C++ source file and converts all < symbols to &lt; and all > symbols to &gt;.
//Adds the tag <PRE> to the beginning of the file and </PRE> to the end of the file.
//This tag preserves whitespace and formatting in the HTML document.

#include <iostream>
#include <string>
#include <fstream>
#include <regex>


using namespace std;

int main() {

    char *inputFileName;

    string cppExt = ".cpp";
    cout << "Enter file path you want to edit" << endl;
    cin>>inputFileName;
    string filePathInput = inputFileName + cppExt;

    //INPUT FILE PATH VALIDATION

    char badChars[] = "<>:\"/|?*";
    char invalid_found = false;


    for (int i = 0; i < strlen(badChars); ++i) {
        if (strchr(inputFileName, badChars[i]) != NULL) {
            invalid_found = true;
            break;
        }
    }
    if (invalid_found) {
        printf("Invalid file name");
    }


    //CANT GET OUTPUT FILE NAME VALIDATION WORKING, SEGMENTATION FAULT


//    char *outPutFileName;
//    string htmlExt = ".html";
//    cout << "Enter file name you want to output" << endl;
//    cin>>outPutFileName;
//    string filePathOutput = outPutFileName + htmlExt;
//
//    char badChars1[] = "<>:\"/|?*";
//    char invalid_found2 = false;
//
//
//    for (int i = 0; i < strlen(badChars); ++i) {
//        if (strchr(outPutFileName, badChars1[i]) != NULL) {
//            invalid_found2 = true;
//            break;
//        }
//    }
//    if (invalid_found) {
//        printf("Invalid file name");
//    }




    string line;

    ifstream myFile(filePathInput);
    ofstream myFileHTML;
    myFileHTML.open("outFile.html",ios::app);

    if(myFile.is_open())
    {
        myFileHTML << "<PRE>";
        myFileHTML << "\n";

        while(!myFile.eof())
        {
            getline(myFile, line);

            string fileLine = line;


            for(char i : fileLine)
            {
                string fileChar = string(1,i);

                if(fileChar == "<")
                    myFileHTML << "&lt;";
                if(fileChar == ">")
                    myFileHTML << "&gt;";
                else
                    myFileHTML << fileChar;

            }

            myFileHTML << "\n";


        }
        myFileHTML << "</PRE>";

    }
    else
    {
        cout << "File failed to open"<<endl;
    }



     return 0;


}
