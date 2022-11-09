#include <iostream>
using namespace std;

int main() {

    int OPERATIONS = 0;
    cin >> OPERATIONS;
    int gIndexer = 0;
    while (gIndexer < OPERATIONS){
        int tabtabtabtabSize = 0;
        cin >> tabtabtabtabSize;
        int tab[tabtabtabtabSize];

        int tabCiner =0;
        while (tabCiner < tabtabtabtabSize ){
            cin >> tab[tabCiner];

            tabCiner++;
        }



        char operationChar ='i';
        while (operationChar != 'F'){

            cin >> operationChar;

            if(operationChar == 'F'){
                gIndexer++;
            }
            else if(operationChar == 'R'){

                /*
                 *      P
                 *      p
                 *      P
                 *
                 *
                 */

                int startIndex= 0;
                int grouptabtabtabSize = 0;
                cin >> startIndex >> grouptabtabtabSize;
                int EndIndex;

                startIndex=((startIndex % tabtabtabtabSize) + tabtabtabtabSize)%tabtabtabtabSize;
                EndIndex=(startIndex+grouptabtabtabSize -1)%tabtabtabtabSize;

                int currentIndex=startIndex;
                bool cyclicLogic = true;
                bool  secondLap =false;
                int processed = 0;

                while (tabtabtabtabSize - processed >= grouptabtabtabSize){

                   int groupInsideIndexer = 0;
                    while (groupInsideIndexer < grouptabtabtabSize / 2){
                        int getValue= tab[(currentIndex + groupInsideIndexer) % tabtabtabtabSize];
                        tab[(currentIndex + groupInsideIndexer) % tabtabtabtabSize] = tab[(EndIndex + groupInsideIndexer) % tabtabtabtabSize];
                        tab[(EndIndex - groupInsideIndexer) % tabtabtabtabSize] = getValue;
                    }

                    currentIndex = (currentIndex + grouptabtabtabSize) % tabtabtabtabSize;
                    EndIndex = (currentIndex + grouptabtabtabSize - 1) % tabtabtabtabSize;

                    while (EndIndex <= 0){
                        EndIndex = EndIndex + tabtabtabtabSize;
                    }
                    processed = processed + grouptabtabtabSize;
                }




        }

            /*
             *
             *
             *
             *
             *
             *
             */


            else if( operationChar == 'M'){
                //region Descrition




                //endregion
                /*
                 *
                 *
                 *
                 *  PPPP PP  PPP PPP PPP
                 *
                 *
                 *
                 *
                 *
                 */


                int startIndex = 0;
                cin >> startIndex;
                startIndex = ((startIndex %tabtabtabtabSize) +tabtabtabtabSize) %tabtabtabtabSize;
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
                    int beforeTable =  tab[(startIndex + shift * index) %tabtabtabtabSize];
                    // cout << beforeTable << " X"<< endl;
                    while (index < group){
                        int temp = tab[((shift * (index+1)) % group + startIndex) %tabtabtabtabSize];
                        // cout << temp <<" ?  " <<endl;

                        tab[(( shift * (index+1)) % group + startIndex) %tabtabtabtabSize] = beforeTable;
                        beforeTable = temp;
                        whileTrue2 ++;
                        if((whileTrue2 + group) %tabtabtabtabSize < whileTrue2 %tabtabtabtabSize){
                            INDEX_TO_LAST = (whileTrue2 + group+1) %tabtabtabtabSize;
                            // cout<< INDEX_TO_LAST<<" Q"<< endl;
                            secondLap2 = true;
                            whileTrue2 = whileTrue %tabtabtabtabSize;
                            if(whileTrue2 + group -1 > startIndex ){
                                CyclicLogic2 = false;
                            }

                        }

                        index++;

                    }
                    whileTrue2 = whileTrue2 + group -2;

                    startIndex = (startIndex + group ) %tabtabtabtabSize;


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

                    tab[(( shift * (w+1)) % g2 + startIndex) %tabtabtabtabSize] = bfTable2;
                    bfTable2 = temp;

                    w++;
                }


                for (int i = 0; i < tabtabtabtabSize; ++i) {
                    cout<< tab[i] <<" ";

                }

                /*



                 */


            }

            else if(operationChar == 'C'){

                /*
                 * 3 funcja

                 */

                int sIndex = 0;
                int sGroup = 0;
                sIndex = ((sIndex % tabtabtabtabSize) + tabtabtabtabSize) % tabtabtabtabSize;
                cin >> sIndex;
                cin >> sGroup;
                int currentIndex = 0;
                bool firstLap = true;
                currentIndex = sIndex;

                int index5 = 0;
                int isFirst = sIndex;

                while (firstLap || currentIndex < sIndex - 2 * sGroup){

                    while (index5 < sGroup){
                        swap(tab[(currentIndex +index5) % tabtabtabtabSize],tab[( (currentIndex + index5 + sGroup ) % tabtabtabtabSize)] );
                        index5++;
                        isFirst++;

                        if(isFirst > tabtabtabtabSize){
                            firstLap = false;
                        }
                    }
                    currentIndex = (currentIndex + 2 * sGroup) % tabtabtabtabSize;
                    }
                    for(int i=0;i<tabtabtabtabSize;i++){
                        cout<< tab[i]<<" ";}

            }

            /*
           * koniec 3 funkcja
           */

            // 4 funkcja
            
            if(operationChar == 'S')
            {
        
                /*


                 * 
                 */

                int startIndex;
                cin >> startIndex;

                int group;
                cin >> group;


                //cout << startIndex << " y"<< endl;
                int currentIndex = startIndex;
                bool cycleLogic8 = true;
                startIndex = ((startIndex % tabtabtabtabSize) + tabtabtabtabSize) % tabtabtabtabSize;

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
                while (cycleLogic8) {

                    if (rtck == 'r') {
                        int i = 0;
                        while (i < group) {
                            int j = 0;
                            while (j < group - 1) {
                                if (tab[(currentIndex + j + 1) % tabtabtabtabSize] < tab[(currentIndex + j) % tabtabtabtabSize]) {
                                    int bufor = tab[currentIndex + j + 1];
                                    tab[(currentIndex + j + 1) % tabtabtabtabSize] = tab[(currentIndex + j) % tabtabtabtabSize];
                                    tab[currentIndex + j] = bufor;
                                }
                                j++;
                            }
                            i++;
                            whileTrue++;
                            if (whileTrue > tabtabtabtabSize) {
                                firstLap = false;
                            }
                        }
                    }
                    if (rtck == 'm') {
                        int i = 0;
                        while (i < group) {
                            int j = 0;
                            while (j < group - 1) {
                                if (tab[(currentIndex + j) % tabtabtabtabSize] < tab[(currentIndex + j + 1) % tabtabtabtabSize]) {
                                    int bufor = 0;
                                    bufor = tab[(currentIndex + j) % tabtabtabtabSize];
                                    tab[(currentIndex + j) % tabtabtabtabSize] = tab[(currentIndex + j + 1) % tabtabtabtabSize];
                                    tab[(currentIndex + j + 1) % tabtabtabtabSize] = bufor;
                                }
                                j++;
                            }
                            i++;
                            whileTrue++;
                            if (whileTrue > tabtabtabtabSize) {
                                firstLap = false;
                            }
                        }
                    }

                    bool a = (currentIndex+group) % tabtabtabtabSize > startIndex;

                    // cout << !firstLap << " " << a << endl;
                    if (!firstLap && a) {
                        cycleLogic8 = false;

                    }

                    currentIndex = (currentIndex + group) % tabtabtabtabSize;


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
                                if (tab[(currentIndex + j + 1) % tabtabtabtabSize] < tab[(currentIndex + j) % tabtabtabtabSize]) {
                                    int bufor = tab[currentIndex + j + 1];
                                    tab[(currentIndex + j + 1) % tabtabtabtabSize] = tab[(currentIndex + j) % tabtabtabtabSize];
                                    tab[currentIndex + j] = bufor;

                                }
                                j++;


                            }
                            i++;
                            whileTrue++;
                            if (whileTrue > tabtabtabtabSize) {
                                firstLap = false;
                            }
                        }

                    } else if(rtck == 'm'){


                        int i = 0;
                        while (i < lastElementtabtabSize) {
                            int j = 0;
                            while (j < lastElementtabtabSize - 1) {
                                if (tab[(currentIndex + j) % tabtabtabtabSize] < tab[(currentIndex + j + 1) % tabtabtabtabSize]) {
                                    int bufor = 0;
                                    bufor = tab[(currentIndex + j) % tabtabtabtabSize];
                                    tab[(currentIndex + j) % tabtabtabtabSize] = tab[(currentIndex + j + 1) % tabtabtabtabSize];
                                    tab[(currentIndex + j + 1) % tabtabtabtabSize] = bufor;

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



