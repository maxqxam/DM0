#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

#define str std::string
#define OUT(x) std::cout<<x<<'\n';
#define out(x) std::cout<<x;
#define space std::cout<<" ";
#define enter std::cout<<"\n";
#define indent std::cout<<"    ";


//char And,Or,XAnd,Then, Not, Hashtag;
char OpAll[]="&|%>~#=";
char OpSome[]="&|%>=";
char PS[]="()";

char Alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
// Why in string form it can handle one less characters?


char And='&';char Or='|';char XAnd='%';char Then='>';
char Not='~';char Hashtag='#';// Why can't I declare them seperately outside the main function?




str decToHex16(str dex16){
    str out = dex16;
    if (out=="10"){
        out="a";
    }else if(out=="11"){
        out="b";
    }else if(out=="12"){
        out="c";
    }else if(out=="13"){
        out="d";
    }else if(out=="14"){
        out="e";
    }else if(out=="15"){
        out="f";
    }

    return out;
}
str binToHex4based(str bin){
    str Hex = "";
    str hex = "";
    int hexVal = 0;
    int valueTable[4] = {8,4,2,1};
    int c = 3;
    for (int i=bin.length()-1;i!=-1;i--){
        if (bin[i]=='1'){
            hexVal += valueTable[c];
        }
        if (c==0){
            c=4;
            hex = std::to_string(hexVal);
            if (hex.length()==2)
                hex=decToHex16(hex);
            Hex = hex + Hex;
            hexVal = 0;
        }
        c--;
    }

    return Hex;
}
str input(str placeholder){
    str mString;
    bool notEmpty = false;
    while (1){
        mString="";
        out(placeholder)
        // std::cin>>mString; # This Input method only recieve's one word
        getline(std::cin,mString); // # This Input method recieve's the whole line

        if (mString.length()!=0){

            for (int i=0;i!=mString.length();i++){
                if (mString[i]!=' ')
                    notEmpty = true;
            };

            if (notEmpty)
                break;
        }
    }

    return mString;
}

bool isBin(str String){
    for (int i=0 ; i!=String.length() ;i++)
        if (String[i]!='0' & String[i]!='1')
            return false;

    return true;
}

bool validPDec(str pDec){
    char l,r;
    l='(';r=')';
    str rls = "";
    int rc,lc;

    rc = lc = 0;
    int rlc = 0;

    for (int i=0;i!=pDec.length();i++){
        if (pDec[i]==l | pDec[i]==r){
            rls+=pDec[i];
            rlc++;
            if (pDec[i]==l){
                lc++;
            }else{
                rc++;
            }
        }
    }

    bool result = true;

    if (rls[0]==r){
        //OUT("1- ')' is at the begining of the expression.")
        result = false;
    }
    if (rlc%2!=0){
        //OUT("2- The total number of Parenthesis is an odd number.")
        result = false;
    }
    if (rls[rlc-1]==l){
        //OUT("3- '(' is at the ending of the expression.")
        result = false;
    }
    if (rc!=lc){
        //OUT("4- The number of left and right parenthesis is not equal.)")
        result = false;
    }

    if (!result){
        return result;
    }

    bool isCouple = false;
    if (result & rls.length()!=0){
        str tempStr=rls;
        str tempTempStr="";

        if (tempStr.length()==2){
            if (tempStr[0]==l & tempStr[1]==r)
                return true;
        }

        //enter

        //OUT("Enter Checkpoint")
        //OUT(tempStr)
        while (true){
            for (int i=0;i!=tempStr.length()-1;i++){
                if (tempStr[i]==l & tempStr[i+1]==r){
                    tempStr[i]=' ';
                    tempStr[i+1]=' ';

                    for (int c=0;c!=tempStr.length();c++){
                        if (tempStr[c]!=' ')
                            tempTempStr+=tempStr[c];

                    }

                    tempStr=tempTempStr;
                    tempTempStr="";
                    isCouple=true;
                    break;

                }
            }

            if (isCouple==false){
                //out(tempStr)out(" Not a Couple ")OUT(tempStr.length())
                break;
            }else{
                isCouple=false;
            }

            //out(tempStr) OUT(tempStr.length())
            if (tempStr.length()<3){
                break;
            }
        }

        //OUT("Exit Checkpoint")
        //OUT(tempStr);
        //enter

        if (tempStr.length()!=2 & isCouple==false)
            return false;
        if ((tempStr[0]==r & tempStr[1]==l) & tempStr.length()==2)
            return false;

    }

    return true;
}

