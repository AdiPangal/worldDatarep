#include <iostream>
#include <fstream>
using namespace std;

struct COUNTRY{
  float lifeExpect;
  string name;
};
void sort(COUNTRY* list[],int size){
  for(int i = 0; i<size; i++){
    for(int j = i; j < size; j++){
      if((*list[i]).lifeExpect < (*list[j]).lifeExpect){
        COUNTRY* temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }
}


int main(){
  string line;
  ifstream initialFile("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
  int size = 0;
  int sizeWORegions = 0;
  if(initialFile.is_open()){
    while(getline(initialFile,line, '\n')){
      if(line[0] <= 57 && line[0] >= 48){
        size++;
        sizeWORegions++;
        if((line.find("income") != string::npos || line.find("developed") != string::npos || line.find("WORLD") != string::npos || line.find("EUROPE") != string::npos || line.find("AMERICA") != string::npos|| line.find("AFRICA") != string::npos|| line.find("ASIA") != string::npos|| line.find("Europe") != string::npos|| line.find("Caribbean") != string::npos|| line.find("Asia") != string::npos|| line.find("OCEANIA") != string::npos|| line.find("Melanesia") != string::npos|| line.find("Micronesia") != string::npos|| line.find("Polynesia") != string::npos || line.find("Australia/") != string::npos || line.find("Middle Africa") != string::npos||  line.find("n Africa") != string::npos|| line.find("Other") != string::npos || line.find("South America") != string::npos || line.find("Central America") != string::npos) && !(line.find("French Polynesia") != string::npos || line.find("Fed.") != string::npos)){
          sizeWORegions--;
          // Micronesia issue
        }
      }
    }
      initialFile.close();
  }else{
    cout << "Not able to open" << endl;
  }
  // Utilize pointers as a way to sort the rankings of each group
  COUNTRY* listPointer[sizeWORegions];
  COUNTRY list[sizeWORegions];



  
  
  ifstream myFile("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
  if(myFile.is_open()){
    int n = -1;
    //streampos size = myFile.tellg();
    while (getline(myFile, line, '\n')){
      if (line[0] <= 57 && line[0] >= 48){
        if(!(line.find("income") != string::npos || line.find("developed") != string::npos || line.find("WORLD") != string::npos || line.find("EUROPE") != string::npos || line.find("AMERICA") != string::npos|| line.find("AFRICA") != string::npos|| line.find("ASIA") != string::npos|| line.find("Europe") != string::npos|| line.find("Caribbean") != string::npos|| line.find("Asia") != string::npos|| line.find("OCEANIA") != string::npos|| line.find("Melanesia") != string::npos|| line.find("Micronesia") != string::npos|| line.find("Polynesia") != string::npos || line.find("Australia/") != string::npos || line.find("Middle Africa") != string::npos||  line.find("n Africa") != string::npos || line.find("Other") != string::npos || line.find("South America") != string::npos|| line.find("Central America") != string::npos) || (line.find("French Polynesia") != string::npos || line.find("Fed.") != string::npos)){

        int t = 0; // tracks the data point it is on
        n++; // used to determine which line the code is on. Helps distribute stuff into the right array location
        int doesNameNeedExtra = 2;

        int initialIndex = 0;
        int endIndex = line.find(",", initialIndex);
        string wordSum = "";
        while (line.find(",", initialIndex) < line.length()-1){
          endIndex = line.find(",", initialIndex);
          t++;
          string word = line.substr(initialIndex, endIndex-initialIndex); // big issue, noticed that some countries have multiple characters. Will need to solve this
          // puts data into an array so it can be sorted by country

          if(t == 3 || doesNameNeedExtra == 3){
            wordSum = wordSum + word;
            if (line[endIndex - 1] == '\"'){
              list[n].name = wordSum;
              doesNameNeedExtra -= 2;
            }else{
              doesNameNeedExtra++;
            }
            
            //cout << "Going to column 0 at location "<<n << " is " << word << "\n" << endl;
          } else if (t == (16 + doesNameNeedExtra)){
            list[n].lifeExpect = stof(word);
            //cout << "Going to column 1 at location "<<n << " is " << word << "\n" << endl;
          }
          //cout << "Initial Index " << initialIndex << "  End Index " << endIndex << endl;
          //cout << word << "\n" << endl;
          initialIndex = endIndex + 1;
        }
      }
      }
      
    }

    // sorting the data that we get 
    
    myFile.close();
    for(int a = 0; a < sizeWORegions; a++){
      listPointer[a]= &list[a];
    }
    sort(listPointer, sizeWORegions);

    for(int z = 0; z < sizeWORegions; z++){
      cout <<"Rank "<< z+1 << "   "<< (*listPointer[z]).name << ", " <<(*listPointer[z]).lifeExpect << endl;
    }
    
  }else{
    cout << "Unable to open the file" << endl;
  }

  //hello
  //hello there




  return 0;
}




