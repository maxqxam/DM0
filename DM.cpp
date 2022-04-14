#include <iostream>
#include <string>

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

bool inCharList(char Char,const char List[],int ListSize){

    for (int i=0;i!=ListSize-1
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
            if (inCharList(Struct[currentIndex+1],after,
                            sizeof(after)/sizeof(after[0]))){
                
                return 2;
            }
        }else if(currentIndex==Struct.length()-1){
            if (inCharList(Struct[currentIndex-1],before,
                            sizeof(before)/sizeof(before[0]))){
                return 1;
            }

        }else{
            int ifBoth=0;
            if (inCharList(Struct[currentIndex+1],after,
                            sizeof(after)/sizeof(after[0]))){
                
                ifBoth += 2;                
            }
            if (inCharList(Struct[currentIndex-1],before,
                            sizeof(before)/sizeof(before[0]))){
                ifBoth += 1;            
            }
            return ifBoth;
        }                  
}


bool validStruct(str Struct){

    int letCount=0;
    int schCount=0;
    
    for (int i=0;i!=Struct.length();i++){

        if (inCharList(Struct[i],Alphabet,sizeof(Alphabet)/sizeof(Alphabet[0]))){
            letCount++;
        }else if (inCharList(Struct[i],OpAll,sizeof(OpAll)/sizeof(OpAll[0]))){
            schCount++;
        }
        




        if (ifAround(OpSome,i,OpSome,Struct)!=0 & inCharList(Struct[i],OpSome,
            sizeof(OpSome)/sizeof(OpSome[0]))){
            return false;
        }

        if (ifAround("(",i," ",Struct)!=0 & inCharList(Struct[i],OpSome,
            sizeof(OpSome)/sizeof(OpSome[0]))){
            enter
            out(i) space out(Struct) out(ifAround("(",i,")",Struct))
            enter
            return false;
        }

        if (ifAround("~",i,"~",Struct)!=0 & inCharList(Struct[i],"~",
        sizeof("~")/sizeof('~'))){
            return false;
        }

        if (ifAround("~",i,"-",Struct)==1 & inCharList(Struct[i],OpSome,
            sizeof(OpSome)/sizeof(OpSome[0]))){
            return false;
        }
        
    }

    Alphabet;
    
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
    
    str command;
    str messages[] = {"Enter command : ",
                        "Enter Bin Number : "};
    int messageIndex = 0;
    bool ifBin;
    str hex;


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
                out(" valid structer")

            }else{
                out("n invalid sructer")

            }

            enter

            

        }else{
            out(command) space out("Parenthesis Declaration is not valid.") enter

        }


    }

    return 0;
}