bool inCharList(char Char,const char List[]){

    int ListSize=strlen(List);

    for (int i=0;i!=ListSize
            ; i++){

            if (Char==List[i]){
                return true;
            }
    }
    return false;
}

int ifAround(char before[],int currentIndex,
                char after[], str Struct)

    {
        if (currentIndex==0){
            if (inCharList(Struct[currentIndex+1],after)){

                return 2;
            }
        }else if(currentIndex==Struct.length()-1){
            if (inCharList(Struct[currentIndex-1],before)){
                return 1;
            }

        }else{
            int ifBoth=0;
            if (inCharList(Struct[currentIndex+1],after)){

                ifBoth += 2;
            }
            if (inCharList(Struct[currentIndex-1],before)){
                ifBoth += 1;
            }
            return ifBoth;
        }


    return 0;
}

bool inStrList(str Str,str List[],int listSize){
    for (int i=0;i!=listSize;i++){
        if (Str==List[i]) return true;
    }

    return false;
}

template <typename T>
void clearArray(T &array,int arraySize){
    T empty;
    for (int i=0;i!=arraySize;i++){
        array[i]=*empty;
    }
}
template <typename T>
void printArray(T &array,char splitter){
    int size = sizeof(array)/sizeof(array[0]);

    for (int i=0;i!=size;i++){
        out(array[i]) out(splitter)

    }
}


str varStore[8];
str varValStore[8];
char hexCharList[] = "0123456789abcdef";

int getVars(str Struct){
    int maxIndex=7;
    int result=0;

    clearArray(varStore,8);
    str tempVar="";
    bool open=false;
    bool hexOpen=false;

    for (int i=0;i!=Struct.length();i++){
        if (Struct[i]=='#'){            
            hexOpen=true;

        }
        else if (hexOpen){
            if (inCharList(Struct[i],hexCharList)==false){
                hexOpen=false;
            }

        }else{
            if (open){
                if (inCharList(Struct[i],Alphabet)==false){
                    open=false;

                    if(inStrList(tempVar,varStore,maxIndex+1)==0){

                        varStore[result]=tempVar;
                        result++;
                    }else if (i==Struct.length()-1){
                        varStore[result]=tempVar;
                        result++;
                    }

                    tempVar="";
                }else{
                    tempVar+=Struct[i];
                    
                }

            }else{

                if (inCharList(Struct[i],Alphabet)){
                    open=true;

                    tempVar+=Struct[i];
                    if (inStrList(tempVar,varStore,maxIndex+1)==0){
                        if (i==Struct.length()-1 & i==0){
                            varStore[result]=tempVar;
                            result++;

                        }else
                        if (i==Struct.length()-1){
                            varStore[result]=tempVar;
                            result++;

                        }
                    }
                }
            }
        }


    }
    

    return result;
}

str getBinStruct(int packSize,int maxSize){
    str result;
    str ts;
    str fs;

    for (int i=0;i!=packSize/2;i++){
        ts+='1';
        fs+='0';

    }
    while (true){
        result += ts+fs;
        if (result.length()==maxSize){
            break;
        }
    }
    return result;

}
void getVarVals(int varsCount){

    clearArray(varValStore,8);

    int staSize = pow(2,varsCount);

    str tempStr;
    int packSize;
    str Bin,Hex;
    //out("Statement size : ")OUT(staSize)
    //OUT("Enter Loop")
    //
    for (int i=0;i!=varsCount;i++){
        packSize=pow(2,i+1);
        Bin=getBinStruct(packSize,staSize);
        varValStore[i]=Bin;
        //Hex=binToHex4based(Bin);


        //out(i) space out(varStore[i]) space out(packSize) space
        //out(Hex) space
        //if (staSize<16) out(Bin)
        //enter

    }

    //OUT("Exit Loop")


}


