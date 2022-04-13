#include <iostream>
#include <string>

#define str std::string
#define OUT(x) std::cout<<x<<'\n';
#define out(x) std::cout<<x;
#define space std::cout<<" ";
#define enter std::cout<<"\n";


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
        OUT("1- ')' is at the begining of the expression.")
        result = false;
    }
    if (rlc%2!=0){
        OUT("2- The total number of Parenthesis is an odd number.")
        result = false;
    }
    if (rls[rlc-1]==l){
        OUT("3- '(' is at the ending of the expression.")
        result = false;
    }
    if (rc!=lc){
        OUT("4- The number of left and right parenthesis is not equal.)")
        result = false;
    }

    if (result & rls.length()!=0){
        str tempStr=rls;
        str tempTempStr="";
        
        enter
        out(tempStr) enter
        OUT("Enter Checkpoint")
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
                    break;
                }
            }

            OUT(tempStr);
            if (tempStr.length()<3){
                break;
            }
        }
        OUT("Exist Checkpoint")
        OUT(tempStr); 
        enter  


        if (tempStr[0]==r & tempStr[1]==l)
            return false;
    
    }
    


    return true;
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
        enter enter enter enter enter enter enter enter enter enter

        if (command=="q"){
            break;
        }

        if (validPDec(command)){
            out(command) space out("Declaration is valid.") enter

        }else{
            out(command) space out("Declaration is not valid.") enter

        }


    }

    return 0;
}