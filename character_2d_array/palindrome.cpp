

int length(char str[]){
    
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}



bool checkPalindrome(char str[]){
    int len = length(str);
    int i=0;
    int j = len - 1;

    while(i<j){
        if(str[i] != str[j]){
            return false;
        }else{
            i++;
            j--;
        }
    }
    return true;
}