bool validStruct(str Struct){

    int letCount=0;
    int schCount=0;
    int arCode=0;
    char None[] = "-";
    char othSome[] = "~#";
    char lp[] = "(";
    char rp[] = ")";
    char bp[] = "()";

    for (int i=0;i!=Struct.length();i++){

        if (inCharList(Struct[i],Alphabet)){
            letCount++;
        }else if (inCharList(Struct[i],OpAll)){
            schCount++;
        }


        if (inCharList(Struct[i],Alphabet)){
           if (ifAround(rp,i,lp,Struct)!=0){
               return false;

           }
        }else if (inCharList(Struct[i],OpSome)){
            if (ifAround(OpSome,i,OpSome,Struct)!=0){
                return false;

            }
            if (ifAround(lp,i,rp,Struct)!=0){
                return false;

            }


        }else if (inCharList(Struct[i],othSome)){
            if (ifAround(othSome,i,othSome,Struct)!=0){
                return false;

            }else if(Struct[i]=='#'){
                if (ifAround(None,i,hexCharList,Struct)==0){
                    return false;

                }
            }

        }else if (inCharList(Struct[i],")")){
            if (ifAround(None,i,lp,Struct)!=0){
                return false;
            }
            if (ifAround(othSome,i,None,Struct)!=0){
                return false;
            }

        }else if (inCharList(Struct[i],"(")){
            if (ifAround(rp,i,None,Struct)!=0){
                return false;
            }

        }else{


        }



    }

    return true;
}

void shrinkChar(char Char,str &String){
    str result;

    for (int i=0;i!=String.length();i++){
        if (String[i]!=Char){
            result+=String[i];
        }
    }

    String = result;
}

bool validCell(str cell){

    int OpSomeCount=0;

    for (int i=0;i!=cell.length();i++){
        if (inCharList(cell[i],OpSome)) OpSomeCount++;

    }

    if (OpSomeCount>1){
        return false;
    }



    return true;
}
enum Operations{
    AND,OR,THEN,XTHEN,EQUALS



};

char solveBit(char Bit0,char Bit1, int Operation){
    char Bit2;

    if (Operation==AND){
        if (Bit0=='1' & Bit1=='1'){
            Bit2='1';
        }else{
            Bit2='0';
        }

    }else if(Operation==OR){
        if (Bit0=='1' | Bit1=='1'){
            Bit2='1';
        }else{
            Bit2='0';
        }

    }else if(Operation==THEN){
        if (Bit0=='1' & Bit1=='0'){
            Bit2='0';
        }else{
            Bit2='1';
        }


    }else if(Operation==XTHEN){
        if ((Bit0=='1' & Bit1=='1') | (Bit0=='0' & Bit1=='0')){
            Bit2='1';
        }else{
            Bit2='0';
        }
    }else if(Operation==EQUALS){
        if( Bit0==Bit1){
            Bit2='1';
        }else{
            Bit2='0';
        }
    }

    return Bit2;
}

str solveOperation(str Bin0,str Bin1,int Operation){
    str Bin2;

    for (int i=0;i!=Bin0.length();i++){

        Bin2+=solveBit(Bin0[i],Bin1[i],Operation);

    }

    return Bin2;
}

int varsCount;

str varToBin(str Var){
    str result;

    for (int i=0;i!=varsCount;i++){
        if (Var==varStore[i]){
            result = varValStore[i];
        }

    }

    return result;
}



str hexToBin(str Hex){
    str result;


    str binList[16] = {
        "0000" , "0001" , "0010" , "0011",
        "0100" , "0101" , "0110" , "0111",
        "1000" , "1001" , "1010" , "1011",
        "1100" , "1101" , "1110" , "1111"
    };

    for (int i=0;i!=Hex.length();i++){
        int c;
        for (c=0;c!=16;c++){
            if (Hex[i]==hexCharList[c]) break;

        }

        result+=binList[c];

    }

    return result;
}

