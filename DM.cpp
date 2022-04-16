#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

#define str std::string
#define OUT(x) std::cout<<x<<'\n';
#define out(x) std::cout<<x;
#define space std::cout<<" ";
#define enter std::cout<<"\n";




//char And,Or,XAnd,Then, Not, Hashtag;
char OpAll[]="&|%>~#=";
char OpSome[]="&|%>=";

char Alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
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


str varStore[8];
str varValStore[8];
int getVars(str Struct){
    int maxIndex=7;
    int result=0;
    ;
    clearArray(varStore,8);
    str tempVar="";
    bool open=false;

    for (int i=0;i!=Struct.length();i++){
        
        if (open){
            if (inCharList(Struct[i],Alphabet)==false){
                open=false;
                
                if(inStrList(tempVar,varStore,maxIndex+1)==0){

                    varStore[result]=tempVar;           
                    result++;
                }
                
                tempVar="";
            }else{
                tempVar+=Struct[i];
                if (i==Struct.length()-1){
                    varStore[result]=tempVar;
                    result++;
                }
            }
            
        }else{
            
            if (inCharList(Struct[i],Alphabet)){
                open=true;
                
                tempVar+=Struct[i];

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

    //enter 
    //for (int i=0;i!=8;i++){
    //    out(i) space OUT(varStore[i])   
    //}
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
                if (ifAround(None,i,Alphabet,Struct)==0){
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


int main(){
    enter enter enter enter enter enter enter
    str command;
    str messages[] = {"Enter command : ",
                        "Enter Bin Number : "};
    int messageIndex = 0;
    bool ifBin;
    str hex;

    str X = "(p>q)%((p|r)|(q&r))=r";

    //str varStore[8];


    while (true){

        enter
        command = input("Input a parenthesis declaration : ");
        shrinkChar(' ',command);
        enter enter enter

        if (command=="q"){
            break;
        }

        if (validPDec(command)){
            out(command) space out("Parenthesis Declaration is valid.") enter


            out(command) space out("Has a")
            if (validStruct(command)){
                out(" valid structer.")
                enter
                out("This statement contain's ")
                int varsCount=getVars(command);
                out(varsCount);
                out(" variables.")
                enter

                getVarVals(varsCount);

                for (int i=0;i!=varsCount;i++){
                    out(varStore[i]) space
                    out(binToHex4based(varValStore[i])) enter

                }



            }else{
                out("n invalid sructer.")

            }

            enter



        }else{
            out(command) space out("Parenthesis Declaration is not valid.") enter

        }


    }

    return 0;
}