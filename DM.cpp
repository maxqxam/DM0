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

int main(){
    
    str command;
    str messages[] = {"Enter command : ",
                        "Enter Bin Number : "};
    int messageIndex = 0;
    bool ifBin;
    str hex;


    while (true){
        command = input(messages[messageIndex]);    
        if (messageIndex==0){
            if (command=="s"){
                messageIndex=1;
            }else if(command=="q"){
                break;
            }
        }else{
            if (command=="b"){
                messageIndex=0;
            }else if(command=="q"){
                break;
            }else{
                ifBin=isBin(command);
                if (ifBin)
                    std::cout<<command<<" is a binary number \n";                
                if (ifBin & command.length()%4!=0){
                    out(command)
                    OUT(" Is not devidable by 4 therefore it's not valid")
                }else{           
                    hex = binToHex4based(command);
                    out("The hex value of ")out(command) space
                    out("is") space OUT(hex)
                }
            };
        }
    }


    

    return 0;
}