str solveCell(str cell){

    str result;

    bool openVar = false;
    bool openHex = false;

    str Bins[2];

    int binIndex=0;

    str var;
    str hex;
    int binCounter=0;
    char OperationChar;
    bool noPS=true;
    


    for (int i=0;i!=cell.length();i++){
        if (inCharList(cell[i],OpSome)==true){
            OperationChar=cell[i];
        
        }
        if (openHex==false){
            if (cell[i]=='#'){
                openHex=true;

            }

        }else{
            if(inCharList(cell[i],hexCharList)==true){
                hex+=cell[i];
                if (i==cell.length()-1){
                    Bins[binCounter] = hexToBin(hex);

                }

            }else if(inCharList(cell[i],hexCharList)==false){               
                Bins[binCounter] = hexToBin(hex);
                binCounter++;
                hex = "";
                openHex=false;
            }
        }


        if (openHex==false){
            if (openVar==true){

                if (inCharList(cell[i],Alphabet)==false){

                    Bins[binCounter]=varToBin(var);
                    binCounter++;
                    var="";
                    openVar=false;

                }else{
                    var+=cell[i];
                    if (i==cell.length()-1){
                        Bins[binCounter]=varToBin(var);
                        var="";
                    }
                }

            }else{

                if (inCharList(cell[i],Alphabet)==true){
                    openVar=true;
                    var+=cell[i];
                    if (i==cell.length()-1){
                        Bins[binCounter]=varToBin(var);
                        var="";
                    }                    

                }
                
            }

        }

    }
    int OperationInt;

    if (OperationChar=='>') OperationInt=THEN;
    if (OperationChar=='%') OperationInt=XTHEN;
    if (OperationChar=='&') OperationInt=AND;
    if (OperationChar=='|') OperationInt=OR;
    if (OperationChar=='=') OperationInt=EQUALS;

    result = solveOperation(Bins[0],Bins[1],OperationInt);
    


    return binToHex4based(result);
}
bool solveProblem(str problem){

    str cell;
    str hexCell;
    str hexCell0;
    char lp='(';
    char rp=')';

    bool opened = false;
    int cellRange[2] = {0,0};

    enter
    OUT("Cells:")
        
    bool ifPS = false;
    bool breaker = false;
    bool isOver = false;
    while (true){
        for (int i=0;i!=problem.length();i++){

            if (opened){
                if (problem[i]==lp){
                    cellRange[0]=i;

                }else if(problem[i]==rp){

                    cellRange[1]=i;

                    for (int c=cellRange[0]+1;c!=cellRange[1];c++){
                        cell+=problem[c];
                    }

                    enter
                    indent out(problem) space out(" : ") enter
                    indent indent out(cell) space out(" : ") enter
                    indent indent indent 
                    

                    if (validCell(cell)){
                        hexCell0 = solveCell(cell);
                        hexCell = "#" + hexCell0;
                        
                    
                        int k = 0;
                        for (int j=cellRange[0];j!=cellRange[1]+1;j++){
                            if (k<hexCell.length()){
                                problem[j] = hexCell[k];  

                            }else{
                                problem[j] = ' ';
                            
                            }

                            k++;
                        }

                        shrinkChar(' ',problem);
                        out(hexCell) space out(hexToBin(hexCell0))
                        enter  

                        cell="";
                        break;
                        
                    }
                    else{
                        OUT("Invalid cell structer")
                        breaker = true;
                        break;
                    }
                    enter
                    space enter

                    cell="";
                    opened = false;

                }

            }else{
                if (problem[i]==lp){
                    cellRange[0]=i;
                    opened = true;

                }else if(problem[i]==rp){


                }


            }


        }

        if (breaker){
            break;
        }
        ifPS=false;

        for (int i=0;i!=problem.length();i++){
            if (inCharList(problem[i],PS)){ 
                ifPS = true;
                
            }

        }
        
        if (ifPS==false){
            enter 
            if (validCell(problem)){
                isOver=true;
                for (int i=0; i!=problem.length();i++){
                    if (inCharList(problem[i],OpSome)) isOver=false;

                }
                if (!isOver){
                    hexCell0 = solveCell(problem);
                    hexCell = "#" + hexCell0;
                    indent out(problem) space out(" : ") enter indent indent
                    out(hexCell) space 
                    
                    out(hexToBin(hexCell0))
                }

            }else{
                indent out("Invalid Cell") space OUT(problem)

            }
        

            


            break;
        }
    }

    return true;
}

int main(){
    enter enter enter enter enter enter enter
    str command;
    str messages[] = {"Enter command : ",
                        "Enter Bin Number : "};
    int messageIndex = 0;
    bool ifBin;
    str hex;

    str finalResult;

    

    while (true){

        enter
        command = input("Input a Discrete Mathemathics problem: ");
        shrinkChar(' ',command);
        enter enter enter

        if (command=="q"){
            break;
        }

        if (validPDec(command)){
            //out(command) space out("Parenthesis Declaration is valid.") enter


            //out(command) space out("Has a")
            if (validStruct(command)){
                //out(" valid structer.")
                enter
                out("This statement contain's ")
                varsCount=getVars(command);
                out(varsCount);

                out(" variables.")


                getVarVals(varsCount);
                enter enter
                OUT("Variables:")
                for (int i=0;i!=varsCount;i++){

                    indent out(varStore[i]) space
                    if (varsCount<4){
                        out(varValStore[i]) space
                    }

                    out(binToHex4based(varValStore[i])) enter

                }

                solveProblem(command);

            }else{
                out("This problem has an invalid structer.")

            }

            enter



        }else{
            out(command) space out("Parenthesis Declaration is not valid.") enter

        }


    }

    return 0;
}