/*************************************************************************
 * Author:          sugarfreeoh
 * Date:            15 March 2016
 * Description:     You are given two sorted list of numbers. Print out
 *                  the intersection of the sets
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            size_t delLocation;
            vector<string> setOne;
            vector<string> setTwo;

            string one;
            string two;

            string intersection;

            delLocation = line.find(';');

            if(delLocation != string::npos)
            {  
                string temp;

                stringstream setStream;

                one = line.substr(0,delLocation);
                two = line.substr(delLocation+1);

                //cout << "First set: " << one << "." << endl;
                //cout << "Second set: " << two << "." << endl;

                setStream << one;
    
                while(getline(setStream,temp,','))
                {
                    setOne.push_back(temp);
                }

                setStream.str("");
                setStream.clear();

                setStream << two;

                while(getline(setStream,temp,','))
                {
                    setTwo.push_back(temp);
                }

                for(vector<string>::iterator itOne=setOne.begin();
                    itOne != setOne.end();
                    ++itOne)
                {
                    for(vector<string>::iterator itTwo=setTwo.begin();
                        itTwo != setTwo.end();
                        ++itTwo)
                    {
                        if(*itOne == *itTwo)
                        {
                            intersection = intersection + *itTwo + ",";
                            break;
                        }
                    }
                }

                if(intersection.size() > 0)
                {
                    intersection = intersection.substr(0,intersection.size()-1);
                }

                cout << intersection << endl;

                intersection = "";
            }
        }

        inputFile.close();
    }
    else
    {
        cout << "Error opening input file" << endl;
    }

    return 0;
}
