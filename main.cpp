//Lukasz Szczurek
#include <iostream>
using namespace std;

int main() {

    int OPERATIONS = 0;
    cin >> OPERATIONS;
    int gIndexer = 0;
    while (gIndexer < OPERATIONS){
        int tabSize = 0;
        cin >> tabSize;
        int tab[tabSize];

        int tabCiner =0;
        while (tabCiner < tabSize ){
            cin >> tab[tabCiner];

            tabCiner++;
        }

        int tabStartSee = 0;
        while (tabStartSee < tabSize){

            cout << tab[tabStartSee] << " ";

            tabStartSee++;
        }
        cout << endl;



        char operationChar ='i';
        while (operationChar != 'F'){

            cin >> operationChar;

            if(operationChar == 'F'){
                gIndexer++;

                int indexCoutTab = 0;
                while(indexCoutTab < tabSize){
                    cout << tab[indexCoutTab] <<" ";
                }
                cout << endl;
            }
            else if(operationChar == 'R'){

                int startIndex= 0;
                int grouptabtabtabSize = 0;
                cin >> startIndex >> grouptabtabtabSize;
                int EndIndex;

                startIndex=((startIndex % tabSize) + tabSize)%tabSize;
                EndIndex=(startIndex+grouptabtabtabSize -1)%tabSize;

                int currentIndex=startIndex;
                bool cyclicLogic = true;
                bool  secondLap =false;
                int processed = 0;

                while (tabSize - processed >= grouptabtabtabSize){

                   int groupInsideIndexer = 0;
                    while (groupInsideIndexer < grouptabtabtabSize / 2){
                        int getValue= tab[(currentIndex + groupInsideIndexer) % tabSize];
                        tab[(currentIndex + groupInsideIndexer) % tabSize] = tab[(EndIndex + groupInsideIndexer) % tabSize];
                        tab[(EndIndex - groupInsideIndexer) % tabSize] = getValue;
                    }

                    currentIndex = (currentIndex + grouptabtabtabSize) % tabSize;
                    EndIndex = (currentIndex + grouptabtabtabSize - 1) % tabSize;

                    while (EndIndex <= 0){
                        EndIndex = EndIndex + tabSize;
                    }
                    processed = processed + grouptabtabtabSize;
                }
                
                
                for(int i=0;i<grouptabtabtabSize; i++) {
                    cout << tab[i] << " ";
                }

        }

            else if( operationChar == 'M'){



                int startIndex = 0;
                cin >> startIndex;
                startIndex = ((startIndex %tabSize) +tabSize) %tabSize;
                // cout << startIndex << " H"<<endl;
                int START_INDEX = startIndex;



                int group = 0;
                cin >> group;

                int shift = 0;
                cin >> shift;
                shift = (((shift % group) + group)) % group;
                bool CyclicLogic2 = true;
                bool secondLap2 = false;
                int CURRENT_INDEX = startIndex;
                int whileTrue = CURRENT_INDEX;
                int whileTrue2= 0;
                bool secondLap = false;
                int INDEX_TO_LAST = 0;
                int STR_LAST_INDEX = 0;

                while (CyclicLogic2){
                    int index = 0;
                    int beforeTable =  tab[(startIndex + shift * index) %tabSize];
                    // cout << beforeTable << " X"<< endl;
                    while (index < group){
                        int temp = tab[((shift * (index+1)) % group + startIndex) %tabSize];
                        // cout << temp <<" ?  " <<endl;

                        tab[(( shift * (index+1)) % group + startIndex) %tabSize] = beforeTable;
                        beforeTable = temp;
                        whileTrue2 ++;
                        if((whileTrue2 + group) %tabSize < whileTrue2 %tabSize){
                            INDEX_TO_LAST = (whileTrue2 + group+1) %tabSize;
                            // cout<< INDEX_TO_LAST<<" Q"<< endl;
                            secondLap2 = true;
                            whileTrue2 = whileTrue %tabSize;
                            if(whileTrue2 + group -1 > startIndex ){
                                CyclicLogic2 = false;
                            }

                        }

                        index++;

                    }
                    whileTrue2 = whileTrue2 + group -2;

                    startIndex = (startIndex + group ) %tabSize;


                    if(secondLap2 && whileTrue2 > startIndex){
                        CyclicLogic2 = false;
                    }
                    whileTrue2 = whileTrue2 - group + 2;


                }

                int w = 0;
                int g = START_INDEX;
                //cout << START_INDEX <<" START" << endl;
                int bfTable2 = tab[INDEX_TO_LAST];
                // cout << bfTable2 << " LAST" <<endl;
                int g2 = START_INDEX - INDEX_TO_LAST;
                // cout<< g2 <<" G2"<< endl;
                while(w < g){
                    int temp = tab[((shift * (w+1)) % g2 + startIndex) % group];
                    // cout << temp <<" ?  " <<endl;

                    tab[(( shift * (w+1)) % g2 + startIndex) %tabSize] = bfTable2;
                    bfTable2 = temp;

                    w++;
                }


                for (int i = 0; i < tabSize; ++i) {
                    cout<< tab[i] <<" ";

                }

            }

            else if(operationChar == 'C'){


                int sIndex = 0;
                int sGroup = 0;
                sIndex = ((sIndex % tabSize) + tabSize) % tabSize;
                cin >> sIndex;
                cin >> sGroup;
                int currentIndex = 0;
                bool firstLap = true;
                currentIndex = sIndex;

                int index5 = 0;
                int isFirst = sIndex;

                while (firstLap || currentIndex < sIndex - 2 * sGroup){

                    while (index5 < sGroup){
                        swap(tab[(currentIndex +index5) % tabSize],tab[( (currentIndex + index5 + sGroup ) % tabSize)] );
                        index5++;
                        isFirst++;

                        if(isFirst > tabSize){
                            firstLap = false;
                        }
                    }
                    currentIndex = (currentIndex + 2 * sGroup) % tabSize;
                    }
                    for(int i=0;i<tabSize;i++){
                        cout<< tab[i]<<" ";}

            }

            /*
           * koniec 3 funkcja
           */

            // 4 funkcja
            
            if(operationChar == 'S')
            {


                int startIndex;
                cin >> startIndex;

                int group;
                cin >> group;


                //cout << startIndex << " y"<< endl;
                int currentIndex = startIndex;
                bool cycleLogic8 = true;
                startIndex = ((startIndex % tabSize) + tabSize) % tabSize;

                int whileTrue = startIndex;
                bool firstLap = true;

                char rtck = '$';
                if (group < 0) {
                    rtck = 'm';
                } else if (group >= 0) {
                    rtck = 'r';
                }

                if(group < 0){
                    group = group * (-1);
                }

                int startInsideIndex = 0;
                int EndInsideIndex = group-1;
                while (startInsideIndex < tabSize) {




                    if (rtck == 'r') {
                        int i = startInsideIndex;
                        while (i <= EndInsideIndex -1) {
                            int j = startInsideIndex;
                            while (j <= EndInsideIndex-1) {
                                if (tab[(currentIndex + j + 1) % tabSize] < tab[(currentIndex + j) % tabSize]) {
                                    int bufor = tab[currentIndex + j + 1];
                                    tab[(currentIndex + j + 1) % tabSize] = tab[(currentIndex + j) % tabSize];
                                    tab[currentIndex + j] = bufor;
                                }
                                j++;
                            }
                            i++;

                        }
                        //
                    }
                    if (rtck == 'm') {
                        int i = startInsideIndex;
                        while (i <= EndInsideIndex - 1) {
                            int j = startInsideIndex;
                            while (j < EndInsideIndex - 1) {
                                if (tab[(currentIndex + j + 1) % tabSize] > tab[(currentIndex + j ) % tabSize]) {
                                    int bufor = 0;
                                    bufor = tab[(currentIndex + j + 1) % tabSize];
                                    tab[(currentIndex + j + 1) % tabSize] = tab[(currentIndex + j + 1) % tabSize];
                                    tab[(currentIndex + j ) % tabSize] = bufor;
                                }
                                j++;
                            }
                            i++;

                        }
                    }

                            startInsideIndex+= group;

                            EndInsideIndex = min(EndInsideIndex+group , tabSize -1 );




                }


                int lastElementtabtabSize= startIndex - currentIndex;

                int y=0;
                while(y < lastElementtabtabSize){
                    if(rtck == 'r'){

                        //
                        int i = 0;
                        while (i < lastElementtabtabSize) {
                            int j = 0;
                            while (j < lastElementtabtabSize - 1) {
                                if (tab[(currentIndex + j + 1) % tabSize] < tab[(currentIndex + j) % tabSize]) {
                                    int bufor = tab[currentIndex + j + 1];
                                    tab[(currentIndex + j + 1) % tabSize] = tab[(currentIndex + j) % tabSize];
                                    tab[currentIndex + j] = bufor;

                                }
                                j++;


                            }
                            i++;
                            whileTrue++;
                            if (whileTrue > tabSize) {
                                firstLap = false;
                            }
                        }

                    } else if(rtck == 'm'){


                        int i = 0;
                        while (i < lastElementtabtabSize) {
                            int j = 0;
                            while (j < lastElementtabtabSize - 1) {
                                if (tab[(currentIndex + j) % tabSize] < tab[(currentIndex + j + 1) % tabSize]) {
                                    int bufor = 0;
                                    bufor = tab[(currentIndex + j) % tabSize];
                                    tab[(currentIndex + j) % tabSize] = tab[(currentIndex + j + 1) % tabSize];
                                    tab[(currentIndex + j + 1) % tabSize] = bufor;

                                }
                                j++;
                            }
                            i++;
                        }

                    }

                    y++;
                }

                
            }

        }
    }


}



